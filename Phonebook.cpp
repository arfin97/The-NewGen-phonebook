#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;
void welcome(){
printf("\n\n\n\n\n\n\n\n\n\n\n\n");
printf("-------------------------------------------------------------------------------------------------------------\n");
printf("\t\t\t\t\t\ Welcome to Arfin's Phone Book \n");
printf("\t\t\t\t\t\ Name: Md. Hafizur Rahman Arfin\n");
printf("\t\t\t\t\t\ ID: 161-15-0000\n");
printf("-------------------------------------------------------------------------------------------------------------\n");
}

struct Node{
    char name[100];
    char phone[100];
    char email[100];
    struct Node *next;
};
typedef struct Node node;
int speed[10]; int speedid = 0;
//Functions prototypes;
void printnode(node *temp);
node *nameorlist(node *list);
void add(node *list, char name[], char phone[], char email[]);
void addtolog(node *list, char name[], char phone[], char email[]);
node *searchbyid(node *list, int n);
node *searchbyname(node *list, char name[]);
//menu function - only to print the menu;

void menu(){
    printf("\t\t\t\t\t\ 1. Show contacts list\n");
    printf("\t\t\t\t\t\ 2. Call\n");
    printf("\t\t\t\t\t\ 3. Call log\n");
    printf("\t\t\t\t\t\ 4. Speed dial\n");
    printf("\t\t\t\t\t\ 5. Add a new contact\n");
    printf("\t\t\t\t\t\ 6. Update contact\n");
    printf("\t\t\t\t\t\ 7. Delete contact\n");
    printf("\t\t\t\t\t\ 0. Exit\n");
    printf(">> ");
}

//1. Show contacts list; = show();
void show(node *list){
    printf("\n-------------------------------------------------------------------------------------------------------------\n");
    list = list->next;
    if(list == NULL){
        printf("\nThere is no contract in the list\n\n");
        printf("\n-------------------------------------------------------------------------------------------------------------\n\n");
        return;
    }
    int i = 1;
    while(list != NULL){
        printf("\t\t [%d]----------\n", i);
        printf("\t\t Name: %s\n", list->name);
        printf("\t\t Phone: %s\n", list->phone);
        printf("\t\t Email: %s\n", list->email);
        list = list->next;
        i++;
    }
    printf("\n-------------------------------------------------------------------------------------------------------------\n\n");
    return;
}

//3. Call log
void call(node *list, node *log){
    node *temp = nameorlist(list);
    //Calling...

    printf("\t Calling %s", temp->name);
    printf(" -%s", temp->phone); Sleep(300);
    printf("."); Sleep(300);
    printf("."); Sleep(300);
    printf("."); Sleep(300);
    printf("\n\n");

    //Call log linked list;
    addtolog(log, temp->name, temp->phone, temp->email);
    printf("\t Number busy :(\n\n");
    Sleep(500);
}

//4. Speed dial;
void speeddial(node *list, node *log){
    speedid = 0;
    printf("\t 1. Call by speed dial\n");
    printf("\t 2. Add contact to speed dial\n");
    printf("\t >> ");
    int choice; int n;
    node *temp;
    scanf("%d", &choice);
    switch(choice){
        case 1:{
            printf("\t Press the key\n");
            printf("\t >> ");
            scanf("%d", &n);
            if(speed[n] != 0){
                temp = searchbyid(list, speed[n]);
                printf("\t %s -", temp->name); Sleep(300);
                printf(" %s\n\n", temp->phone);
                printf("\t Calling %s -", temp->name); Sleep(300);
                printf("."); Sleep(300); printf("."); Sleep(300); printf("."); Sleep(300);
                //Call log linked list;
                addtolog(log, temp->name, temp->phone, temp->email);
                printf("\t Number busy :(\n\n");
                Sleep(500);
            }
            else{
                printf("\t No number was assigned with this key\n\n");
            }
            break;
        }
        case 2:{
            printf("\t Please enter the key you want to assign number with(0-9)\n");
            printf("\t >> ");
            scanf("%d", &n);
            temp = nameorlist(list);
            speed[n] = speedid;
            printf("\t %s is assinged to key %d\n\n", temp->name, n);
            break;
        }
    }
    speedid = 0;
}

//5. Add a new contact = add;
void add(node *list, char name[], char phone[], char email[]){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    strcpy(temp->email, email);
    temp->next = NULL;

    while(list->next != NULL){
        list = list->next;
    }
    list->next = temp;
    return;
}

