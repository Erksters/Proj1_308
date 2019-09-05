/**********************************************
 * Name: ERICK SAENZ-GARDEA                   *
 * Date: SEPT 8TH, 2019                       *
 * Assignment: Project 1 -Sequence and Order validation*
 * **********************************************
 *  This program will be able to read text files line-by-line and
 *  validate the bracket expression. If the brackets are miswritten, the program will
 *  specify which line the error is found*
 *  *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkExp(char str[256]);
void push(char);
char pop();
void find_top();
char peek();

int top = 0;
char stack[100];
char newStack[100];

int main() {
    //This will open the test file in the working directory
    FILE* filePointer = fopen("test.txt", "r");
    if(filePointer == NULL){
        printf("Cant open filePointer");
        return 1;
    }
    //Initializing the object to hold all our text
    char output[256];

    //Converting the first line to an int for the loop.
    int lines =  atoi(fgets(output, sizeof(output), filePointer));
    printf("there are %d lines\n", lines);

    int flag = 0;
    //iterating through the text file line-by-line.
    for(int i = 1; i< lines+1; i++){
        fgets(output, sizeof(output), filePointer);
        //Check the expression here using "Stacks"
        if(checkExp(output) == 0)
        {
            printf("Line %d: incorrect\n",i);
            flag = 1;
        }
        else
        {
            printf("Line %d: looks good\n",i);
        }
        top = 0;
    }

    if (flag == 1){
        printf("All lines were NOT formatted correctly");
    } else {
        printf("All lines are formatted correctly");
    }

    fclose(filePointer);
    return 0;


}

// This method will check the string to see if the brackets match. If the brackets are balanced, then the method will return a 1.
int checkExp(char str[256]){
    for (int i = 0; str[i] != '\0';i++)
    {
        if (str[i] == '(' | str[i] == '[' | str[i] == '{' | str[i] == ')' | str[i] == ']' | str[i] == '}')
        {
            if(top == 0){
                push(str[0]);
                stack;
                continue;
            }else if (top>0){
                char open = peek();
                char close = str[i];

                if (open == '(' & (str[i] == ')'))
                {
                    pop();
                }
                else if (open == '[' & (str[i] == ']'))
                {
                    pop();
                }
                else if (open == '{' & (str[i] == '}'))
                {
                    pop();
                }
                else {
                    push(str[i]);
                }

            }
        }
    }
    if (top == 0) {
        return (1);
    }
    else{
        return (0);
    }
}

//This method will return the character at the top of the stack, then lower the value of the top
char pop()
{
    if (top == 0)
    {
        printf("expression is invalid\n");
        exit(0);
    }
    else
    {
        top--;
        return (stack[top]);
    }
}

//This method will add onto the stack char 'a' at the top, then increase the value of top for further pushing.
void push(char a)
{
    stack[top] = a;
    top++;
}

//This method will return the most recent character added onto the stack. If the stack is empty, then the method will print a message to help the user correct this mistake.
char peek(){
    if(top - 1 != -1){
        return (stack[top-1]);
    }
    printf("nothing on stack to peek at");
    return 'x';
}