#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<io.h> 
#include <process.h>
#include <memory.h>
#include <stdio.h>     
#include <unistd.h> 
#include <direct.h>

//void SearchFile(char *);   



void SearchFile(char *dir)
{       
    // Define structure
    struct _finddata_t   ffblk; 
	// Define arrays
    char path[256],path1[256],path2[256];
    char ch;   
    sprintf(path,"%s\\*.pdf*",dir); 
    sprintf(path1,"%s\\",dir);  
    long done = _findfirst(path,&ffblk);   
    printf("done is %d\n",done);
    int find=0;  
    printf("%s\n",path);
    while (find==0)     
    {     
        if(strcmp(ffblk.name,".pdf"))
        {   
            printf("strcmp is %d\n",strcmp(ffblk.name,".pdf"));
			strcpy(path2,path1);
            strcat(path2,ffblk.name);
           // system(path2);
            printf("Delete Files: %s\n Press 'Y' or 'N'\n",path2);
            scanf("%c",&ch);
            if(ch=='Y' || ch=='y')
            {
                if   (remove(path2)   ==   0) 
                   printf( "Have Removed:   %s.\n ",path2); 
                else 
                   perror( "remove "); 
            }
            getchar();
        }
        find=_findnext(done,&ffblk);
    }
    _findclose(done); 
    
}

int main()   
{    
    char buf[80]; 
	// Get current working directory
    getcwd(buf,sizeof(buf));   
    printf("current working directory: %s\n", buf); 
	SearchFile(buf);
    printf("\n");
	// Pause operation
    system("pause");   
    return 0;   
}
