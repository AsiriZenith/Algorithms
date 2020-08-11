#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

//create binary tree untill enter '0'
struct node *create_tree(struct node *root)
{
    int n;
    struct node *ptr, *temp1, *temp2;
    printf("\n\nIf you want to stop, Enter '0'");
    do
    {
        printf("\nEnter a number : ");
        scanf("%d", &n);
        ptr =(struct node*)malloc(sizeof(struct node));
        ptr->data=n;
        ptr->left=ptr->right=NULL;

        if (root==NULL)
        {
            root=ptr;
        }
        else
        {
            temp1=root;
            while (temp1!=NULL)
            {
                temp2=temp1;
                if (temp1->data>ptr->data)
                {
                    temp1=temp1->left;
                }
                else if (temp1->data<ptr->data)
                {
                    temp1=temp1->right;
                }
                else
                {
                    printf("\n\nNo any change. because that value has exist.");
                }
            }
            if (temp2->data>ptr->data)
            {
                temp2->left=ptr;
            }
            else if (temp2->data<ptr->data)
            {
                temp2->right=ptr;
            }
        }
    } while (n!=0);
}

int main()
{
    struct node *root=NULL;
    //root = (struct node*)malloc(sizeof(struct node));
    create_tree(root);
}