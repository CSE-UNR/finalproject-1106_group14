//Authors: Faith Nelson and Tevon Westby
//Date: 5/7/24
//Purpose: Simple photo editor

#include <stdio.h>
		#define ROW_S 300
		#define COL_S 300

void brightenPhoto(int *Rows, int *Col, char ReadArr[][COL_S]);
void processPhoto(int *Rows, int *Col, char ReadArr[][COL_S], char Arr[][COL_S]);
void cropPhoto(int *Rows, int *Col, char ReadArr[][COL_S]);
void displayPhoto(int *Rows, int *Col, char ArrayPhoto[][COL_S]);
void dimPhoto(int *Rows, int *Col, char ReadArr[][COL_S]);
void savePhoto(int *Rows, int *Col, char ReadArr[][COL_S]);
void loadPhoto(int *ReadR, int *ReadC, char ArrayPhoto[][COL_S]);

int main() {
    // User input
    	int Option1 = 0, Option2 = 0, save;

    // Store Photo
    int ReadC = 0, ReadR = 0;
    char Photo[ROW_S][COL_S];
    char proPhoto[ROW_S][COL_S];

    do {
        printf("Welcome to Erinstagram please select an option:\n");
        	printf("1. Load an image\n 2. Edit Image\n 3. Exit program\n");
        scanf("%d", &Option1);

        switch(Option1){
            case 1:
                // Load image
                printf("\n\nLoading Photo\n\n");
                loadPhoto(&ReadR, &ReadC, Photo);
                	processPhoto(&ReadR, &ReadC, Photo, proPhoto);
					
                        if(proPhoto[0][0] == 0){
                    displayPhoto(&ReadR, &ReadC, Photo);
                }
                break;
            		case 2:
                if(Photo[0][0] == 0){
                    	printf("No Photo loaded\n");
                }else{
                    printf("\n\nEditing Photo\n\n");
                        printf("To crop image enter 4, to brighten image enter 5, to dim image enter 6, to save enter 7\n");
                    scanf("%d", &Option2);
                    if(Option2 == 4){
                        cropPhoto(&ReadR, &ReadC, Photo);
                        displayPhoto(&ReadC, &ReadR, Photo);

                    }else if(Option2 == 5){
                        brightenPhoto(&ReadR, &ReadC, Photo);
                        displayPhoto(&ReadC, &ReadR, Photo);

                    }else if(Option2 == 6){
                        dimPhoto(&ReadR, &ReadC, Photo);
                        	displayPhoto(&ReadC, &ReadR, Photo);

                    }else if(Option2 == 7){
                        	savePhoto(&ReadR, &ReadC, Photo);

                    }
                }
                break;
            case 3:
                printf("\n\ngoodbye!\n\n");
                break;
            default:
                printf("\n\nNot a valid option, enter a new one\n\n");
                break;
        }
    } while(Option1 != 3);

    return 0;
}

void loadPhoto(int *ReadR, int *ReadC, char ArrayPhoto[][COL_S]){
    FILE *FP;
    char FILENAME[900];
    int Rows = 0,Col = 0;


    printf("Please put in a file name to display the photo\n");
    scanf("%s", FILENAME);

    FP = fopen(FILENAME, "r");
	
    if(FP == NULL){
        printf("Error opening the file you named, maybe it doesn't exist.\n");
    }else{
    	  for(int i = 0; i < *ReadR; i++){
        for(int j = 0; j < *ReadC; j++){
            ArrayPhoto[i][j] = 0;
        }
    }
        for(Rows = 0; Rows < ROW_S; Rows++){
            fgets(ArrayPhoto[Rows], (ROW_S + 1), FP);
        }
        fclose(FP);

        for(Rows = 0; ArrayPhoto[Rows][0] != '\0' && ArrayPhoto[Rows][0] != '\n'; Rows++){
        *ReadR = Rows;
        }
        
        for(Col = 0; ArrayPhoto[0][Col]!= '\0' && ArrayPhoto[0][Col]!= '\n'; Col++){
        *ReadC = Col;
      	}
    }
}

void displayPhoto(int *Rows, int *Col, char ArrayPhoto[][COL_S]) {
    printf("______________________________________\n");
    for (int i = 0; i < *Rows; i++) {
        for (int j = 0; j < *Col; j++) {
            printf("%c", ArrayPhoto[i][j]);
        }
        printf("\n");
    }

    printf("______________________________________\n");
}

