#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char *lines[MAX_LINES];
int lineCount = 0;

/* Function to display the document */
void displayDocument()
{
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Function to insert a new line */
void insertLine()
{
    int position;
    char text[MAX_LENGTH];
    int i;

    if (lineCount >= MAX_LINES)
    {
        printf("\nDocument is full.\n");
        return;
    }

    printf("Enter line number to insert: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    /* Shift lines down */
    for (i = lineCount; i >= position; i--)
    {
        lines[i] = lines[i - 1];
    }

    /* Allocate memory for new line */
    lines[position - 1] = malloc(strlen(text) + 1);

    if (lines[position - 1] == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(lines[position - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Function to delete a line */
void deleteLine()
{
    int position;
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Free memory of deleted line */
    free(lines[position - 1]);

    /* Shift remaining lines up */
    for (i = position - 1; i < lineCount - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Function to save document to a file */
void saveFile()
{
    char filename[100];
    FILE *file;
    int i;

    printf("Enter file name: ");
    scanf("%99s", filename);

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("File saved successfully.\n");
}

/* Function to load document from a file */
void loadFile()
{
    char filename[100];
    char text[MAX_LENGTH];
    FILE *file;

    int i;

    printf("Enter file name: ");
    scanf("%99s", filename);
    getchar();

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    /* Clear current document */
    for (i = 0; i < lineCount; i++)
    {
        free(lines[i]);
    }

    lineCount = 0;

    /* Read lines from file */
    while (fgets(text, MAX_LENGTH, file) != NULL &&
           lineCount < MAX_LINES)
    {
        text[strcspn(text, "\n")] = '\0';

        lines[lineCount] = malloc(strlen(text) + 1);

        if (lines[lineCount] == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        strcpy(lines[lineCount], text);

        lineCount++;
    }

    fclose(file);

    printf("File loaded successfully.\n");
}

/* Function to search for a word */
void searchText()
{
    char word[100];
    int found = 0;
    int i;

    getchar();

    printf("Enter word or phrase to search: ");
    fgets(word, 100, stdin);

    word[strcspn(word, "\n")] = '\0';

    if (strlen(word) == 0)
    {
        printf("Search text cannot be empty.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}

/* Function to display help */
void showHelp()
{
    printf("\n========== HELP ==========\n");

    printf("insert  - Insert a new line\n");
    printf("delete  - Delete a line\n");
    printf("display - Display the document\n");
    printf("save    - Save document to a file\n");
    printf("load    - Load document from a file\n");
    printf("search  - Search for a word or phrase\n");
    printf("help    - Show available commands\n");
    printf("exit    - Exit the editor\n");

    printf("==========================\n");
}

/* Main function */
int main()
{
    char command[20];

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR        \n");
    printf("=================================\n");

    printf("Type 'help' to see available commands.\n");

    while (1)
    {
        printf("\n> ");
        scanf("%19s", command);

        if (strcmp(command, "insert") == 0)
        {
            insertLine();
        }
        else if (strcmp(command, "delete") == 0)
        {
            deleteLine();
        }
        else if (strcmp(command, "display") == 0)
        {
            displayDocument();
        }
        else if (strcmp(command, "save") == 0)
        {
            saveFile();
        }
        else if (strcmp(command, "load") == 0)
        {
            loadFile();
        }
        else if (strcmp(command, "search") == 0)
        {
            searchText();
        }
        else if (strcmp(command, "help") == 0)
        {
            showHelp();
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    /* Free allocated memory before exiting */
    for (int i = 0; i < lineCount; i++)
    {
        free(lines[i]);
    }

    printf("\nEditor closed.\n");

    return 0;
}