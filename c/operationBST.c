#include <stdlib.h>
#include <string.h>
typedef struct node
{
struct node *leftchild;
int info;
struct node *rightchild;
}
NODE;
NODE * get_node(int val)
{
NODE *p;
p = (NODE*)malloc(sizeof(NODE));
p->info=val;
p->leftchild = p->rightchild = NULL;
return p;
}
NODE* insert(NODE *h, int key)
{
NODE *p,*q;
q = get_node(key);
if(h==NULL)
h = q;
else
{
p = h;
while(1)
{
if(p->info>q->info)
{
if(p->leftchild==0)
{
p->leftchild = q;
break;
}
else
p=p->leftchild;
}
else
{
if(p->rightchild==0)
{
p->rightchild = q;
break;
}
else
p=p->rightchild;
}
}
}
return h;
}
NODE * create()
{
int i,n,key;
NODE *h=NULL;
printf("Enter no.of keys:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter key:");
scanf("%d",&key);
h = insert(h,key);
}
return h;
}
void inorder(NODE *h)
{
if(h!=NULL)
{
inorder(h->leftchild);
printf("%d\t",h->info);
inorder(h->rightchild);
}
}
int main()
{
NODE *root;
int ch,key;
while(1)
{
printf("1.Create\n");
printf("2.Insert\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice (1-6):");
scanf("%d",&ch);
switch(ch)
{
case 1:
root = create();
break;
case 2:
printf("Enter key to insert:");
scanf("%d",&key);
root=insert(root,key);
break;
case 3:
inorder(root);
printf("\n");
break;
case 4:
exit(0);
}
getch();
}
}