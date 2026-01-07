#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Book {
    int id;
    char name[50];
    char author[50];
    char category[30];
    float price;
    float rating;
};

struct Book *b;
int count = 0;
int capacity = 0;


/* Add Book */
void addBook() {
    if (count == capacity) {
        capacity += 5;
        b = (struct Book *)realloc(b, capacity * sizeof(struct Book));

        if (b == NULL) {
            printf("Memory reallocation failed!\n");
            return;
        }
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &b[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b[count].author);

    printf("Enter Category: ");
    scanf(" %[^\n]", b[count].category);

    printf("Enter Price: ");
    scanf("%f", &b[count].price);

    printf("Enter Rating: ");
    scanf("%f", &b[count].rating);

    count++;
    printf("\nBook added successfully!\n");
}

/* Remove Book */
void removeBook() {
    int id, i, found = 0;
    printf("\nEnter Book ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (b[i].id == id) {
            b[i] = b[count - 1];
            count--;
            found = 1;
            break;
        }
    }

    if (found)
        printf("Book removed successfully!\n");
    else
        printf("Book not found!\n");
}

void searchBookByName(struct Book b[], int n)
{
    char searchName[50];
    int found = 0;

    printf("Enter book name (or part of name): ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < n; i++)
    {
        if(strstr(b[i].name, searchName) != NULL)
        {
            printf("\nBook Found:");
            printf("\nID: %d", b[i].id);
            printf("\nName: %s", b[i].name);
            printf("\nAuthor: %s", b[i].author);
            printf("\nCategory: %s", b[i].category);
            printf("\nPrice: %.2f", b[i].price);
            printf("\nRating: %.1f\n", b[i].rating);
            found = 1;
        }
    }

    if(!found)
    {
        printf("\nNo book found with this name.\n");
    }
}



/* Show Author Books */
void showAuthorBooks() {
    char author[50];
    int found = 0;

    printf("\nEnter Author Name: ");
    scanf(" %[^\n]", author);

    for (int i = 0; i < count; i++) {
        if (strcmp(b[i].author, author) == 0) {
            printf("%d %s %.2f %.2f\n",
                   b[i].id, b[i].name, b[i].price, b[i].rating);
            found = 1;
        }
    }

    if (!found)
        printf("No books found for this author!\n");
}

/* Show Category Books */
void showCategoryBooks() {
    char category[30];
    int found = 0;

    printf("\nEnter Category: ");
    scanf(" %[^\n]", category);

    for (int i = 0; i < count; i++) {
        if (strcmp(b[i].category, category) == 0) {
            printf("%d %s %.2f %.2f\n",
                   b[i].id, b[i].name, b[i].price, b[i].rating);
            found = 1;
        }
    }

    if (!found)
        printf("No books found in this category!\n");
}

/* Update Book */
void updateBook() {
    int id;
    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (b[i].id == id) {
            printf("Enter new Price: ");
            scanf("%f", &b[i].price);

            printf("Enter new Rating: ");
            scanf("%f", &b[i].rating);

            printf("Book updated successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

/* Display Top 3 Books */
void displayTopBooks() {
    struct Book temp;

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (b[i].price < b[j].price) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("\nTop 3 Books by Price:\n");
    for (int i = 0; i < count && i < 3; i++) {
        printf("%s - %.2f\n", b[i].name, b[i].price);
    }

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (b[i].rating < b[j].rating) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("\nTop 3 Books by Rating:\n");
    for (int i = 0; i < count && i < 3; i++) {
        printf("%s - %.2f\n", b[i].name, b[i].rating);
    }
}

/* Display All Books */
void displayAllBooks() {
    if (count == 0) {
        printf("\nNo books available!\n");
        return;
    }

    printf("\nAll Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s %s %s %.2f %.2f\n",
               b[i].id, b[i].name, b[i].author,
               b[i].category, b[i].price, b[i].rating);
    }
}

/* Main Function */


int main() {
    int choice;

    capacity = 5;   // initial capacity
    b = (struct Book *)malloc(capacity * sizeof(struct Book));

    if (b == NULL) {
     printf("Memory allocation failed!\n");
     return 1;
    }


    do {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Show Author Books\n");
        printf("5. Show Category Books\n");
        printf("6. Update Book\n");
        printf("7. Display Top Books\n");
        printf("8. Display All Books\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: addBook(); break;
        case 2: removeBook(); break;
        case 3: searchBookByName(b, count); break;
        case 4: showAuthorBooks(); break;
        case 5: showCategoryBooks(); break;
        case 6: updateBook(); break;
        case 7: displayTopBooks(); break;
        case 8: displayAllBooks(); break;
        case 9: printf("Exiting program...\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 9);

    free(b);
    return 0;
}
