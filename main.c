#include "CW2.h"
#include "CW2.c"
int main() {
	
    if (room <= 1){
        printf("Welcome to the text adventure game!\n");
        printf("You are in a dungeon with 13 rooms. Each room contains a different challenge.\n");
        printf("Your goal is to collect all the items and defeat all the enemies to win the game.\n");


        printf("\n1. Direction commands: north, n, south, s, east, e, west, w\n");

        printf("\n2. Look Command : look, 1\n");

        printf("\n3. Fight commands: killMonster, killmonster, km \n");

        printf("\n4. Alternate commands: Kill Zombie, kill warewolf, kill dragon\n");

        printf("\n5. Get commands: get diamond cross, get sword, get Sword, get alixir\n");

        printf("\n6. Drop copper key, drop food, drop golden chalice.\n");

        printf("\n7. Inventory Command: inventory, i.\n");

        printf("\n8. Healing commands: eat food, drink elixir, use medpack\n");

        printf("\n9. Unlockin door: unlock door\n");

        printf("\n10. Help\n");

        printf("\n11.  exit\n");

        
        // printf("\n3. Atatcking commands:warewolf, dragon, zombie, monster\n");



        // printf("\n6. Get Commands: silver, bronze,\n");


    }
// , int room
    while (fgets(command, 1000, stdin)) {
        // Process the command entered by the user
        if (processCommand(command) == 0) break;
        // Print the current room description

    }

    return 0;
}
