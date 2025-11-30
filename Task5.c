#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 50

struct Player {
    char name[50];
    int age;
    char position[50];
};

struct Team {
    char teamName[50];
    char sport[50];
    struct Player players[MAX_PLAYERS];
    int playerCount;
};

void addPlayer(struct Team *t) {
    if (t->playerCount >= MAX_PLAYERS) {
        printf("\nCannot add more players. Team is full.\n");
        return;
    }

    printf("\nEnter Player Name: ");
    scanf(" %[^\n]", t->players[t->playerCount].name);

    printf("Enter Player Age: ");
    scanf("%d", &t->players[t->playerCount].age);

    printf("Enter Player Position: ");
    scanf(" %[^\n]", t->players[t->playerCount].position);

    t->playerCount++;

    printf("\nPlayer added successfully!\n");
}

void searchByPosition(struct Team *t) {
    char searchPos[50];
    int found = 0;
	int i;
    printf("\nEnter Position to Search: ");
    scanf(" %[^\n]", searchPos);

    printf("\nPlayers with Position '%s':\n", searchPos);

    for (i= 0;i< t->playerCount; i++) {
        if (strcmp(t->players[i].position, searchPos) == 0) {
            printf("Name: %s, Age: %d\n",
                   t->players[i].name,
                   t->players[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("No players found with this position.\n");
    }
}

void displayTeam(struct Team *t) {
    printf("\n===== TEAM DETAILS =====\n");
    printf("Team Name: %s\n", t->teamName);
    printf("Sport: %s\n", t->sport);
int i;
    printf("\n--- Players ---\n");
    for (i=0;i< t->playerCount; i++) {
        printf("Player %d:\n", i + 1);
        printf("  Name: %s\n", t->players[i].name);
        printf("  Age: %d\n", t->players[i].age);
        printf("  Position: %s\n", t->players[i].position);
    }
}

int main() {
    struct Team t;
    t.playerCount = 0;

    int choice;

    printf("Enter Team Name: ");
    scanf(" %[^\n]", t.teamName);

    printf("Enter Sport: ");
    scanf(" %[^\n]", t.sport);

    do {
        printf("\n==== MENU ====\n");
        printf("1. Add Player\n");
        printf("2. Search Player by Position\n");
        printf("3. Display Team Details\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer(&t);
                break;

            case 2:
                searchByPosition(&t);
                break;

            case 3:
                displayTeam(&t);
                break;

            case 4:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}

