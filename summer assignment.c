#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

// Function to add a contact
void addContact() {
    if (count >= MAX) {
        printf("\nContact list is full!\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter Phone: ");
    scanf("%s", contacts[count].phone);

    printf("Enter Email: ");
    scanf("%s", contacts[count].email);

    count++;
    printf("\nContact added successfully!\n");
}

// Function to display contacts
void viewContacts() {
    if (count == 0) {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nContact %d\n", i + 1);
        printf("Name : %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
}

// Function to search contact
void searchContact() {
    char searchName[50];
    int found = 0;

    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\nContact Found!\n");
            printf("Name : %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nContact not found.\n");
}

// Function to delete contact
void deleteContact() {
    char deleteName[50];
    int found = 0;

    printf("\nEnter Name to Delete: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            found = 1;
            printf("\nContact deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nContact not found.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("\nThank you for using the Contact Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}