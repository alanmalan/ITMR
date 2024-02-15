#include <stdio.h>

void egg(char* somethingrelevant){
	fgets(somethingrelevant, 280, stdin);  //the only fucking way it would work
}

int main(int argc, char** argv) {
	//FILE * file;
	//file = fopen (argv[1], "r");
	int i = 0;
	int debug = 0;
	int inpt = 0;
	const int tapemaxl = 250; 
	const int codemaxl = 280;
	int tape[255] = {0}; 
	char code[280] = {0};
	int codepointer = 0;
	int pointer = 0;
	int savd = 1;
	srand(time(NULL));
	egg(code); 
	//fread (code, 1, 280, file);
	while(1){
		switch(code[codepointer]){
			case '>':
				pointer++;
				if (pointer > tapemaxl){
					pointer = 0;
				}
				break;
			case  '<':
				if(pointer == 0){
					pointer = tapemaxl;
				}
				else{
					pointer--;
				}
				break;
			case '+':
				if (tape[pointer] == 255){
				tape[pointer] = 0;
				} else {
					tape[pointer]++;
				}
				break;
			case '-':
				if (tape[pointer] == 0){
				tape[pointer] = 255;
				} else {
					tape[pointer]--;
				}
				break;
			case '.':
				printf("%d", tape[pointer]);
				break;	
			case ':':
				printf("%c", tape[pointer]);
				break;	
			case ',':
				inpt=getchar();
				tape[pointer] = (int)inpt;
			case '[':
				savd = codepointer; //:troll:
				break;
			case ']':
				if (tape[pointer] != 0){  
					codepointer = savd;
				}
				break;
			case '&':
				if (pointer > tapemaxl){
					codepointer = 1;
				}
				else if (tape[pointer] != 0){	
					codepointer = codepointer + 2;
				}
				break;
			case '%':
				tape[pointer] = rand() % 256 ;
				break;
			case '$':
				if(tape[pointer] < codemaxl){
					codepointer = tape[pointer];
				}
				break;
		}
		if (codepointer == codemaxl){
			goto end;
		} else {
			codepointer++;
		}
	}
	end:
	pointer = 0;
	while (1){
		if (i > 250){
			printf("\n");
			break;
		} 
		printf("[%d]", tape[pointer]); //QOL feature
		pointer++;
		i++;
	}
	//fclose(file);
	getchar();
	return 0;
}
