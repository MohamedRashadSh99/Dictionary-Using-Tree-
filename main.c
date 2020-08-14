#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//CONSTANTS
#define wrdlen 48


FILE*ifp1 ;
// A struct representing a node in a binary search tree

struct treenode
{
    // The contents of the node
char word[wrdlen];
	// Links to the node's left and right children
struct treenode* left;
struct treenode* right;
};
struct treenode *pre;
struct treenode *suc;
struct treenode *leaf;
int maxHeight(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int height(struct treenode *root)
{
     return (root == NULL ? -1 : 1 + maxHeight(height(root->left), height(root->right)));
}

int size(struct treenode *root)
{
    return (root == NULL ? 0 : 1 + size(root->left) + size(root->right));
}

// Adds a new node to the tree. Duplicates are disallowed. Returns 1 if a
// new node was added, returns 0 if newdata was already in the tree
int insert(struct treenode** root, char newword[wrdlen])
{
    // If we've reached the right place to insert, create a new node and add it in
	if( (*root) == NULL)
	{
		(*root) = (struct treenode*)malloc(sizeof(struct treenode));
        strcpy((*root)->word,newword);
		(*root)->left = NULL;
		(*root)->right = NULL;
		return 1;
	}
    // Otherwise, search for the correct place to insert

	if(strcmp(newword,(*root)->word)<0)
	{
		return insert( &((*root)->left), newword);
	}

	else if(strcmp(newword,(*root)->word)>0)
	{
		return insert( &((*root)->right), newword);
	}
// If the new data is neither less than nor greater than the the data at
// the current node, it must be equal, and duplicates are not allowed
	else
	return 0;
}

// Returns 1 if target is in the tree and 0 otherwise
int search(struct treenode* root, char target[wrdlen])
{

    // An empty tree contains nothing, much less target
	if(root == NULL)
		return 0;
    leaf=root;
	// If the current node is what we're looking for, we've found it

	if(strcmp(root->word,target) == 0)
    {


		return 1;}
    // If what we're looking for is smaller than this node, it must be in
    // the left subtree if it exists
	if(strcmp(target,root->word) < 0)
    {
    //    leaf=root;
		return search(root->left, target);}
	// Similarly, if the target is greater than this node, it can only be in
    // the right subtree
	else{
      //  leaf=root;
	return search(root->right, target);}
}




void predecessor(struct treenode *root,char *target )
{
    if(root==NULL)return;

    if(strcmp(root->word,target)==0)
    {
       if(root->left!=NULL)
       {
      struct treenode*temp1=root->left;
        while(temp1->right!=NULL)
            temp1=temp1->right;
        pre=temp1;

    }

     if(root->right!=NULL)
       {
        struct treenode*temp1=root->right;
        while(temp1->left!=NULL)
            temp1=temp1->right;
        suc=temp1;

    }
return ;
}
if(strcmp(target,root->word)<0)
{
    suc=root;
    predecessor(root->left,target);
}
else
{

    pre=root;
    predecessor(root->right,target);

}

}
/*
void leaf()
{

}
void predsucessor()
{


}
*/
int ask_the_user_for_the_dictionary_file(int valid)

  {while(!valid)
    {
        char infile[wrdlen];
         printf("Please enter the name of the dictionary file you wish to access\n");
         scanf("%s", infile);
         ifp1 = fopen(infile, "r");

         if(ifp1 == NULL)
           printf("sorry, could not find that file!\n");
         else
         {
             valid = 1;
             printf("Reading file now.........\n");
         }
    }

    return valid;
    }
int main(void)
{
    char c;
    int x,i,valid;
    valid = 0;
    struct treenode* root;
    char newword[wrdlen];
    root = NULL;


    //ask the user for the dictionary file
    if(ask_the_user_for_the_dictionary_file(valid)==1)

    {valid = 0;
    //read in all the words and place them into a BST

    while(!feof(ifp1))
    {
        fscanf(ifp1, "%s ", newword);

        insert(&root, newword);


    }
    system("cls");

    printf("Height of our tree =%d\n",height(root));
    printf("Number of nodes =%d\n\n\n",size(root));


      char postfix[]="I kemo am mo engineer Zorro's teasel's properer Saroyan's capability's conjunctive homeless's dopy intensities";
   // char postfix[wrdlen];
   // printf("enter your word to search for: ");

   char*token=strtok(postfix," ");
    while(token!=NULL)
 {

 x= search(root,token);
	if(x==0)
    {
        predecessor(root,leaf->word);
        printf("\n%s not found- %s -%s-%s\n",token,leaf->word,pre->word,suc->word);

    }
    else
        printf("\n%s-found\n",token);

	token=strtok(NULL," ");
 }

    }
c='2';
while(c!='1')
{
    scanf("%c",&c);
    if(c!='1')
        printf("\nenter 1 to exit\n");;

}
return 0;
}

