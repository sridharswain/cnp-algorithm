#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node{
	char data;
	struct node *in,*up,*next,*prev;
};
struct node *head=NULL;
void insert(struct node **add,char x[],int n,int l,struct node **key);
void down(struct node **add,char x[],int n,int l);
void print(struct node **add);
void insert(struct node **add,char x[],int n,int l,struct node **key){//horizontal insert control function 
	if (n==-1){
		if (*add==NULL){
			insert(&(*key),x,n,l+1,&(*key));
			return;
		}
		while((*add)->prev!=NULL){
			*add=(*add)->prev;
			n++;
		}
		if (*add==head){
			printf("finish");
			return;
		}
		printf("%c->up\n",(*add)->data);
		insert(&(*add)->up,x,n+1,l+1,&(*key));
		return;
	}
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x[n];
	newnode->in=NULL;
	newnode->up=NULL;
	newnode->prev=NULL;
	newnode->next=NULL;
	if (*add==NULL){
		*add=newnode;
		newnode->up=*key;
		printf("new->%c\n",(*add)->data);
		down(&(*add),x,n-1,l);
		return;
	}
	else{
		(*add)->next=newnode;
		newnode->prev=*add;
		if ((*add)->up!=NULL){
			newnode->up=(*add)->up;
		}
		printf("next->%c\n",newnode->data);
		down(&(*add)->next,x,n-1,l);
		return;
	}
}
struct node *key=NULL;
void down(struct node **add,char x[],int n,int l){ //vertical insert control function.
	if (l==0){
		printf("l=0\n");
		//printf("%d",count);
		print(&(*add));//print called
		printf("\n");
		count++;
		insert(&(*add),x,n,l,&key);
		return;
	}
	if (*add==NULL){
		key=NULL;
		printf("start\n");
		insert(&(*add),x,n,l-1,&key);
		return;
	}
	else{
		key=*add;
		printf("goin\n");
		insert(&(*add)->in,x,n,l-1,&key);
		return;
	}
}
void print(struct node **add){ //print function
	if (*add==NULL){
		return;
	}
	else{
		print(&(*add)->up);
		printf("%c",(*add)->data);
	}
}
main(){//main 
	/*int i,n;
	printf("Enter the length of array:");
	scanf("%d",&n);
	*/char x[15]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};
	/*for(i=0;i<n;i++){
		printf("Enter %dth element:",i);
		scanf(" %c",&x[i]);
	}
	int l;
	printf("Enter the length of Combination:");
	scanf("%d",&l);*/
	down(&head,x,14,7);
}