//3. add to log
void addtolog(node *list, char name[], char phone[], char email[]){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    strcpy(temp->email, email);
    temp->next = NULL;

    temp->next = list->next;
    list->next = temp;
    return;
}
//search node by name;
node *searchbyname(node *list, char name[]){
    speedid--;
    list = list->next;
    if(list == NULL){
        printf("\nThere is no contract in the list\n");
        return NULL;
    }
    while(strcmp(list->name, name) != 0){
        list = list->next;
        speedid++;
    }
    return list;
}

//search by id;
node *searchbyid(node *list, int n){
    for(int i = 0; i < n; i++){
        list = list->next;
        speedid++;
    }
    return list;
}

//Search or show the list;
node *nameorlist(node *list){
    printf("\t 1. Search by name\n");
    printf("\t 2. Show list\n");
    printf("\t >> ");

    int choice;
    node *temp;
    scanf("%d", &choice);
    switch(choice){
        // if user choosed search by name update option;
        case 1:{
            char name[100];
            printf("\tPlease enter the name: ");
            scanf(" %[^\n]", name);
            temp = searchbyname(list, name);
            printf("\n");
            break;
        }
        case 2:{
            show(list);
            printf("\tPlease choose the id of contact: ");
            int n;
            scanf("%d", &n);
            temp = searchbyid(list, n);
            printf("\n");
            break;
        }
    }
    return temp;
}

//6. Update contact;
void update(node *list){
    node *temp = nameorlist(list);
    if(temp == NULL){
        printf("\t Contact could not found\n\n");
    }
    printf("\tContact To be edited\n\n");
    printnode(temp);
    printf("\t 1. Change name\n");
    printf("\t 2. Change phone\n");
    printf("\t 3. Change email\n");
    printf("\t >> ");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:{
            printf("\t Enter new name: ");
            char name[100]; scanf(" %[^\n]", name);
            strcpy(temp->name, name);
            break;
        }
        case 2:{
            printf("\t Enter new phone number: ");
            char phone[100]; scanf(" %[^\n]", phone);
            strcpy(temp->phone, phone);
            break;
        }
        case 3:{
            printf("\t Enter new email: ");
            char email[100]; scanf(" %[^\n]", email);
            strcpy(temp->email, email);
            break;
        }
    }
    printf("\t Contract updated successfully...\n\n");
}

void del(node *list){
    node *temp = nameorlist(list);
    printf("\tContact To be deleted\n\n");
    printnode(temp);
    printf("proceed? (y/n): ");
    char ch; scanf(" %c", &ch);
    if(ch == 'y'){
        while(strcmp(list->next->name, temp->name) != 0){
            list = list->next;
        }
        node *temp2 = list->next;
        list->next = list->next->next;
        free(temp2);
        printf("\t Contract deleted successfully...\n\n");
    }
    else if(ch == 'n'){
        printf("\t Contract was not deleted...\n\n");
        return;
    }
}

//prints the node passed to it;
void printnode(node *temp){
    printf("\tName: %s\n", temp->name);
    printf("\tPhone: %s\n", temp->phone);
    printf("\tEmail: %s\n", temp->email);
    printf("\n");
}


int main(){
    system("color F9");
    welcome();
    Sleep(2000);
    system("cls");
    //creating dummy node;
    node *list = (node *)malloc(sizeof(node));
    list->next = NULL;
    //crating dummy node for log list;
    node *log = (node *)malloc(sizeof(node));
    log->next = NULL;
    //showing the menu;
    while(true){
        menu();
        int choice;
        scanf("%d", &choice);
        switch(choice){
        case 1:
            show(list);
            break;
        case 2: //2. Call
            call(list, log);
            break;
        case 3: //3. Call log
            printf("Call log.\n");
            show(log);
            break;
        case 4://4. Speed dial
            speeddial(list, log);
            break;
        case 5: //Add new contract
            char name[100]; char phone[100]; char email[100];
            printf("\t Name: ");  scanf(" %[^\n]", name);
            printf("\t Phone: "); scanf(" %[^\n]", phone);
            printf("\t Email: "); scanf(" %[^\n]", email);
            add(list, name, phone, email);
            printf("\t Contact Saved Successfully...\n\n");
            break;
        case 6: //Update
            update(list);
            break;
        case 7: //Delete contact
            del(list);
            break;
        case 0:
            return 0;
            break;
        }
    }
    return 0;
}
