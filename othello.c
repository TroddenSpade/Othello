#include <stdio.h>
#define row 8
#define column 8

void defineTable(int table[row][column],char *argv[]);

int main(int argc,char *argv[])
{
    int table[row][column];

    defineTable(int table[row][column],char *argv[]);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%d",table[i][j]);
        }
        puts("");
    }

    
    // int counter;
    // printf("Program Name Is: %s",argv[0]);
    // if(argc==1)
    //     printf("\nNo Extra Command Line Argument passed Other Than program Name");
    // if(argc>=2)
    // {
    //     printf("\nNumber Of Arguments passed: %d",argc);
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
            table[i][j]= argv[i-1][j] - 30 ;
        }
    }

}

