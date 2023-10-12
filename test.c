#include <stdio.h>
#include <string.h>

#define client_LEN 100
#define client_NAME_LEN 33
#define client_PASSWORD_LEN 33

struct client
{
    char client_name[client_NAME_LEN];
    char client_password[client_PASSWORD_LEN];
}; // client type

struct client client[client_LEN]; // array type client
int client_number = 0;

int SignUp()
{

    if (client_number == client_LEN)
    {
        printf("Maximum number of client reached.\n");
        return 0;
    }

    struct client New_Client;

    printf("Enter username: ");

    scanf("%s", New_Client.client_name);

    printf("Enter password: ");
    scanf("%s", New_Client.client_password);

    for (int i = 0; i <= client_number; i++)
    {
        if (strcmp(New_Client.client_name, client[i].client_name) == 0)
        {
            printf("this client name Already exists\n");

            return 0;
        }
    }

    client[client_number] = New_Client;

    client_number++;

    printf("SignUP successful.\n");

} // A function responsible for the registration process

int login()
{
    char clientname[client_NAME_LEN];
    char clientpassword[client_PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", clientname);

    printf("Enter password: ");
    scanf("%s", clientpassword);

    for (int i = 0; i < client_number; i++)
    {
        if (strcmp(clientname, client[i].client_name) == 0 && strcmp(clientpassword, client[i].client_password) == 0)
        {
            printf("Login successful.\n");
            return 0;
        }
    }

    printf("Login failed please check username and password.\n");
    return 0;
} // A function responsible for the entry process

int main()
{
    int choice_number = 0;
    printf(" welcome to our system   .\n");

    while (choice_number == 0 || choice_number == 1 || choice_number == 2 || choice_number != 3)
    {
        printf("1=> Sign up to our system\n");
        printf("2=> Login\n");
        printf("3=> close\n");
        printf("please enter namber of this number: ");
        scanf("%d", &choice_number);

        switch (choice_number)
        {
        case 1:
            SignUp();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("close\n");
            break;
        default:
            printf("Invalid number. Please choice number from 1 to 3.\n");
            break;
        }
    }

    return 0;
}