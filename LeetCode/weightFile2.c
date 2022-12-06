#include <stdio.h>         
#include <stdlib.h>  
#include <string.h>


int main(int argc, char* argv[])
{
    FILE *inFile = NULL;
    char *fileName = argv[1];
    inFile=fopen(fileName,"r");
    int outCount = 1;

    int checkCount = atoi(argv[2]);
    int avg = 0;

    int max = -1;

    int wordCount = 0;
    int true = 1;
    char arr[100][100] = {0};
    int arrCount = 0;
    while(wordCount<checkCount)
    {
        if(feof(inFile)){break;}
        char c[100];
        int count=0;
        if(fscanf(inFile,"%s",&c)==1)
        {
            for(int i=0;i<strlen(c);i++)
            {
                count = count +c[i];
            }
            if(count>=max){
                if(count==max)
                {
                    max=count;
                    strcpy(arr[arrCount],c);
                    arrCount++;
                }else{
                    max = count;
                    arrCount=0;
                    strcpy(arr[arrCount],c);
                    arrCount++;
                }
            }
            avg=avg+count;
            wordCount++;
        }
        //printf("%d: \"%s\" has weight: %d\n", outCount,c,count);
        //outCount++;
    }
    double average = (double) avg/checkCount;
    printf("Average: %.1f\n",average);
    printf("Maximum word weight: %d\n",max);
    printf("Words with weight %d: \n",max);
    for(int s=0;s<=arrCount;s++)
    {
        printf("%s\n",arr[s]);
    }
    

    /*int count = argc;
    for(int i=1;i<count;i++)
    {
        char *c = argv[i];
        int ascii = 0;
        
        for(int k=0;k<strlen(c);k++)
        {
           // printf("%c\n",c[k]);
           ascii = ascii+c[k];
        }
        printf("\"%s\" has weight: %d\n",c,ascii);
    }*/
}