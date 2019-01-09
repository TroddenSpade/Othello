#include <stdio.h>
#include <stdlib.h>

#define row 8
#define column 8
#define black 1
#define white 2

void defineTable(int table[row][column],char *argv[]);
void printTable(int table[row][column]);

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

void validSquares(const int table[row][column],int player);

/////////////////


int main(int argc,char *argv[])
{
    int table[row][column]={
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,1 ,2 ,0 ,0 ,0},
        {0 ,0 ,0 ,2 ,1 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
    };

    // int const Player= argv[9][0]-48;

    // defineTable(table,argv);

    validSquares(table,1);
    printTable(table);
    
    
    // int counter;
    // printf("Program Name Is: %s",argv[0]);
    // if(argc==1)
    //     printf("\nNo Extra Command Line Argument passed Other Than program Name");
    // if(argc>=2)
    // {
    //     printf("\nNumber Of Arguments passed: %d\n",argc);
    //     printf("\n----Following Are The Command Line Arguments Passed----");
    //     for(counter=0;counter<argc;counter++)
    //         printf("\nargv[%d]:%s",counter,argv[counter]);
    // }

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
    puts("");
    for(int i=0;i<row;i++){
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

void validSquares(const int table[row][column],int player){

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
                    if(table[j][i]>0){
                        continue;
                    }
                    else if(validSE(j,i,j,i,table,player) != -1){
                        printf("%d\n",validSE(j,i,j,i,table,player));
                        
                    }else if(validSW(j,i,j,i,table,player) != -1){
                        printf("%d\n",validSW(j,i,j,i,table,player));

                    }else if(validSouth(j,i,j,i,table,player) != -1){
                        printf("%d\n",validSouth(j,i,j,i,table,player));

                    }else if(validNE(j,i,j,i,table,player) != -1){
                        printf("%d\n",validNE(j,i,j,i,table,player));

                    }else if(validNW(j,i,j,i,table,player) != -1){
                        printf("%d\n",validNW(j,i,j,i,table,player));

                    }else if(validNorth(j,i,j,i,table,player) != -1){
                        printf("%d\n",validNorth(j,i,j,i,table,player));

                    }else if(validEast(j,i,j,i,table,player) != -1){
                        printf("%d\n",validEast(j,i,j,i,table,player));

                    }else if(validWest(j,i,j,i,table,player) != -1){
                        printf("%d\n",validWest(j,i,j,i,table,player));

                    }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////