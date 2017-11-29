#include "corefiles.h"
#include "commands.h"
#include "adt.h"

#include <stdio.h>
#include <string.h>

boolean gameOver;

int main () {
    int n, m;
    char colors[] = {'R', 'B'};
    printf("Enter map size: ");
    scanf("%d %d", &n, &m);
    CreateMap(n, m);
    CreatePlayers(2, colors);
    CreateQueue(2);

    POINT coordinates[] = {{1, m-2}, {n-2, 1}};
    InitializeMap(2, coordinates, n*m/15);
    InitializePlayers(2, coordinates);
    InitializeQueue(2);

	EndTurn();
    PrintMap();
    printf("\n");

    char command[11];
    do {
        printf("Your input: ");
        scanf(" %s", command);
        if (!strcmp(command, "MOVE")) {
            Move(GetSelectedUnit());
        } else if (!strcmp(command, "UNDO")) {
            Undo();
        } else if (!strcmp(command, "CHANGE_UNIT")) {
            ChangeUnit(GetCurrentPlayer());
        } else if (!strcmp(command, "RECRUIT")) {
            RecruitUnit(GetCurrentPlayer(), GetSelectedUnit());
            MakeStackEmpty();
        } else if (!strcmp(command, "ATTACK")) {
            Attack(GetSelectedUnit());
            MakeStackEmpty();
        } else if (!strcmp(command, "MAP")) {
            PrintMap();
        } else if (!strcmp(command, "INFO")) {
            PrintInfoGame();
        } else if (!strcmp(command, "END_TURN")) {
            EndTurn();
            MakeStackEmpty();
        } else if (!strcmp(command, "SAVE")) {
            printf("We don't have save feature. Heckin' bamboozled.\n");
        } else {
            printf("Invalid input\n");
        }
    } while (strcmp(command, "EXIT"));

    return 0;
}
