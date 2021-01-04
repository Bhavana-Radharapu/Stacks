#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int DebugMode;
struct stack{
    
    char *data;
    int top;
    int capacity;
    int size;
    
};
// constructor
//-----------------------------------------------------------------------
struct stack* init(){
    struct stack *list;
    list = (struct stack*)malloc(sizeof(struct stack));
    list->top = -1;
    list->capacity = 4;
    list->data = (char*)malloc(sizeof(list->capacity));
    return list;
}
//checks for full
//-----------------------------------------------------------------------
int isFull(struct stack *st){
    if(st->top == st->capacity-1)
        return TRUE;
    else
        return FALSE;
}
//checks empty stack
//-----------------------------------------------------------------------
int isEmpty(struct stack *st){
    if(st->top == -1)
        return TRUE;
    else {
        return FALSE;
    }
}
//checks if they match
//-----------------------------------------------------------------------
int match(char top,char c){
    int i = c - 'm';
    char list[4] = {'a','b','c','d'};
    
    if(top == list[i]){
        return TRUE;
    }
    else
        return FALSE;
}
//push function
//-----------------------------------------------------------------------
void push(struct stack *st, char c){
    
    if(isFull(st)){
        
        if(DebugMode == 1){
                     printf(" The stack size is %d", st->capacity);
            printf("\n");
                 }
        st->capacity = st->capacity + 4;
        
        if(DebugMode == 1){
                     printf(" The stack size is %d", st->capacity);
            printf("\n");
                 }
    }
    char* temp = st->data;
    st->data = (char*) malloc(st->capacity * sizeof(char));
    for(int j = 0; j < st->size; j++)
    {
        st->data[j] = temp[j];
    }
    free(temp);
    st->data[++(st->top)] = c;
    st->size++;
}
//pop function
//-----------------------------------------------------------------------
int pop(struct stack *pt){
    
    if(isEmpty(pt)){
        return -1;
    }
    
    pt->size--;
    return pt->data[pt->top--];
    
}
//-----------------------------------------------------------------------
void EmptyStack(struct stack *pt){
    while(!(isEmpty(pt) == TRUE)){
        pop(pt);
    }
}

//checks for char in list one
//-----------------------------------------------------------------------
int firstList(char a){
    
    char list_1[4] = {'a','b','c','d'};
    int list_size = 4;
    
    for(int i= 0; i<4;i++){
        if(a == list_1[i])
            return TRUE;
    }
    return FALSE;
}
//checks for char in list two
//-----------------------------------------------------------------------
int secondList(char c){

    char list_2[4] = {'m','n','o','p'};
    int list_size = 4;
    
    for(int j=0;j<list_size;j++){
        if(c == list_2[j])
            return TRUE;
    }
    return FALSE;
}
//checks if at least one exists
//-----------------------------------------------------------------------
bool exists(char *c,int size){
    
    for(int k=0;k<size;k++){
        if(c[k]=='a'||c[k] == 'b'||c[k] == 'c'||c[k] == 'd')
            return true;
    }
    return false;
}
//trims the letters
//-----------------------------------------------------------------------
void RemoveExtraLetter(char *c){
  
    int count = 0;
    while(c[count] != '\0'){
        
        if(c[count]=='a'||c[count] == 'b'||c[count] == 'c'||c[count] == 'd'){
            printf("%c",c[count]);
        }
        count++;
    }
    printf(" ");
}

//-----------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    //debug mode
    DebugMode = 0;
    
    for(int k=0;k<argc;k++){
    if(strcmp(argv[k], "-d") == 0){
        DebugMode = 1;
    }
    }
    struct stack *st;
    st = init();

    char input[300];
    
     /* set up an infinite loop */
 while (1)
 {
   /* get line of input from standard input */
     
   printf ("\nEnter input to check or q to quit\n");
   fgets(input, 300, stdin);
   /* remove the newline character from the input */
   int i = 0;
   while (input[i] != '\n' && input[i] != '\0')
   {
      i++;
   }
   input[i] = '\0';


   /* check if user enter q or Q to quit program */
   if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) )
     break;
 
//    printf ("%s\n", input);
   /*Start tokenizing the input into words separated by space
    We use strtok() function from string.h*/
   /*The tokenized words are added to an array of words*/
   
   char delim[] = " ";
   char *ptr = strtok(input, delim);
   int j = 0 ;
   char *wordList[15];
  

    while (ptr != NULL)
    {
        wordList[j++] = ptr;
        ptr = strtok(NULL, delim);
    }
     
    if(DebugMode != 1){
     printf("Decoded message: ");
    }
     
     //checks for each word in worlist
     for(int k=0;k<j;k++){
         int size = strlen(wordList[k]);
       char* word =  wordList[k];
       
         for(int j=0;j<size;j++){
             if(firstList(word[j])){
                 push(st,word[j]);
                 if(DebugMode == 1){
                     printf("The item being pushed %c", word[j] );
                     printf("\n");
                 }
             }
             else if(secondList(word[j])){
                 if(match((st->data[st->top]),word[j])){
                     if(DebugMode == 1){
                     printf("The item being popped %c", st->data[st->top] );
                         printf("\n");
                 }
                     pop(st);
                 }
                 else{
                     break;
                 }
             }
         }
         
         if(DebugMode == 1){
             printf("Decoded message: ");
            }
         if(isEmpty(st) && exists(input,size)){
             RemoveExtraLetter(wordList[k]);
         }
         else{
             EmptyStack(st);
         }
     }

     
     printf("\n");
  /*Run the algorithm to decode the message*/
 }
    
    printf ("\nGoodbye\n");
    
    return 0;
}



