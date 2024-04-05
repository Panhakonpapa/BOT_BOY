#include <stdio.h>
#include <stdlib.h>
#include <toml.h>
#include <string.h>
typedef struct {
	const char* SoureFiles1;
	const char* SoureFiles2;
	const char* SoureFiles3;
	const char* SoureFiles4;
	const char* SoureFiles5;	
	const char* SoureFiles6;	
	const char* SoureFiles7;	
} Token;

void Write_the_info(const char* source_files[], int file_arry_t) {
	printf("Nova will Build the files: \n"); 	
	for (int i = 0; i < file_arry_t; i++) {
		printf("- %s \n", source_files[i]); 	
	}	
}
void NovaBuild_up(Token* Nova) {
	char compiler[4024];
	snprintf(compiler, sizeof(compiler), "gcc main.c -o nova -lSDL2 -lSDL2_ttf -lm -Wall -Wextra ");

	const char* source_files[] = {
		Nova->SoureFiles1,
		Nova->SoureFiles2, 	
		Nova->SoureFiles3, 								  Nova->SoureFiles4,
		Nova->SoureFiles5, 
		Nova->SoureFiles6, 
		Nova->SoureFiles7, 		
	}; 	
	int file_arry_t = sizeof(source_files) / sizeof(source_files[0]);
	
	for (int i = 0; i < file_arry_t; i++) {
		snprintf(compiler + strlen(compiler), sizeof(compiler) - strlen(compiler)," %s ", source_files[i]); 	
	}
	printf("%s\n", compiler);
	
	Write_the_info(source_files, file_arry_t);
	int final_exe = system(compiler); 	
	if (final_exe == 0) {
		printf("NovaBuild compilation sucessful\n");
	}
	else {
		printf("NovaBuild compilation failure\n");
	}
}

void Run_Nova() {
	const char* exefile = "./nova";
	int file_exe = system(exefile);		
	if (file_exe == 0) {
		printf("Build sucessful\n"); 	
	}
	else {	
		printf("Build failure\n"); 	
	}
}
int main() {
	printf("Welcome to Nova\n");
	Token Nova; 	
	
	FILE* FileOpen;
	char errbuf[256];
	//* Read the data form the toml file  //	
	FileOpen = fopen("Nova.toml", "r");
	if (FileOpen == NULL) {
		perror("Falure to open file lol\n");		
		return -1;	
	}
	//* Pasese the data form the toml file //	
	toml_table_t* config = toml_parse_file(FileOpen, errbuf, sizeof(errbuf));	
	fclose(FileOpen);
	if (config == NULL) {
		printf("%s\n", errbuf);	
		return -1;
	}	
	//* Toml Infomation about the build projcet //	
	const char* name = toml_raw_in(config, "name");
	const char* version = toml_raw_in(config, "version");	
	const char* author = toml_raw_in(config, "author");	
	
	printf("Projcet Infomation: \n");
	printf("Name: - %s\n", name);
	printf("Version: - %s\n", version);
	printf("author %s \n", author);
	
	//* Paser Nova Build file config into Token // 	
	Nova.SoureFiles1 = toml_raw_in(config, "file1"); 			
	Nova.SoureFiles2 = toml_raw_in(config, "file2");
	Nova.SoureFiles3 = toml_raw_in(config, "file3");	
	Nova.SoureFiles4 = toml_raw_in(config, "file4"); 			
	Nova.SoureFiles5 = toml_raw_in(config, "file5");
	Nova.SoureFiles6 = toml_raw_in(config, "file6"); 			
	Nova.SoureFiles7 = toml_raw_in(config, "file7"); 		
	if (!Nova.SoureFiles1 && !Nova.SoureFiles2 && !Nova.SoureFiles3) {
		printf("Error File %s", Nova.SoureFiles1);
		return -1;
	}		
	if (!Nova.SoureFiles4 && !Nova.SoureFiles5 && !Nova.SoureFiles6) {
		printf("Error File %s", Nova.SoureFiles1);
		return -1;
	}	
	//* Run build exe for Nova
	NovaBuild_up(&Nova);
	Run_Nova();

	toml_free(config);
	return 0;
}
