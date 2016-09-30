/*
 ============================================================================
 Name        : Assignment_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE* fp;
	char* filename;
	char string[50];
	int i=0;
	for(i=0; i<argc; i++)
	{
		if(i<argc && argv[i][0]=='-' && argv[i][1]=='f')
		{
			i++;
			filename=malloc(sizeof(argv[i])+4);
			sprintf(filename, "%s.txt", argv[i]);
		}
		else if(i<argc && argv[i][0]=='-' && argv[i][1]=='w')
		{
			//i++; //increments array
			if(i++>=argc)
			{
				printf("Wrong formating\n");
				return 0;
			}

			fp = fopen(filename, "w");//opens the given input file for reading

			if (fp == NULL) //making sure the input file exists
			{
				freopen(filename, "w", fp);
			}

			while(i<argc)
			{
				fprintf(fp, "%s ", argv[i]); //writes to file
				i++;
			}
			free(filename);
			fclose(fp);
		}
		else if(i<argc && argv[i][0]=='-' && argv[i][1]=='r')
		{
			i++; //increments array
			fp = fopen(filename, "r");//opens the given input file for reading
			if (fp == NULL) //making sure the input file exists
			{
				printf("File does not exist\n");
				return 0;
			}
			if( fgets (string, 50, fp)!=NULL )
			   {
			      /* writing content to stdout */
			      printf("%s\n", string);
			   }

			free(filename);
			fclose(fp);
		}
	}
	return 0;
}
