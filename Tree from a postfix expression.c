# include <stdio.h>
# include <string.h>
# include <stdlib.h>


struct node
{
    char op;
    int d;
    struct node * left;
    struct node * right;
}; //  this is for tree formation in the backgroud

int CTD(char c) // Another Way to convert a Char Digit to Integer Digit
{
    int z1;
    
    z1 = c - 48;
    
    return z1; 
}

void PostOrder(struct node * p)
{
    if(p == NULL)
        return;

    PostOrder(p->left);
    PostOrder(p->right);
    if(p->d == -1)
        printf("%c \t", p->op);
    else
        printf("%d \t", p->d);
}

struct node * root = NULL; // initial null tree

struct node * getnode() // for both operators and numbers
{
   struct node *p;
   
   p = (struct node *) malloc(sizeof(struct node));
  
   p -> left = NULL;
   p -> right = NULL;
   
   return p;
}

struct node * stack[10]; // stack for workout is empty at beginning
int top=-1;

void push(struct node * p)
{
    struct node * k;
    
    if(top==9)
        printf("Stack is Full \n");
    else
    {
        top++;
        stack[top]=p;
    }
}

struct node * pop()
{
    struct node * k;
    
    if(top==-1)
            printf("Stack is Empty \n");
    else
    {
        k = stack[top];
        top--;
        return k;
    }
}

int main()
{
    char inp[10],c;
    struct node * p, * q, * z;
    
    printf("Give Postfix Expression \n");
    scanf("%s",inp);
    
    int l=strlen(inp);
    
    for(int i=0;i<l;i++)
    {
        c=inp[i];
        
        if(c>='0' && c<='9')
        {
            p = getnode();
            p->d = CTD(c);
            p->op = '\0';
            push(p);
        }
        else
        {
            p = pop();
            q = pop();
            z = getnode();
            
            z->op = c;
            z->d = -1;
            z -> left = q;
            z -> right = p;
            push(z);
       }
    }
    
p = pop();
root = p;

printf("Resulting Tree is \n");
PostOrder(root);

return 0;
}
