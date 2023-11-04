#include <stdlib.h>
#include <stdio.h>

typedef struct s_list{
    int id;
    char * name;
    int price;
    int page_count;
    char * language;
    int weight;
    int year;

    struct s_list *next;
} t_list;


t_list *create_node(int set_id, char* set_name, int set_price, int set_page, char* set_language, int set_weight, int set_year){
    t_list *node = (t_list *)malloc(sizeof(t_list));

    node->id = set_id;
    node->name = set_name;
    node->price = set_price;
    node->page_count = set_page;
    node->language = set_language;
    node->weight = set_weight;
    node->year = set_year; 

    node->next = NULL;
    return node;
}

void push_back (t_list **list, int set_id, char *set_name, int set_price, int set_page, char* set_language, int set_weight, int set_year){
    t_list *new_element = create_node(set_id,set_name,set_price, set_page, set_language, set_weight, set_year);

    t_list *tmp = *list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_element;

}

int main(){
    t_list *list = create_node(0, "Harry Potter and the Philosopher’s Stone", 110, 500,"English",800,1997);

    push_back(&list, 1, "Harry Potter and the Chamber of secrets", 200, 660,"English",800,1998);
    push_back(&list, 2, "Harry Potter and the Prisoner of Azkaban", 195, 778,"English",1000,1999);
    push_back(&list, 3, "Harry Potter and Goblet of Fire", 180, 500,"English",650,2000);
    push_back(&list, 4, "Harry Potter and the Order of the Phoenix", 190, 955,"English",1240,2003);
    push_back(&list, 5, "Harry Potter and the Half-Blood Prince", 220, 624,"English",950 ,2005);
    push_back(&list, 6, "Harry Potter and the Deathly Hallows", 220, 784,"English",1025,2007);


    while (list != NULL){
        printf("Book: %d\n", list->id+1);
        printf("Name: %s\n", list->name);
        printf("Price : %d dollars\n", list->price);
        printf("Page count: %d \n", list->page_count);
        printf("Language: %s\n", list->language);
        printf("Weight: %d  \n", list->weight);
        printf("Year: %d\n", list->year);
        
        printf("/////////////////////////////\n");
        list= list->next;
    }
    
    t_list *tmp;
    while(list) { 
        tmp = list;
        list = list->next;
        free(tmp);
    }
}