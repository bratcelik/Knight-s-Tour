#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 8

void accessibility(int arr[][SIZE],int,int,int *);
void move(int board[][SIZE],int *situations,int *i,int *j);
void strategicAccessibility(int arr[][SIZE],int i,int j,int *situation,int *strategicSituation);
void print(int board[][SIZE]);
int collectStatus(int *situation);

int main(){	
	int board[SIZE][SIZE]={{0}};
	int situations[SIZE]={0};
	int strategicSituations[SIZE]={0};//to stay on the next move
	int i,j;
	size_t step=2;
	srand(time(NULL));
	i=rand()%SIZE;
	j=rand()%SIZE;
	//i=7;j=2;
	board[i][j]=1;
	printf("Starting row : %d Starting column : %d\n",i+1,j+1);
	while(step<=64){
		accessibility(board,i,j,situations);
		strategicAccessibility(board,i,j,situations,strategicSituations);
		if(collectStatus(situations)!=0){	
			move(board,strategicSituations,&i,&j);
			board[i][j]=step;
			step++;
		}
		else
			break;
	}
	printf("Step taken : %d\n\n\n",step-1);
	print(board);		
	return 0;	
}
void print(int board[][SIZE]){
	int k,l;
	for(k=0;k<SIZE;k++){
		for(l=0;l<SIZE;l++)
			printf("%4d ",board[k][l]);
		printf("\n");	
	}
}
int collectStatus(int *situation){
		int i;

		int sum=0;
		for(i=0;i<SIZE;i++){
			sum += *(situation + i);
		}
		return sum;
}
void strategicAccessibility(int arr[][SIZE],int i,int j,int *situation,int *strategicSituation){
	int tempSituation[SIZE]={0};
	if(*situation==1){
		accessibility(arr,i-2,j-1,tempSituation);
		*strategicSituation = collectStatus(tempSituation)+1;
	}
	else
		*strategicSituation = 0;

	if(*(situation+1)==1){
		accessibility(arr,i-1,j-2,tempSituation);
		*(strategicSituation+1)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+1)=0;

	if(*(situation+2)==1){
		accessibility(arr,i+1,j-2,tempSituation);
		*(strategicSituation+2)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+2)=0;

	if(*(situation+3)==1){
		accessibility(arr,i+2,j-1,tempSituation);
		*(strategicSituation+3)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+3)=0;

	if(*(situation+4)==1){
		accessibility(arr,i+2,j+1,tempSituation);
		*(strategicSituation+4)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+4)=0;

	if(*(situation+5)==1){
		accessibility(arr,i+1,j+2,tempSituation);
		*(strategicSituation+5)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+5)=0;

	if(*(situation+6)==1){
		accessibility(arr,i-1,j+2,tempSituation);
		*(strategicSituation+6)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+6)=0;

	if(*(situation+7)==1){
		accessibility(arr,i-2,j+1,tempSituation);
		*(strategicSituation+7)= collectStatus(tempSituation)+1;
	}
	else
		*(strategicSituation+7)=0;

}
void accessibility(int arr[][SIZE],int i,int j,int *situation){
	if((i-2)>=0 && (j-1) >= 0){
		if(arr[i-2][j-1]==0){
			*situation=1;
		}
		else
		situation[0]=0;	
	}
	else
		situation[0]=0;
	if(i-1>=0&&j-2>=0){
		if(arr[i-1][j-2]==0)
			*(situation+1)=1;
		else
		situation[1]=0;	
	}
	else
		situation[1]=0;
	if(i+1<8 && j-2>=0){
		if(arr[i+1][j-2]==0)
			*(situation+2)=1;
		else
		situation[2]=0;	
	}
	else
		situation[2]=0;
	if(i+2<8 && j-1>=0){
		if(arr[i+2][j-1]==0)
			*(situation+3)=1;
		else
		situation[3]=0;	
	}
	else
		situation[3]=0;
	if(i+2<8&&j+1<8){
		if(arr[i+2][j+1]==0)
			*(situation+4)=1;
		else
		situation[4]=0;	
	}
	else
		situation[4]=0;
	if(i+1<8&&j+2<8){
		if(arr[i+1][j+2]==0)
			*(situation+5)=1;
		else
		situation[5]=0;	
	}
	else
		situation[5]=0;
	if(i-1>=0&&j+2<8){
		if(arr[i-1][j+2]==0)
			*(situation+6)=1;
		else
		situation[6]=0;	
	}
	else
		situation[6]=0;
	if(i-2>=0&&j+1<8){
		if(arr[i-2][j+1]==0)
			*(situation+7)=1;
		else
		situation[7]=0;	
	}
	else
		situation[7]=0;
}

void move(int board[][SIZE],int *strategicSituations,int *i,int *j){	
	size_t m;
	int k;
	int temp=10;
	for(m=0;m<SIZE;m++){
		if(*(strategicSituations+m)< temp && *(strategicSituations+m)>0){
			k = m;
			temp = *(strategicSituations+m);
		}
		else if(*(strategicSituations+m)==1)
			k=m;
	}
	switch(k){
		case 0:
			*i = *i-2;
			*j = *j-1; break;
		case 1:
			*i = *i-1;
			*j = *j-2; break;
		case 2:
			*i = *i+1;
			*j = *j-2; break;
		case 3:
			*i = *i+2;
			*j = *j-1; break;
		case 4:
			*i = *i+2;
			*j = *j+1; break;
		case 5:
			*i = *i+1;
			*j = *j+2; break;
		case 6:
			*i = *i-1;
			*j = *j+2; break;
		case 7:
			*i = *i-2;
			*j = *j+1; break;
		default :
		break;								
	}
}

