#include <stdio.h>

#include <string.h>
int main() {
	FILE *fp ;

        int i;
	char bloc[100];
	char par[100];


	
        fp = fopen("text.txt", "r");

	while(fgets(bloc, 100, fp)) {	
		


	
	char *ptr = strtok(bloc, " ;");
	
	while(ptr != NULL) {
	printf("%s\n", ptr);
	ptr = strtok(NULL, " ;");
}

}

        fclose(fp);

	return 0;
}
