#include <stdio.h>
#include <time.h>
#include <string.h>

struct SWBlock {
	char blocInfo[4][100];
	int resCount;
	time_t startTime;
	char res[100];	
};

struct SWBlock blocks[10];

int main()
{
	FILE *fp ;

        int i=0;
	int j=0;
	char bloc[100];
	char par[100];
	
        fp = fopen("text.txt", "r");

	while(fgets(bloc, 100, fp))
	{		
		char *ptr = strtok(bloc, " ;");
	
		while(ptr != NULL)
		{
			printf("%s\n", ptr);
			ptr = strtok(NULL, " ;");
			strcpy(blocks[i].blocInfo[j], ptr); 	
			j++;
		}
		i++;
	}
        fclose(fp);
	return 0;
}
