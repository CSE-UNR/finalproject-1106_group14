//Authors: Faith Nelson and Tevon Westby
//Date: 5/7/24
//Purpose: Simple photo editor

#include <stdio.h>
		#define ROW_S 300
		#define COL_S 300

void brightenPhoto(int *Rows, int *Col,char ReadArr[][COL_S]);
void processPhoto(int *Rows, int *Col, char ReadArr[][COL_S], char Arr[][COL_S]);
void cropPhoto(int *Rows, int *Col,char ReadArr[][COL_S]);
void displayPhoto(int *Rows, int *Col, char ArrayPhoto[][COL_S]);
void dimPhoto(int *Rows, int *Col, char ReadArr[][COL_S]);
void savePhoto(int *Rows, int *Col, char ReadArr[][COL_S]);
void loadPhoto(int *ReadR, int *ReadC, char ArrayPhoto[][COL_S]);

int main(){
	//user input
	int Option1, Option2, save;
	
	
	//store Photo
	int ReadC, ReadR;
	char Photo[ReadR][ReadC];
	char proPhoto[ReadR][ReadC];


	do{
		printf("Welcome to Erinstagram please select an option:\n");
		printf("1. Load an image\n 2. Edit Image\n 3. Exit program\n");
		scanf("%d", &Option1);
	
	
	switch(Option2){
		case '1':
		//Load image
		printf("\n\nLoading Photo\n\n");

		loadPhoto(&ReadR, &ReadC, Photo);

		processPhoto(&ReadR, &ReadC, Photo, proPhoto);
		
			if(proPhoto[0][0] == 0){
				displayPhoto(&ReadR, &ReadC, proPhoto);
			}
		break;
		case '2':
			if(proPhoto[0][0] == 0){
				printf("No Photo loaded\n");
			}else{
			printf("\n\nEditing Photo\n\n");
			printf("To crop image enter 4, to brighten image enter 5,to dim image enter 6, to save enter 7\n");
			scanf("%d", &Option2);

				if(Option2 == 4){
					cropPhoto(&ReadR, &ReadC, proPhoto);
					
					displayPhoto(&ReadC, &ReadR, proPhoto);
				
				}else if(Option2 == 5){
					brightenPhoto(&ReadR, &ReadC, proPhoto);
					
					displayPhoto(&ReadC, &ReadR, proPhoto);

				}else if(Option2 == 6){
					dimPhoto(&ReadR, &ReadC, proPhoto);
					
					displayPhoto(&ReadC, &ReadR, proPhoto);
				
				}else if(Option2 == 7){
					savePhoto(&ReadR, &ReadC, proPhoto);
				}
			}
		break;
		case 3 :
		printf("\n\ngoodbye!\n\n");
		break;
		
		default:
			printf("\n\nNot a vaild option enter a new one\n\n");
			break;
		
	}
}while(Option1 != 3);
	

return 0;
}

//functions now

void loadPhoto(int *ReadR, int *ReadC, char ArrayPhoto[][COL_S]){
	//declareing so im able to open an Photo from a file 

	FILE* FP;
	char FILENAME[900];

	// make sure it does not have junk in there when it stores.
	int Rows = 0, Col = 0;

	//reset the array making get rid of junk

	for(int i = 0; i < *ReadR; i++){
		for(int j = 0; j < *ReadC; j++){
			ArrayPhoto[i][j] = 0;
		}
	}
	//asking the user for what file they would love to read out of.

	printf("Please put in a file name to display the photo\n");
	scanf("%s", FILENAME);


	FP = fopen(FILENAME,"r");

	if(FP == NULL){
		printf("Error opening the file you name maybe it doesnt exist. \n");
	}else{

					for(Rows = 0; Rows < ROW_S; Rows++){
						fgets(ArrayPhoto[Rows],(ROW_S+1), FP);
					}
					fclose(FP);
			// for it to read the file to a space or to an endline character

			for(Rows = 0; ArrayPhoto[ROW_S][0] != '\0' && ArrayPhoto[ROW_S][0]!= '\n'; Rows++){}
			*ReadR = Rows;
			for(Col = 0; ArrayPhoto[0][COL_S] != '\0' && ArrayPhoto[0][COL_S]!= '\n'; Col++){}
			*ReadC = Col;
	}

}
void displayPhoto(int *Rows, int *Col, char ArrayPhoto[][COL_S]){
	printf("______________________________________\n");

	for(int i = 0; i< *Rows; i++){
		for(int j = 0; j < *Col; j++){
			printf("%c", ArrayPhoto[i][j]);
		}
		printf("\n");

	}
printf("______________________________________\n");

}

void brightenPhoto(int *Rows, int *Col, char ReadArr[][COL_S]){
	//using ascci table for the case as the vaulue it just made sense for me hence 32 46 etc
	int Curval;

	for(int i = 0; i < *Rows; i++){
		for(int j; j< *Col; j++){
			Curval = ReadArr[i][j];
			switch(Curval){
				case 32:
					ReadArr[i][j] = '.';
					break;
				case 46:
					ReadArr[i][j]= 'o';
					break;
				case 111:
					ReadArr[i][j]= 'O';
					break;
				case 79:
					ReadArr[i][j]= '0';
					break;
				
				case 48:
				ReadArr[i][j]= '0';
				break;
				
				default:
				printf("error on row %d, Column %d\n", i, j);
				break;

			}
		}
	}
}


void dimPhoto(int *Rows, int *Col, char ReadArr[][COL_S]){
	int Curval;

	for(int i = 0; i < *Rows; i++){
		for(int j; j< *Col; j++){
			Curval = ReadArr[i][j];
			switch(Curval){
				case 32:
					ReadArr[i][j] = ' ';
					break;
				case 46:
					ReadArr[i][j]= ' ';
					break;
				case 111:
					ReadArr[i][j]= '.';
					break;
				case 79:
					ReadArr[i][j]= 'o';
					break;
				
				case 48:
				ReadArr[i][j]= 'O';
				break;
				
				default:
				printf("error on row %d, Column %d\n", i, j);
				break;

			}
		}
	}
}

void savePhoto(int *Rows, int *Col, char ReadArr[][COL_S]){
	
}
	

		



	