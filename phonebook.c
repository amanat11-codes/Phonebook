#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LIMIT 100
#define NUMBER_LIMIT 15


typedef struct contact{
    char name[NAME_LIMIT];
    char number[NUMBER_LIMIT];
} Contact;

void createContact(char fname[50], FILE *fp);
int quit = 0;


int main(void)
{
    char fname[50];
    char name_tmp[NAME_LIMIT];
    char number_tmp[NUMBER_LIMIT];

    printf("Welcome! Enter the name of your phonebook: ");
    

    // name of phonebook
    fgets(fname, NAME_LIMIT, stdin);
    if (strchr(fname, '\n') != NULL)
    {
        *strchr(fname, '\n') = '\0';
    }    
    strcat(fname, ".csv");

    // check if file exists
    FILE *fp = fopen(fname, "a+");


    // Creating a new contact and appedning it to the csv file
    
    while(quit == 0)
    {
        createContact(fname, fp);
    }

    printf("Closing file. Exiting program...\n");
    fclose(fp);
    return 0;
    
}

void createContact(char fname[50], FILE *fp)
{
    Contact c;

    printf("Appending a new contact in %s... Enter q to quit\n", fname);
    printf("Enter name: ");
    fgets(c.name, NAME_LIMIT, stdin);
    
    if (c.name[0] == 'q')
    {
        quit = 1;
        return;
    }
    printf("Enter number: ");
    fgets(c.number, NUMBER_LIMIT, stdin);

    // replace '\n' with '\0'
    if (strchr(c.name, '\n') != NULL)
    {
        *(strchr(c.name, '\n')) = '\0';
    }

    if (strchr(c.number, '\n') != NULL)
    {
        *(strchr(c.number, '\n')) = '\0';
    }

    fprintf(fp, "%s,%s\n", c.name, c.number);
}