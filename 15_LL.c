#include <stdio.h>
#include <stdlib.h>

struct linklist {
    int no;
    struct linklist* next;
};

typedef struct linklist node;

node* create(node*, int);
node* front_insert(node*, int);
node* middle_insert(node*, int, int);
node* end_insert(node*, int);
node* front_delete(node*);
node* middle_delete(node*, int);
node* end_delete(node*);
node* sort(node*);
void search(node*, int);
void count(node*);
void copy(node*);
void reverse(node*);
void display(node*);
void findsum(node*);

int main() {
    int n, i, ch, x, ich, dch;
    node* head = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Sort\n");
        printf("5. Search\n");
        printf("6. Count\n");
        printf("7. Copy\n");
        printf("8. Reverse\n");
        printf("9. Display\n");
        printf("10. Find sum\n");
        printf("11. Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of elements you want to enter: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &x);
                    head = create(head, x);
                }
                break;
            case 2:
                printf("\nInsertion Menu:\n");
                printf("1. Front Insert\n");
                printf("2. Middle Insert\n");
                printf("3. End Insert\n");
                printf("Enter your choice: ");
                scanf("%d", &ich);
                switch (ich) {
                    case 1:
                        printf("Enter the element to insert at the front: ");
                        scanf("%d", &x);
                        head = front_insert(head, x);
                        break;
                    case 2:
                        printf("Enter the element after which to insert: ");
                        scanf("%d", &n);
                        printf("Enter the element to insert: ");
                        scanf("%d", &x);
                        head = middle_insert(head, n, x);
                        break;
                    case 3:
                        printf("Enter the element to insert at the end: ");
                        scanf("%d", &x);
                        head = end_insert(head, x);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 3:
                printf("\nDeletion Menu:\n");
                printf("1. Front Delete\n");
                printf("2. Middle Delete\n");
                printf("3. End Delete\n");
                printf("Enter your choice: ");
                scanf("%d", &dch);
                switch (dch) {
                    case 1:
                        head = front_delete(head);
                        break;
                    case 2:
                        printf("Enter the element to delete: ");
                        scanf("%d", &x);
                        head = middle_delete(head, x);
                        break;
                    case 3:
                        head = end_delete(head);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 4:
                head = sort(head);
                printf("Sorted successfully.\n");
                break;
            case 5:
                printf("Enter the number you want to search: ");
                scanf("%d", &x);
                search(head, x);
                break;
            case 6:
                count(head);
                break;
            case 7:
                copy(head);
                break;
            case 8:
                reverse(head);
                break;
            case 9:
                display(head);
                break;
            case 10:
                findsum(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

node* create(node* head, int n) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->no = n;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        node* traverse = head;
        while (traverse->next != NULL) {
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
    return head;
}

node* front_insert(node* head, int n) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->no = n;
    temp->next = head;
    head = temp;
    return head;
}

node* middle_insert(node* head, int n, int x) {
    node* temp = head;
    while (temp != NULL && temp->no != n) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", n);
    } else {
        node* new_node = (node*)malloc(sizeof(node));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        new_node->no = x;
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}

node* end_insert(node* head, int n) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->no = n;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        node* traverse = head;
        while (traverse->next != NULL) {
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
    return head;
}

node* front_delete(node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

node* middle_delete(node* head, int x) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        node* temp = head;
        node* prev = NULL;
        while (temp != NULL && temp->no != x) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Element %d not found in the list.\n", x);
        } else {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
        }
    }
    return head;
}

node* end_delete(node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node* temp = head;
        node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    return head;
}

node *sort(node *head)
{
  node *temp,*temp1;
  int no1;
  temp=head;
  while(temp!=NULL)
  {
     temp1=temp->next;
     while(temp1!=NULL)
     {
       if(temp->no>temp1->no)
       {
	 no1=temp->no;
	 temp->no=temp1->no;
	 temp1->no=no1;
       }
       temp1=temp1->next;
     }
     temp=temp->next;
  }
  return(head);
}

void search(node* head, int x) {
    node* temp = head;
    int pos = 1;
    while (temp != NULL && temp->no != x) {
        temp = temp->next;
        pos++;
    }
    if (temp != NULL) {
        printf("Element %d found at position %d.\n", x, pos);
    } else {
        printf("Element %d not found in the list.\n", x);
    }
}

void count(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of elements in the list: %d\n", count);
}

void copy(node *head)
{
  node *temp,*new1=NULL,*head1=NULL,*temp1;
  temp=head;
  while(temp!=NULL)
  {
    new1=(node*)malloc(sizeof(node));
    new1->no=temp->no;
    new1->next=NULL;
    temp=temp->next;
    if(head1==NULL)
       head1=new1;
    else
    {
      temp1=head1;
      while(temp1->next!=NULL)
	 temp1=temp1->next;
      temp1->next=new1;
    }
  }
  printf("Original link list is:");
  display(head);
  printf("\nNew copied linked listis:");
  display(head1);
}

void reverse(node *head)
{
   node *temp,*new1,*temp1;
   temp=head;
   while(temp!=NULL)
   {
     if(temp==head)
     {
       new1=(node*)malloc(sizeof(node));
       new1->no=temp->no;
       new1->next=NULL;
       temp1=new1;
     }
     else
     {
       new1=(node *)malloc(sizeof(node));
       new1->no=temp->no;
       new1->next=temp1;
       temp1=new1;
     }
     temp=temp->next;
   }
   printf("Original link list is:");
   display(head);
   printf("\n\nReverse link list is:");
   display(temp1);
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List elements: ");
        while (head != NULL) {
            printf("%d ", head->no);
            head = head->next;
        }
        printf("\n");
    }
}

void findsum(node* head) {
    int sum = 0;
    node* temp = head;
    while (temp != NULL) {
        sum += temp->no;
        temp = temp->next;
    }
    printf("Sum of elements in the list: %d\n", sum);
}