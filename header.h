struct node {int i; struct node *next; };

void print_list(struct node * head);
struct node * insert_front(struct node * head, int i);
struct node * free_list(struct node * head);
struct node * remove_node(struct node *front, int data);
