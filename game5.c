#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "CW2.c"

int main() {
    // Define variables for the game
    int health = 12;
    int room = 1;
    int food = 0;
    int medpack = 0;
    int sword = 0;
    int copper_key = 0;
    int bronze_key = 0;
    int elixir = 0;
    int diamond_cross = 0;
    int silver_spear = 0;
    int golden_chalice = 0;
    int zombie = 0;
    int warewolf = 0;
    int monster = 0;
    int dracula = 0;
    int lizard_man = 0;
    int bride_of_dracula = 0;
    int dragon = 0;
    int game = 1;
    // Initialize the starting room number

    char command[1000];

    printf("Welcome to the text adventure game!\n");
    printf("You are in a dungeon with 13 rooms. Each room contains a different challenge.\n");
    printf("Your goal is to collect all the items and defeat all the enemies to win the game.\n");

    printf("What do you want to do?\n");
    printf("1. Move to the next room press north, south, east, west\n");
    printf("2. Help\n");
    printf("3. Alternate kill zombie, kill werewolf, kill dragon\n");
    printf("3. Drop copper key, drop food, drop golden chalice.\n");
    printf("3. Drop copper key, drop food, drop golden chalice.\n");
    printf("3. Healing commands eat food, drink elixir, use medpack\n");
    printf("4. Attack enemy, killMonster,killmonster,km\n");
    printf("5. Get diamond cross, get sword, get Sword, get elixir\n");
    printf("6.  exit\n");

    while (fgets(command, 1000, stdin)) {
        // Process the command entered by the user
        if (processCommand(command, &room) == 0) break;
        // Print the current room description
        printf("You are in room %d.\n", room);

        while (game >= 1)
    {
        // Print the current room and the player's health
        printf("\nYou are in room %d. Your health is %d.\n", room, health);

        // Check if the player has won the game
        if (room == 13 && food >= 1 && medpack >= 1 && sword >= 1 && copper_key >= 1 && bronze_key >= 1 && elixir >= 1 && diamond_cross >= 1 && silver_spear >= 1 && golden_chalice >= 1)
        {
            printf("\nCongratulations, you have won the game with %d health!\n", health);
            break;
            game = 0;
        }


        // Check if the player has died
        if (health <= 0)
        {
            printf("\nSorry, you lost the game.\n");
            break;
        }


        // Print the options for the current room
        printf("What do you want to do?\n");
        printf("1. Move to the next room press n(north), s(south), e(east), w(west)\n");
        printf("2. Help\n");
        printf("3. Alternate kill zombie, kill werewolf, kill dragon\n");
        printf("3. Drop copper key, drop food, drop golden chalice.\n");
        printf("3. Drop copper key, drop food, drop golden chalice.\n");
        printf("3. Healing commands eat food, drink elixir, use medpack\n");
        printf("4. Attack enemy, killMonster,killmonster,km\n");
        printf("5. Get diamond cross, get sword, get Sword, get elixir\n");
        printf("6. Exit game exit\n");

        // Get the player's choice
        int choice;
        scanf("%d", &choice);

        // Handle the player's choice
        switch (choice)
        {
            case 1:
                // Move to the next room
                if(room <=13){

                    // conditions to check room and perfom neccessary action
                    room++;

                    if(room == 2){

                        food += 5;
                        health += 5;

                        printf("You gained +5 health and +5 food");
                    }


                    else if (room == 3)

                    {
                        /* code */
                        zombie += 5;
                        // a while  loop to make sure all zombies are killed before moving to the next step
                        while(zombie >= 1){

                            printf("You are under attack by zombies, press 3 to attack \n");

                            int choice;
                            scanf("%d", &choice);
                            // checking users choice to perform necessary action
                            if(choice == 3){

                                int attack = rand() % 5 + 1;

                                printf("You attacked the zombie and dealt with %d damage.\n", attack);
                                if (zombie - attack <= 0)
                                {
                                    printf("You killed the zombie!\n");
                                    zombie = 0;
                                }
                                else
                                {
                                    zombie -= attack;
                                }
                            }
                            // user loses +10 health for entering invalid command
                            else{
                                health -= 5;
                                // check if the player still has health
                                if (health <= 0)
                                {
                                    printf("\nSorry, you lost the game.\n");
                                    break;
                                }
                            }

                        }
                        

                    }


                    else if (room == 4)
                    {
                        health += 10;
                        medpack += 10;
                        printf("You gained +10 medpack and +10 health");

                    }
                    

                    else if (room == 5)
                    {
                        warewolf += 12;
                        // check if warewolf has health greater than 0
                        while (warewolf >= 1)
                        {
                            printf("You are under attack by warewolf, press 5 to attack \n");

                            int choice;
                            scanf("%d", &choice);

                            if (choice != 5){
                                health -= 5;

                                if (health <= 0)
                                {
                                    printf("\nSorry, you lost the game.\n");
                                    break;
                                }
                            }

                            else{

                            int attack = rand() % 12 + 1;
                            printf("You attacked the warewolf and dealt with %d damage.\n", attack);
                            warewolf -= attack;
                            }
                        }
                    }


                    else if (room == 6)
                    {
                        monster += 4;

                        while (monster>=1)
                        {
                            printf("There's a monster and a sword in this room, press 6 to attack \n");
                            int choice;
                            scanf("%d", &choice);
                            if (choice==6){
                                sword += 1;
                                int attack = rand() % 4 + 1;
                                printf("You attacked a monster and deaalt with %d gained and gained +5 health and a sword.\n", attack);
                                monster -= attack;

                            }
                            else{
                                health -= 5;

                                if (health <= 0)
                                {
                                    printf("\nSorry, you lost the game.\n");
                                    break;
                                }
                            }
                        }



                    }

                    else if (room == 7)
                    {
                        printf("There's a dracula and a coper key in this room, press 7 to attack \n");
                        dracula += 12;

                        while (dracula >= 1)
                        {
                            int choice;
                            scanf("%d", &choice);
                            if (choice==7){
                                copper_key += 1;
                                int attack = rand() % 4 + 1;
                                printf("You attacked the draculas and dealt with %d damage and gained a sword.\n", attack);
                                dracula -= attack;

                            }
                            else{
                                health -= 5;
                                if (health <= 0)
                                {
                                    printf("\nSorry, you lost the game.\n");
                                    break;
                                }
                            }

                            printf(" %d of dracula's health remaining.\n", dracula);

                        }

                    }

                    else if (room == 8)
                    {
                        printf("You have a chance to collect an bronze key, press 8 to collect \n");
                        int choice;
                        scanf("%d", &choice);
                        if (choice==8){
                            bronze_key += 1;
                            printf("You collected %d bronze keys.\n", bronze_key);
                        }

                    }

                    else if (room == 9)
                    {
                        /* code */
                        printf("You have a chance to collect +10 health and elixir, press 9 to collect \n");
                        int choice;
                        scanf("%d", &choice);
                        if (choice==9){
                            health += 10;
                            elixir += 1;
                            printf("You collected %d elixir and gained +10 health.\n", elixir);

                        }
                    }

                    else if (room ==10)
                    {
                        lizard_man += 5;

                        while (lizard_man >=1)
                        {
                            printf("You are under attack by lizard-man press 10 to attack and collect a diamond cross \n");
                            int choice;
                            scanf("%d", &choice);
                            if (choice==10){
                                diamond_cross += 1;
                                int attack = rand() % 5 + 1;
                                printf("You collected %d diamond cross and dealt with %d damage.\n", elixir, attack);
                                lizard_man -= attack;
                            }
                            else{
                                health -= 5;
                                if (health <= 0)
                                {
                                    printf("\nSorry, you lost the game.\n");
                                    break;
                                }
                            }


                        }
                        

                        
                    }

                    else if (room ==11)
                    {
                        bride_of_dracula += 7;
                        while (bride_of_dracula >= 1)
                        {
                            printf("You are under attack by bride of dracula, press 11 to react \n");

                            int choice;
                            scanf("%d", &choice);
                            if (choice==11){

                                int attack = rand() % 7 + 1;
                                printf("You attacked the brides of Dracula and killed %d of them.\n", attack);
                                bride_of_dracula -= attack;
                            }
                            else{
                                health -= 5;
                                if (health <= 0)
                                {
                                    printf("\nSorry, you lost the game.\n");
                                    break;
                                }
                            }

                        }
                    }

                    else if (room == 12)
                    {
                        printf("You have a chance to collect a silver spear, press 12 to collect \n");
                        int choice;
                        scanf("%d", &choice);
                        if (choice==12){
                            silver_spear += 1;
                            printf("You collected %d silver spear.\n", silver_spear);
                        }
                    }
                    else if (room == 13)
                    {


                        dragon += 12;
                        while (dragon >=1)
                        {
                            printf("You are in a room with 12 dragons and a golden chalice, press 13 to attack and collect \n");

                            int choice;
                            scanf("%d", &choice);
                            if (choice==11){
                                golden_chalice += 1;


                                int attack = rand() % 12 + 1;
                                printf("You attacked 12 dragons and killed %d of them.\n", attack);
                                dragon - attack;
                            }
                        }
                    }

                }


                else{
                    printf("You're in the last room of this dangeon.\n", food);

                }
                break;

            case 2:
                printf("***List of commands*** \n");
                printf("1. Move to the next room press n(north), s(south), e(east), w(west)\n");
                printf("3. Alternate kill zombie, kill werewolf, kill dragon\n");
                printf("3. Drop copper key, drop food, drop golden chalice.\n");
                printf("3. Drop copper key, drop food, drop golden chalice.\n");
                printf("3. Healing commands eat food, drink elixir, use medpack\n");
                printf("4. Attack enemy, killMonster,killmonster,km\n");
                printf("5. Get diamond cross, get sword, get Sword, get elixir\n");
                printf("6. Exit game exit\n");
                printf("NB: You lose -5 health for entering invalid command at each stage");

                game = 0;

                break;

            case 3:
                // Check if the player has a medpack
                if (medpack > 0)
                {
                    // Increase the player's health
                    health += 20;
                    medpack--;

                    printf("You used some  and regained 20 health. You have %d medpack remaining.\n", medpack);
                }
                else
                {
                    printf("You don't have any medpack left.\n");
                }
                break;

            case 4:
                // Handle the player's choice to attack an enemy
                if (room == 3 && zombie == 0)
                {
                    // Attack the zombie
                    int attack = rand() % 20 + 1;
                    printf("You attacked the zombie and dealt with %d damage.\n", attack);

                    // Check if the zombie is dead
                    if (zombie - attack <= 0)
                    {
                        printf("You defeated the zombie!\n");
                        zombie = 0;
                    }
                    else
                    {
                        zombie -= attack;
                    }
                }
                else if (room == 5 && warewolf == 0)
                {
                    // Attack the warewolf
                    int attack = rand() % 20 + 1;
                    printf("You attacked the warewolf and dealt %d damage.\n", attack);

                    // Check if the warewolf is dead
                    if (warewolf - attack <= 0)
                    {
                        printf("You defeated the warewolf!\n");
                        warewolf = 0;
                    }
                    else
                    {
                        warewolf -= attack;
                    }
                }
                else if (room == 6 && monster == 0)
                {
                    // Attack the monster
                    int attack = rand() % 20 + 1;
                    printf("You attacked the monster and dealt with %d damage.\n", attack);

                    // Check if the monster is dead
                    if (monster - attack <= 0)
                    {
                        printf("You killed the monster!\n");
                        monster = 0;
                    }
                    else
                    {
                        monster -= attack;
                    }
                }
                else if (room == 7 && dracula == 0)
                {
                    // Attack Dracula
                    int attack = rand() % 20 + 1;
                    printf("You attacked Dracula and dealt %d damage.\n", attack);

                    // Check if Dracula is dead
                    if (dracula - attack <= 0)
                    {
                        printf("You defeated Dracula!\n");
                        dracula = 0;
                    }
                    else
                    {
                        dracula -= attack;
                    }
                }
                else if (room == 10 && lizard_man == 0)
                {
                    // Attack the lizard man
                    int attack = rand() % 20 + 1;
                    printf("You attacked the lizard man and dealt %d damage.\n", attack);

                    // Check if the lizard man is dead
                    if (lizard_man - attack <= 0)
                    {
                        printf("You defeated the lizard man!\n");
                        lizard_man = 0;
                    }
                    else
                    {
                        lizard_man -= attack;
                    }
                }
                else if (room == 11 && bride_of_dracula == 0)
                {
                    // Attack the bride of Dracula
                    int attack = rand() % 20 + 1;
                    printf("You attacked the bride of Dracula and dealt %d damage.\n", attack);

                    // Check if the bride of Dracula is dead
                    if (bride_of_dracula - attack <= 0)
                    {
                        printf("You defeated the bride of Dracula!\n");
                        bride_of_dracula = 0;
                    }
                    else
                    {
                        bride_of_dracula -= attack;
                    }
                }
            }
    }



    }

    return 0;
}
