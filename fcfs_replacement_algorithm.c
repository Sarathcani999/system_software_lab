#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int arr[100],input[100],indx,frame_size,i,count=0;

void enter_input(int length){
	printf("Enter the input values :\n");
	for(i=0;i<length;i++){
		scanf("%d",&input[i]);
	}
}

int check_if_present(int value){
	for(i=0;i<frame_size;i++){
		if(value == arr[i]){
			count++;
			return 1;
		}
	}
	return 0;
}

void print_arr(){
	int j;
	printf("\n");
	for(j=0;j<frame_size;j++){
		printf("%d\n",arr[j]);
	}
	printf("\n");
}

void update(int k){
	indx = (indx+1) % frame_size;
	arr[indx] = input[k];
	print_arr();
}

void process(int length){
	int k;
	for(k=0;k<length;k++){
		if(check_if_present(input[k]) == 0){
			update(k);
		}
	}
}

void main(){
	int length;
	indx = -1;
	printf("Enter the no of frames\n");
	scanf("%d",&frame_size);
	printf("Enter the input length\n");
	scanf("%d",&length);
	enter_input(length);
	process(length);
	printf("Page Faults = %d",(length-count));
}
