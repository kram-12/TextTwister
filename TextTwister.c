#include<stdio.h>
#include<string.h>
#define size 5

char answer[] = "apple";
char jumble[] = "elpap";
char copy[] = "elpap";
char queue[size] ="";
char stack[size]="";

int jumblePoint = 0;
int top = -1;
int rear = -1, front = -1;

void push();
void enqueue();
void QueueToStack();
void StackToQueue();
void printJ();
void printQ();
void printS();
int checkQueue();
int checkStack();
int check();
void reset();

int main(){
    int ch = 1;
    while(ch){
        printf("Rules:\n"
        "Enter 1 to Push (From Jumbled Word to Stack)\n"
        "Enter 2 to Enqueue (From Jumbled Word to Queue)\n"
        "Enter 3 to Pop (From Stack to Queue)\n"
        "Enter 4 to Dequeue (From Queue to Stack)\n"
        "Enter 5 to Submit the answer\n"
        "Enter 6 to Reset\n\n");

        printf("Jumbled Word: ");printJ();printf("\n");
        printf("Queue Word: ");printQ();printf("\n");
        printf("Stack Word: ");printS();printf("\n");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                push();
                break;
            case 2:
                enqueue();
                break;
            case 3:
                StackToQueue();
                break;
            case 4:
                QueueToStack();
                break;
            case 5:
                ch=check();
                if(ch==1)reset();
                break;
            case 6:
                reset();
                break;
            default:
                printf("\nEnter Valid choice\n");
                ch=0;    
        }
    }

    return 0;
}

void printJ(){
    int i=jumblePoint;
    while(jumble[i]!='\0'){
        printf("%c",jumble[i]);
        i++;
    }
}

void printS(){
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
}

void printQ(){
    int i;
    if (front != -1){
        for (i = front; i != rear; i = (i + 1) % size) {
            printf("%c", queue[i]);
        }
        printf("%c", queue[i]);
    }
    else{
        printf("");
    }
}

void QueueToStack(){
    int item;
    if(front == -1){
        printf("\n Queue is empty !! \n");
        return;
    } 
    else{
        item = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        top++;
        stack[top]=item; 
    }   
}

void push(){
    if(jumblePoint>=size){
        printf("No letters remaining in the Jumpled Word\n");
        return;
    }
    top++;
    stack[top]=jumble[jumblePoint];
    jumblePoint++;
}

void StackToQueue(){
    if(top==-1){
        printf("No letters in the \"Stack\" Word\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    queue[rear] = stack[top];
    top--;
}

void enqueue(){
    if(jumblePoint>=size){
        printf("No letters remaining in the Jumpled Word\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    queue[rear] = jumble[jumblePoint];
    jumblePoint++;  
}

int checkQueue() {
  int i;
  if (front == -1)
    return 0;
  else {
    int j=0;
    for (i = front; i != rear; i = (i + 1) % size) {
      if(queue[i]!=answer[j]){
            return 0;
        }
      j++;
    }
    if(queue[i]!=answer[j]){
            return 0;
        }
    }
    return 1;
}

int checkStack(){
    if(stack[0]=='\0'){
        return 0;
    }
    if(strcmp(stack,answer)==0){
        return 1;
    }
    return 0;
}

int check(){
    int cq=checkQueue(),cs=checkStack();
    if(cq==1||cs==1){
        printf("\nYou Win\n");
        return 0;
    }
    else{
        printf("\nYou Lose, Try Again\n");
        return 1;
    }
}

void reset(){
    strcpy(jumble,copy);
    strcpy(queue,"");
    strcpy(stack,"");
    jumblePoint=0;
    int top = -1;
    int rear = -1, front = -1;
}