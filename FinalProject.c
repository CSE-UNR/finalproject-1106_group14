//Authors: Faith Nelson and Tevon Westby
//Date: 5/7/24
//Purpose: Simple photo editor

#include <stdio.h>


int main(){
	int Option;

	do{
		printf("Welcome to Erinstagram please select an option:\n");
		printf("1. Display an image\n 2. Edit Image\n 3. Exit program\n");
		scanf("%d", Option);
	}while(Option != 3);
	switch(Option){
		case '1':
		//Display/load image
		break;
		case '2':
			printf("To crop image enter 4, to brighten image enter 5, and to dim image enter 6\n");
		break;
		default:
			printf("Goodbye\n");
		break;
		}
	
	






return 0;
}

