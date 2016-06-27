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

void changename(char *p)
{
	int i,j;
	j=0;
	char tail1[100];
	strlen(p);
	//printf("P is %d\n",strlen(p));	
	for (i=strlen(p)-12;i<strlen(p)-4 ; i++)
	{
		tail1[j]=p[i];
		j++;		
	}
	p[i-8]='\0';
	tail1[j]='\0';
	//printf("p1 is %s\n",p);
	//printf("tail1 is %s\n",tail1);
	strcat(tail1,p);
	strcpy(p,tail1);
	strcat(p,".pdf");
	//printf("p1 is %s\n",p);
}

void SearchFile(char *dir)
{       
    // Define structure
    struct _finddata_t   ffblk; 
	// Define arrays
    char path[256],path1[256],path2[256],path3[256],name1[256];
    char ch;   
    sprintf(path,"%s\\*.pdf*",dir); 
    sprintf(path1,"%s\\",dir);  
    long done = _findfirst(path,&ffblk);   
    //printf("done is %d\n",done);
    int find=0;  
    //printf("%s\n",path);
    while (find==0)     
    {     
        // Compare strings
		if(strcmp(ffblk.name,".pdf"))
        {   
            //printf(" strcmp is %d. \n ffblk.name is %s\n",strcmp(ffblk.name,".pdf"),ffblk.name);
			// Copy "path1"  to "path2"
			strcpy(path2,path1);
			//printf("path2 is %s\n",path2);
			// Copy "ffblk.name" string to the end of "path2"
            strcat(path2,ffblk.name);
           // system(path2);
            // printf("Rename Files: %s\n Press 'Y' or 'N'\n",path2);
            // scanf("%c",&ch);
            // if(ch=='Y' || ch=='y')
            // {
                strcpy(path3,path1);
				strcpy(name1,ffblk.name);
				changename(name1);
				strcat(path3,name1);
				// path2 is the oldname, path is the newname
				if   (rename(path2,path3)   ==   0) 
                   printf( "Have renamed:   %s\n ",path3); 
                else
					// Print the last system error messages
                   perror( "Rename Error!!!"); 
            //}
			// Reads characters from the console and immediately echo
            //getchar();
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
