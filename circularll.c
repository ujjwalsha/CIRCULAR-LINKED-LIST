#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//CIRCULAR LINKED LIST IMPLEMENTATION
struct link{
    int data;
    struct link* next;
};

typedef struct link node;
node* head;

node* createNode(){
    node* n;
    n = (node*)malloc(sizeof(node));
    return n;
}

//insert the node at ending
void insertatEnd(){

    node*curr = head;
    node* newnode = createNode();
    
    printf("Enter your node to insert ");
    scanf("%d", &newnode->data);
 
    newnode->next = newnode;
    if(head == NULL){
    head = newnode;
    }
    else{
         while(curr->next!= head){
        curr = curr->next;
    }
        curr->next = newnode;
        newnode->next = head;

    }
}

//insert at beginning 
void insertatbeg(){
    node* curr = head;
    node* newnode = createNode();

    printf("Enter your node ");
    scanf("%d", &newnode->data);

    newnode->next = newnode;
    if(head == NULL){
    head = newnode;
    }
    else{ 
       while(curr->next != head){
            curr = curr->next;
        }
        newnode->next = head;
        curr->next = newnode;
        head = newnode;
     }
}

//insert at the specific position 
void insertpos(){

    node* newnode;
    node* curr;
    int pos, n, i;
    newnode = createNode();
    printf("enter your position");
    scanf("%d", &pos);

    if(pos == 1){
        insertatbeg();
    }
    
    else{
     printf("enter your number ");
        scanf("%d", &n);
        newnode->data = n;
        curr = head;

        for(i=1; i<pos-1; i++){
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void deleteatbeg(){
    node* temp, *curr;
    curr = head;

    while(curr->next != head){
        curr = curr->next;
    }
    temp = head;
    head = head->next;
    curr->next = head;
    free(temp);
}

void deleteatlast(){

    node* temp, *curr;
    curr = head;

    if(head == NULL)
    printf(" CLL IS EMPTY");

    while(curr->next != head){
        temp = curr;
        curr = curr->next;
    }

    temp->next = head;
    free(curr);
}

void delpos(){
    int i , pos;
    node *temp, *curr;
    printf("enter your position ");
    scanf("%d", &pos);

    if(head == NULL)
    printf("cll is empty");

    else{  
            if(pos == 1)
            deleteatbeg();
            else{
            i = 1; 
            curr = head;
            while(i<pos){
                temp = curr;
                curr = curr->next;
                i++;
            }
            temp->next = curr->next;
            free(curr);
            }
   }
}

void display()
{

    node *curr = head;
    
    if(head == NULL)
    printf("linked list is empty");

    do{
        printf("%d-> ", curr->data);
        curr = curr->next;
    }while(curr!= head);
}

void destroy()
{
    node *curr = head;
    node* next;

    while(curr != head)
    {
        next= head;
        curr = curr->next;

        free(next);
    }
    head = NULL;
    printf("all node is deleted");
}

void count(){
    node* temp;
    int cnt = 0;

    
    temp = head;
    do{
        cnt++;
        temp = temp->next;
    }while(temp!= head);
    
    printf("number of node is %d", cnt);
}

void search(){
    node* temp;
    if(head == NULL)
    printf("\n linked list is empty");

    else{
        int res =0, num;
        temp = head;
        printf("enter your node to search");
        scanf("%d", &num);

        do{
            if(temp->data == num){
                printf("\b element is found");
                res = 1;
                break;
            }
            temp = temp->next;
        }while(temp!= head);
        if(res== 0)
        printf("\n element not found");
    }
}



void main(){
    int choice;
        printf("\n 1. INSERT AT ENDING ");
        printf("\n 2. INSERT AT THE BEGINNING ");
        printf("\n 3. INSERT AT THE SPECIFIC POSITION");
        printf("\n 4. DELETE AT BEGINNING IN CLL");
        printf("\n 5. DELETE AT ENDING IN CLL ");
        printf("\n 6. delete at specific position ");
        printf("\n 7. COUNTING THE NODE");
        printf("\n 8. SEARCHING THE NODE IN CLL");
        printf("\n 9. DISPLAY THE CLL ");
        printf("\n 10. DESTROY THE WHOLE CLL ");
        printf("\n 11. EXITING THE PROGRAM  ");

        
    while(1){
        printf("\n ENTER YOUR CHOICE ~ ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            insertatEnd();
            break;
            
            case 2:
            insertatbeg();
            break;
            
            case 3:
            insertpos();
            break;
    

            case 4:
            deleteatbeg();
            break;

            case 5:
            deleteatlast();
            break;

            case 6:
            delpos();
            break;

            case 7:
            count();
            break;

            case 8:
            search();
            break;

            case 9:
            display();
            break;
        
            case 10:
            destroy();
            break;

            case 11:
            exit(0);

            default:
            printf("invalid choice ");
        }
    }
}