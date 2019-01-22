#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define row 8
#define column 8
#define black 1
#define white 2

int const Position[row*column]={
    99 ,-8 ,8  ,6  ,6  ,8  ,-8 ,99 ,

    -8 ,-24,-4 ,-3 ,-3 ,-4 ,-24,-8 ,

    8  ,-4 ,7  ,4  ,4  ,7  ,-4 ,8  ,

    6  ,-3 ,4  ,0  ,0  ,4  ,-3 ,6  ,

    6  ,-3 ,4  ,0  ,0  ,4  ,-3 ,6  ,

    8  ,-4 ,7  ,4  ,4  ,7  ,-4 ,8  ,

    -8 ,-24,-4 ,-3 ,-3 ,-4 ,-24,-8 ,

    99 ,-8 ,8  ,6  ,6  ,8  ,-8 ,99
};

void defineTable(int table[row][column],char *argv[]);
void printTable(int table[row][column]);

//////////////////////// Strategies ////////////////////////////////////
int random(const int table[row][column],int player,int listOfValidSquares[]);
int positional(const int table[row][column],int player,int listOfValidSquares[]);

//////////////////////// Valid Moves ///////////////////////////////////
int isInTable(int x ,int y);
int validNorth(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validSouth(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validWest(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validEast(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validNW(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validNE(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validSW(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validSE(int x0,int y0 ,int x ,int y, const int table[row][column],int player);
int validSquares(const int table[row][column],int player,int listOfValidSquares[]);

////////////////////////////////////////////////////////////////////////
int flipNorth(int x ,int y, int table[row][column],int player);
int flipSouth(int x ,int y, int table[row][column],int player);
int flipWest(int x ,int y, int table[row][column],int player);
int flipEast(int x ,int y, int table[row][column],int player);
int flipNE(int x ,int y, int table[row][column],int player);
int flipNW(int x ,int y, int table[row][column],int player);
int flipSE(int x ,int y, int table[row][column],int player);
int flipSW(int x ,int y, int table[row][column],int player);
void doFlip(int x ,int y, int table[row][column],int player);


int main(int argc,char *argv[])
{
    // int table[row][column];
    int table[row][column]={
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,1 ,2 ,0 ,0 ,0},

        {0 ,0 ,0 ,1 ,2 ,0 ,0 ,0},

        {0 ,0 ,0 ,1 ,2 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},

        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
    };

    int listOfValidSquares[64];

    // int const Player= argv[9][0]-48;

    // defineTable(table,argv);

    // int num = random(table,Player,listOfValidSquares);
    // int num = positional(table,Player,listOfValidSquares);
    doFlip(5,2,table,1);
    printTable(table);
    // printf("%d %d",num%8,num/8);
    // printf("%d",validWest(5,2,5,2,table,1));

    return 0;
}

void defineTable(int table[row][column],char *argv[])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            table[i][j]= argv[i+1][j] - 48 ;
        }
    }

}

void printTable(int table[row][column]){
    printf("%s","   ");
    for(int i=0;i<column;i++)   printf("%d ",i);
    puts("");
    for(int i=0;i<row;i++){
        printf("%d :",i);
        for(int j=0;j<column;j++){
            printf("%d ",table[i][j]);
        }
        puts("");
    }

}



///////////////////////////////////////////////////////////////////////////
/////////////////////// Valid Moves Function //////////////////////////////

int isInTable(int x,int y){
    if(x < 8 && x>=0 && y<8 && y>=0)    return 1;
    else    return 0;
}

int validNorth(int x0,int y0 ,int x ,int y, const int table[row][column],int player){    ////
    y-=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validNorth(x0,y0,x,y,table,player);
}

int validSouth(int x0,int y0 ,int x ,int y, const int table[row][column],int player){    ////
    y+=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validSouth(x0,y0,x,y,table,player);
}

int validWest(int x0,int y0 ,int x ,int y, const int table[row][column],int player){     ////
    x-=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validWest(x0,y0,x,y,table,player);
}

int validEast(int x0,int y0 ,int x ,int y, const int table[row][column],int player){     ////
    x+=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validEast(x0,y0,x,y,table,player);
}

int validNW(int x0,int y0 ,int x ,int y, const int table[row][column],int player){       ////
    y-=1;   x-=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validNW(x0,y0,x,y,table,player);
}

int validNE(int x0,int y0 ,int x ,int y, const int table[row][column],int player){
    y-=1;   x+=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validNE(x0,y0,x,y,table,player);
}

int validSW(int x0,int y0 ,int x ,int y, const int table[row][column],int player){
    y+=1;   x-=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validSW(x0,y0,x,y,table,player);
}

int validSE(int x0,int y0 ,int x ,int y, const int table[row][column],int player){
    y+=1;   x+=1;
    if(!isInTable(x,y))  return -1;

    if(table[y][x]== 0) return -1;
    else if(table[y][x]== player){
        if (abs(x-x0)==1 || abs(y-y0)==1 )    return -1;
        else    return x0+y0*8;
    }
    else    return  validSE(x0,y0,x,y,table,player);
}

int validSquares(const int table[row][column],int player,int listOfValidSquares[]){
    int k =0;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(table[i][j]>0){
                continue;
            }
            else if(validSE(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validSE(j,i,j,i,table,player);
                k++;

            }else if(validSW(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validSW(j,i,j,i,table,player);
                k++;

            }else if(validSouth(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validSouth(j,i,j,i,table,player);
                k++;

            }else if(validNE(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validNE(j,i,j,i,table,player);
                k++;

            }else if(validNW(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validNW(j,i,j,i,table,player);
                k++;

            }else if(validNorth(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validNorth(j,i,j,i,table,player);
                k++;

            }else if(validEast(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validEast(j,i,j,i,table,player);
                k++;

            }else if(validWest(j,i,j,i,table,player) != -1){
                listOfValidSquares[k]=validWest(j,i,j,i,table,player);
                k++;

            }
        }
    }

    return k;
}

///////////////////////////////   Flip    //////////////////////////////////////

int flipNorth(int x ,int y, int table[row][column],int player){    ////
    if (validNorth(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] =player;
    y-=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        y-=1;
    }
}

int flipSouth(int x ,int y, int table[row][column],int player){    ////
    if (validSouth(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] =player;
    y+=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        y+=1;
    }
}

int flipWest(int x ,int y, int table[row][column],int player){     ////
    if (validWest(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] = player;
    x-=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        x-=1;
    }
}

int flipEast(int x ,int y, int table[row][column],int player){     ////
    if (validEast(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] = player;
    x+=1;
    while(table[y][x] == 3 - player){
        table[y][x]=player;
        x+=1;
    }
}

int flipNW(int x ,int y, int table[row][column],int player){       ////
    if (validNW(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] = player;
    y-=1;   x-=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        y-=1;   x-=1;
    }
}

int flipNE(int x ,int y, int table[row][column],int player){
    if (validNE(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] = player;
    y-=1;   x+=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        y-=1;   x+=1;
    }
}

int flipSW(int x ,int y, int table[row][column],int player){
    if (validSW(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] = player;
    y+=1;   x-=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        y+=1;   x-=1;
    }
}

int flipSE(int x ,int y, int table[row][column],int player){
    if (validSE(x,y,x,y,table,player)== -1)  return 0;
    table[y][x] = player;
    y+=1;   x+=1;
    while(table[y][x] == 3 - player){
        table[y][x]= player;
        y+=1;   x+=1;
    }
}

void doFlip(int x ,int y, int table[row][column],int player){
    flipNorth(x ,y,table,player);
    flipSouth(x ,y,table,player);
    flipEast(x ,y,table,player);
    flipWest(x ,y,table,player);
    flipNE(x ,y,table,player);
    flipNW(x ,y,table,player);
    flipSE(x ,y,table,player);
    flipSW(x ,y,table,player);
}

///////////////////////////// Strategies ///////////////////////////////////////

int random(const int table[row][column],int player,int listOfValidSquares[]){
    int size = validSquares(table , player ,listOfValidSquares);
    if(size ==0)    return -1;
    srand(time(NULL));
    return listOfValidSquares[rand()%size];
}

int positional(const int table[row][column],int player,int listOfValidSquares[]){
    int size = validSquares(table , player ,listOfValidSquares);
    if(size ==0)    return -1;

    int bestPos = Position[listOfValidSquares[0]];
    int bestSqr = 0;
    for(int i=1;i<size;i++){
        if(bestPos < Position[listOfValidSquares[i]]){
            bestPos = Position[listOfValidSquares[i]];
            bestSqr = i;
        }
    }
    return listOfValidSquares[bestSqr] ;
}

int evalBoard(const int table[row][column],int player,int listOfValidSquares[]){


}

int copyBoard(const int table[row][column],int board[row][column]){
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            board[i][j]=table[i][j];
        }
    }
}