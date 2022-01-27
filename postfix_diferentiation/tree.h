#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;                 //node will store an integer
    struct node *right_child; // right child
    struct node *left_child;  // left child
};
typedef struct node *tree;
tree search(tree root, int x)
{
    if (root == NULL || root->info == x) //if root->info is x then the element is found
        return root;
    else if (x > root->info) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the info, so we will search the left subtree
        return search(root->left_child, x);
}
tree makeEmpty(tree T)
{
    if (T != NULL)
    {
        makeEmpty(T->left_child);
        makeEmpty(T->right_child);
        free(T);
    }
}
//function to find the minimum value in a node
tree findMin(tree root)
{
    if (root == NULL)
        return NULL;
    else if (root->left_child != NULL)    // node with minimum value will have no left child
        return findMin(root->left_child); // left most element will be minimum
    return root;
}
tree findMax(tree root)
{
    if (root == NULL)
        return NULL;
    else if (root->right_child != NULL)
        return findMax(root->right_child);
    else
        return root;
}
//function to create a node
tree new_node(int x)
{
    tree p;
    p = malloc(sizeof(tree));
    p->info = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

tree insert(tree root, int x)
{
    //searching for the place to insert
    if (root == NULL)
        return new_node(x);
    else if (x > root->info) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child, x);
    return root;
}

// funnction to delete a node
tree delete (tree root, int x)
{
    //searching for the item to be deleted
    if (root == NULL)
        return NULL;
    if (x > root->info)
        root->right_child = delete (root->right_child, x);
    else if (x < root->info)
        root->left_child = delete (root->left_child, x);
    else
    {
        //No Children
        if (root->left_child == NULL && root->right_child == NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if (root->left_child == NULL || root->right_child == NULL)
        {
            tree temp;
            if (root->left_child == NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            tree temp = findMin(root->right_child);
            root->info = temp->info;
            root->right_child = delete (root->right_child, temp->info);
        }
    }
    return root;
}
void postOrder(tree root)
{
    if (root != NULL)
    {
        postOrder(root->left_child);
        postOrder(root->right_child);
        printf("%d ", root->info);
    }
}
void inOrder(tree root)
{
    if (root != NULL) // checking if the root is not null
    {
        inOrder(root->left_child);  // visiting left child
        printf(" %d ", root->info); // printing info at root
        inOrder(root->right_child); // visiting right child
    }
}
void preOrder(tree root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preOrder(root->left_child);
        preOrder(root->right_child);
    }
}

int main()
{
    tree T = NULL, a;

    int choice, x;
    do
    {
        printf("\n2 -> FIND MINIMUM ELEMENT\n3 -> FIND MAXIMUM ELEMENT\n4 -> DISPLAY POSTORDER EXPRESSION\n5 -> DISPLAY INORDER EXPRESSION\n6 -> DISPLAY PREORDER EXPRESSION\n7 -> MAKE EMPTY\n8 -> INSERT ELEMENT\n9 -> DELETE ELEMENT\n10 -> EXIT\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 2:
        {
            a = findMin(T);
            if (a == NULL)
                printf("Tree is empty\n");
            else
                printf("Minimum element : %d \n", a->info);
            break;
        }
        case 3:
        {
            a = findMax(T);
            if (a == NULL)
                printf("Tree is empty\n");
            else
                printf("Maximum element : %d \n", a->info);
            break;
        }
        case 4:
        {
            if (T == NULL)
                printf("Tree is empty\n");
            else
                postOrder(T);
            break;
        }
        case 5:
        {
            if (T == NULL)
                printf("Tree is empty\n");
            else
                inOrder(T);
            break;
        }
        case 6:
        {
            if (T == NULL)
                printf("Tree is empty\n");
            else
                preOrder(T);
            break;
        }
        case 7:
        {
            makeEmpty(T);
            break;
        }
        case 8:
        {
            printf("Enter element to be inserted : ");
            scanf("%d", &x);
            T = insert(T, x);

            break;
        }
        case 9:
        {
            printf("Enter element to be deleted : ");
            scanf("%d", &x);
            T = delete (T, x);
            break;
        }
        }
    } while (choice != 10);

    return 0;
}