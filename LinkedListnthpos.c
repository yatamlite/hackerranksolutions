//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list?h_r=next-challenge&h_v=zen
/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = data;
    if (head == NULL) {
            insert->next = NULL;
            head = insert;  
    } else if (position == 0) {
            insert->next = head;
            head = insert;
    } else {
        struct Node *temp, *next;
        temp = head;

        while(--position > 0) {
           temp = temp->next; 
        }
        next = temp->next;
        temp->next = insert;
        insert->next = next;
        
    }
    return head;
}
