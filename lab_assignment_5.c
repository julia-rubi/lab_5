// Julianna Diaz
// COP 3502
// Professor Torosdagli
// 9 June 2023


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){

  // Initalizes the count to identify the length of the linkedlist
	int count = 0;
  
  // Creates node to take the value of the head
	node *current = head;
	
  // While loop that counts the length of the linkedlist until it equals null
	while(current != NULL){
    // Increases the count to find length of the linkedlist
		count++;
    // Moves to the next node to continue counting
		current = current->next;
	}
  // Returns total number of nodes in the linkedlist
	return count; 

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head){
  
  // Finds the length of the linkedlist with the length function
  int len = length(head);
  // Creates a char string compatible to the size of the linkedlist
	char *string =  (char*)malloc((len+1)*sizeof(char));
  // Makes parse_node equal to the head of the linkedlist
	node *parse_node = head; 

  // Variable to run through each character in the string
	int i = 0;
  
  // while loop that parses the string in the linkedlist until it equals null
	while(parse_node != NULL){

    // Goes through each part of the string and parses the letter
    string[i] = parse_node->letter;				
    // Continues to the next node
		parse_node = parse_node->next;
    i++;
	}
    // Identifies the end of the string
  	string[i] = '\0';

  // Returns the completed string 
	return string;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){
	
	// Creates new node to insert the character
	node *new_node = (node*)malloc(sizeof(node));
  // Makes current equal to the head pass through
  node *current = *pHead;
  
  // Adds the new character to the end and finishes the linkedlist
	new_node->letter = c;
	new_node->next = NULL;
  
  // Checks if the head is Null; if it is, it prints out gives linkedlist
	if(*pHead == NULL)
		*pHead = new_node;
  
  
  else {
	 
   // While loop that runs while linkedlist is not null
	 while(current->next != NULL) {
    // Continues to the next node
		current = current->next; 
	   }

  // Adds the next node to the end of the new_node
	current->next = new_node; 
  }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){

  // Creates a temp node to help delete the space
	node *temp;
  // Makes current node equal to the head passed through
	node *current = *pHead;

  // Runs until the current linkedlist turns null
	while(current != NULL){
    // Holds the next value of the linkedlist
		temp = current->next;
    // Frees the current space
		free(current);
    // Continues to the next value in the linkedlist
		current = temp;
	}
	
  // Makes the head null; 
  *pHead = NULL;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("DeleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
  return 0;
}