void brightenPhoto(int *Rows, int *Col, char ReadArr[][COL_S]){
    int Curval;

   for(int i = 0; i < *Rows; i++){
        for(int j = 0; j < *Col; j++){
            Curval = ReadArr[i][j];
            switch(Curval){
                case' ':
                    break;
                case'.':
                    ReadArr[i][j] = 'o';
                    break;
                case 'o':
                    ReadArr[i][j] = 'O';
                    break;
                case 'O':
                    break;
                default:
                    printf("error on row %d, Column %d\n",i,j);
                    break;
            }
        }
    }
}

void dimPhoto(int *Rows, int *Col, char ReadArr[][COL_S]) {
    int Curval;

    for (int i = 0; i < *Rows; i++) {
        for (int j = 0; j < *Col; j++) {
            Curval = ReadArr[i][j];
            switch(Curval){
               case' ':
                    break;
                case'.':
                    ReadArr[i][j] = ' ';
                    break;
                case 'o':
                    ReadArr[i][j] = '.';
                    break;
                case 'O':
                    break;
                default:
                    printf("error on row %d, Column %d\n", i, j);
                    break;
            }
        }
    }
}

void savePhoto(int *Rows, int *Col, char ReadArr[][COL_S]) {
    FILE *FP;
    char FILENAME[900];

    printf("Please put in a file name to which you would like to save the photo\n");
    scanf("%s", FILENAME);

    FP = fopen(FILENAME, "w");

    // Write ReadArr content to the file here
    for(int i = 0; i< *Rows; i++){
        for(int j = 0; j < *Col; j++){
            fprintf(FP, "%c",ReadArr[i][j]);
        }
        fprintf(FP, "\n");
    }
    printf("saved!");
    fclose(FP);
}

void processPhoto(int *Rows, int *Col, char ReadArr[][COL_S], char Arr[][COL_S]){
    int Curchar, ValidPhoto = 0;

    for(int i = 0; i < *Rows; i++){
        for(int j = 0; j < *Col; j++){
            Curchar = Arr[i][j];
            switch(Curchar){
                case ' ':
                    ReadArr[i][j] = ' ';
                    break;
                case '.':
                    ReadArr[i][j] = '.';
                    break;
                case 'o':
                    ReadArr[i][j] = 'o';
                    break;
                case 'O':
                    ReadArr[i][j] = 'O';
                    break;
                case '0':
                    ReadArr[i][j] = '0';
                    break;
                default:
                    ValidPhoto = 1;
                    break;
            }
        }
    }
}

void cropPhoto(int *Rows, int *Col, char ReadArr[][COL_S]){
    int cropR = 0, cropC = 0, validC = 0, validR = 0, xRows = 0, xCols = 0, choice;

    do{
        do{
            printf("What row would you like to remove and where at?\nThe first Row should start at 0\n\n");
            scanf("%d",&cropR);
            if(cropR >= *Rows){
                printf("Your image is smaller than where you want to crop on the rows\n");
                validR = 0;
            }else{
                validR = 1;
            }
        }while (validR == 0);

        do{
            printf("What column would you like to remove and where at?\nThe first column should start at 0\n\n");
            scanf("%d",&cropC);
            if(cropC >=*Col){
                printf("Your image is smaller than where you want to crop on the columns\n");
                validC = 0;
            }else{
                validC = 1;
            }
        }while(validC == 0);

        printf("You want to crop row at %d\nYou want to crop at column: %d\nIs this correct? (1 = yes 2 = no) ",cropR,cropC);
        scanf("%d", &choice);
    }while(choice == 2);

        for(int i = 0; i < *Rows - cropR; i++){
            for(int j = 0; j < *Col - cropC; j++){
                ReadArr[i][j] = ReadArr[i + cropR][j + cropC];
            }
    }
    
         *Rows -= cropR;
                *Col -= cropC;
    
        for(xRows = 0; ReadArr[xRows][0] != '\0' && ReadArr[xRows][0] != '\n'; xRows++){
        *Rows = xRows;
    }
    
        for(xCols = 0; ReadArr[0][xCols] != '\0' && ReadArr[0][xCols] != '\n'; xCols++){
        *Col = xCols;
    }
}



	

	
