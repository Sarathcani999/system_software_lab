#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int arr[100],input[100],index_arr[100],indx,frame_size,i,count=0;

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

int find_index(int k,int length,int value){
	int j;
	for(j=k;j<length;j++){
		if(value == input[j]){
			return j;
		}
	}
}

void make_index_arr(int k,int length){
	int j;
	for(j=0;j<frame_size;j++){
		index_arr[j] = find_index(k,length,arr[j]);
	}
}

void print_arr(){
	int j;
	printf("\n");
	for(j=0;j<frame_size;j++){
		printf("%d\n",arr[j]);
	}
	printf("\n");
}

int find_largest_index(){
	int j;
	int largest = 0;
	for(j=1;j<frame_size;j++){
		if(index_arr[j]>index_arr[largest]){
			largest = j;
		}
	}
	return largest;
}

void update(int li,int k){
//	indx = (indx+1) % frame_size;
//	arr[indx] = input[k];
//	print_arr();

	arr[li] = input[k];
	print_arr();
}

void process(int length){
	int k,li;
	for(k=0;k<length;k++){
		if(check_if_present(input[k]) == 0){
			make_index_arr(k,length);
			li = find_largest_index();
			update(li,k);
		}else{
			
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
