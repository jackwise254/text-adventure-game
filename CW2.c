#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

int get_room(room) {

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


    if(room <=13){

        // conditions to check room and perfom neccessary action

        if(room == 2){
            food += 5;
            health += 5;
            printf("You gained +5 health and +5 food\n");
            return main();
        }


        else if (room == 3)

        {
            /* code */
            zombie += 5;
            // a while  loop to make sure all zombies are killed before moving to the next step
            while(zombie >= 1){
                printf("You are under attack by zombies, type Kill Zombie to attack \n");
                return main();
            }
        }


        else if (room == 4)
        {
            health += 10;
            medpack += 10;
            printf("You gained +10 medpack and +10 health\n");
            return main();

        }
        

        else if (room == 5)
        {
            warewolf += 12;
            // check if warewolf has health greater than 0
            while (warewolf >= 1)
            {
                printf("You are under attack by warewolf, type kill warewolf to attack \n");
                return main();
            }
        }


        else if (room == 6)
        {
            monster += 4;
            while (monster>=1)
            {
                printf("There's a monster and a sword in this room, type killMonster to attack \n");
                return main();
            }
        }

        else if (room == 7)
        {
            dracula += 12;
            while (dracula >= 1)
            {
                printf("There's a dracula and a coper key in this room, type dracula to attack \n");
                return main();
            }
        }

        else if (room == 8)
        {
            printf("You have a chance to collect an bronze key, type bronze to colect \n");

        }

        else if (room == 9)
        {
            /* code */
            printf("You have a chance to collect +10 health and elixir, type get elixir to collect \n");
        }

        else if (room ==10)
        {
          while (locked == true)
           {    
                if (strcmp(command, "unlock door\n") == 0) {

                    if(bronze_key>=1){
                        locked = false;
                        return main();
                    }
                    else{
                        printf("You don't have bronze keys to access this room\n");
                        return main();
                        
                    }
                }
                else{
                    printf("You can't access this room, use bronze keys to unlock\n");
                    return main();
                }
                
            }
            lizard_man += 5;

            while (lizard_man >=1)
            {
                printf("You are under attack by lizard-man type lizard to attack and collect a diamond cross \n");
                return main();
            }
        }

        else if (room ==11)
        {
            bride_of_dracula += 7;
            while (bride_of_dracula >= 1)
            {
                printf("You are under attack by bride of dracula, type bride to react \n");
                return main();
            }
        }

        else if (room == 12)
        {
            printf("You have a chance to collect a silver spear, type get sword to collect \n");
           
        }
        else if (room == 13)
        {
            while (locked_13 == true)
           {
                if (strcmp(command, "unlock door\n") == 0) {

                    if(copper_key>=1){
                        locked = false;
                        return main();
                    }
                    else{
                        printf("You don't have copper keys to access this room\n");
                        return main();
                        
                    }
                }
                else{
                    printf("You can't access this room, use copper keys to unlock\n");
                    return main();
                }
            }

            dragon += 12;
            while (dragon >=1)
            {

                printf("You are in a room with 12 dragons and a golden chalice, type kill dragon to attack and collect \n");
                return main();
            }
        }
        return main();

    }


    else{
        printf("You're in the last room of this dangeon.\n", food);
        return 0;
    }
        // Handle the player's choice
    }

}


// Function to process the command entered by the user
// and return the next room number
int processCommand(char* command) {
  // Check if the user entered the "quit" command
  if (strcmp(command, "exit\n") == 0) {
    return 0; // Signal to exit the game

  }

  // Check if the user entered the "go north" command
  if (strcmp(command, "north\n") == 0  || strcmp(command, "n\n") == 0) {
    // Change the room number to the north room
    if (room==6 || room ==8 ||room==9 || room==10){
        room -= 5;
        return get_room(room);

    }
    else if (room==11 || room == 12)
    {
        room -= 4;  
        return get_room(room);
    }
    else{
        printf("You can't go there.\n");
        return main();
    }


  }

  // Check if the user entered the "go east" command
  if (strcmp(command, "east\n") == 0  || strcmp(command, "e\n") == 0) {
    // Change the room number to the north room
    room += 1;
    return get_room(room);
    // Change the room number to the north room
    if (room >= 13){
        printf("You can't go there.\n");
        return main();
    }
    else{
        return get_room(room);
    }

  }

  // Check if the user entered the "go west" command
  if (strcmp(command, "west\n") == 0  || strcmp(command, "w\n") == 0) {
    // Change the room number to the north room
    if (room <=0){
        printf("You can't go there.\n");
        return 0;
    }
    else{
        room -= 1;
        return get_room(room);
    }
  }


// Check if the user entered the "go south" command
  if (strcmp(command, "south\n") == 0 || strcmp(command, "s\n") == 0) {
    // Change the room number to the south room
    if (room==1 || room==3 || room ==4 || room==5){
        room += 5;
        return get_room(room);

    }
    else if (room==7 || room == 8)
    {
        room+= 4;  
        return get_room(room);
    }
    

    else{
        printf("You can't go there.\n");
        return main();
    }

  }


  // Check if the user entered the " look" command
  if (strcmp(command, "look\n") == 0 || strcmp(command, "1\n") == 0) {
    // return the room where the player is currently in
    return get_room(room);

  }


// attacking commands.
    // attacking zombie

  if (strcmp(command, "Kill Zombie\n") == 0) {

    if(room == 3){
        int attack = rand() % 5 + 1;
        health -= 3;
        printf("You attacked the zombie and dealt with %d damage.\n", attack);
        if (zombie - attack <= 0)
        {
            printf("You killed the zombie!\n");
            zombie = 0;
        }
        else
        {
            zombie -= attack;
            printf("Your health is %d, zombie's energy is %d, repeat the command\n", health, zombie);
        }
    }
    else{
        printf("There's no zombies here, use movement commands to go to the next room!\n");
    }

  }

    // attacking warewolf
  if (strcmp(command, "kill warewolf\n") == 0) {

    if(room==5){
        int attack = rand() % 5 + 1;
        health -= 3;

        printf("You attacked the warewolf and dealt with %d damage.\n", attack);
        if (warewolf - attack <= 0)
        {
            printf("You killed the warewolf!\n");
            warewolf = 0;
        }
        else
        {
            warewolf -= attack;
            printf("Your health is %d, warewolf's energy is %d, repeat the command\n", health, warewolf);

        }
    }
    else{
        printf("There's no warewolfs here, use movement commands to go to the next room!\n");
    }

  }


    // attacking dragon
  if (strcmp(command, "kill dragon\n") == 0) {

    if(room==13){
        while (locked_13 == "True")
        {
            printf("You can't access this room, use copper keys to unlock\n");
            return main();
        }
        
        int attack = rand() % 5 + 1;
        health -= 3;

        printf("You attacked the dragon and dealt with %d damage.\n", attack);
        if (dragon - attack <= 0)
        {
            printf("You killed the dragon!\n");
            dragon = 0;
        }
        else
        {
            dragon -= attack;
            printf("Your health is %d, dragon's energy is %d, repeat the command\n", health, dragon);

        }
    }
    else{
        printf("There's no dragons here, use movement commands to go to the next room!\n");
    }

  }


    // attacking monster
  if (strcmp(command, "killMonster\n") == 0 || strcmp(command, "killmonster\n") == 0 || strcmp(command, "km\n") == 0) {

    if(room==6){
        int attack = rand() % 5 + 1;
        health -= 3;
        printf("You attacked the monster and dealt with %d damage.\n", attack);
        if (monster - attack <= 0)
        {
            printf("You killed the monster!\n");
            monster = 0;
        }
        else
        {
            monster -= attack;
            printf("Your health is %d, monster's energy is %d, repeat the command\n", health, monster);

        }
    }
    else{
        printf("There's no monsters here, use movement commands to go to the next room!\n");
    }

  }


  // attacking dracula
  if (strcmp(command, "dracula\n") == 0) {

    if(room==7){
        int attack = rand() % 5 + 1;
        health -= 3;

        printf("You attacked the dracula and dealt with %d damage.\n", attack);
        if (dracula - attack <= 0)
        {
            printf("You killed the dracula!\n");
            dracula = 0;
        }
        else
        {
            dracula -= attack;
            printf("Your health is %d, dracula's energy is %d, repeat the command\n", health, dracula);

        }
    }

    else{
        printf("There's no draculas here, use movement commands to go to the next room!\n\n");
    }

  }


// collecting bronze key
  if (strcmp(command, "bronze\n") == 0) {
    if (room == 8){
        if(bronze_key <=1){
        bronze_key += 1;
        printf("You collected %d bronze keys.\n", bronze_key);
        return main();

        }
        else{
            printf("You cannot collect more than 1 bronze keys!\n");
            return main();
        }

    }else{
        printf("There is no bronze key in this room, move to the next room!\n!\n");
        return main();
    }

    

  }


// collecting elixir
  if (strcmp(command, "get elixir\n") == 0) {
    if (room == 9){
        if(elixir <=1){
            elixir += 1;
            health += 10;
            printf("You collected %d elixir and +10 health.\n", elixir);
            return main();

        }
        else{
            printf("You cannot collect more than 1 elixir!");
            return main();
        }

    }else{
        printf("There is no elixir in this room, move to the next room!\n!\n");
        return main();
    }
    

  }

   // attacking lizard
  if (strcmp(command, "lizard\n") == 0) {

    if(room==10){
        
        int attack = rand() % 5 + 1;
        health -= 3;

        printf("You attacked the dragon and dealt with %d damage.\n", attack);
        if (lizard_man - attack <= 0)
        {
            printf("You killed the dragon!\n");
            lizard_man = 0;
        }
        else
        {
            lizard_man -= attack;
        }
    }
    else{
        printf("There's no lizard man in this room!\n");
        return main();

    }

  }

//   inventory


 if (strcmp(command, "inventory\n") == 0 || strcmp(command, "i\n") == 0) {

    printf("\n*** Inventory list ***\n");
    printf("Health: %d\n", health);
    printf("Food: %d\n", food);
    printf("Medpack: %d\n", medpack);
    printf("Elixir: %d\n", elixir);
    printf("Current room: %d\n", room);

    return main();

  }


   // eating food
  if (strcmp(command, "eat food\n") == 0) {

    if(food>=5){
        food -= 5;
        health += 10;

        printf("You gained +10 health, you've %d health\n", health);
        return main();

    }
    else{
        printf("You've no food or medpack left to use\n");
        return main();
    }

  }



 // use medpack
  if (strcmp(command, "use medpack\n") == 0) {

    if(medpack>=5){
        medpack -= 5;
        health += 10;

        printf("You gained +10 health, you've %d health\n", health);
        return main();

    }
    else{
        printf("You've no medpack left to use\n");
        return main();
    }

  }


     // drinking elixir
  if (strcmp(command, "drink elixir\n") == 0) {

    if(elixir>=1){
        elixir -= 1;
        health += 10;
        printf("You gained +10 health, you've %d health\n", health);
        return main();

    }
    else{
        printf("You've no elixir left to use\n");
        return main();
    }

  }

  


 // attacking bride_of_dracula
  if (strcmp(command, "bride\n") == 0) {

    if(room==11){
        health -= 3;

        int attack = rand() % 5 + 1;
        printf("You attacked the dragon and dealt with %d damage.\n", attack);
        if (bride_of_dracula - attack <= 0)
        {
            printf("You killed the bride of dracula!\n");
            bride_of_dracula = 0;
        }
        else
        {
            bride_of_dracula -= attack;
        }
    }
    else{
        printf("There's no bride of dracula in this room!\n");
        return main();

    }

  }

  


// collecting silver  spear
  if (strcmp(command, "get sword\n") == 0 || strcmp(command, "get Sword\n") == 0) {
    if (room == 12){

        if(silver_spear <=1){
        silver_spear += 1;
        printf("You collected %d silver spear.\n", silver_spear);
        return main();

        }
        else{
            printf("You cannot collect more than 1 silver spears!\n");
            return main();
        }

    }else{
        printf("There is no silver spear in this room, move to the next room!\n!\n");
        return main();
    }

  }

//   unlocking door

  if (strcmp(command, "unlock door\n") == 0) {

    if(room ==10){
        if(bronze_key>=1){
            locked = false;
            return main();
        }
        else{
            printf("You don't have bronze keys to access this room\n");
            return main();
            
        }
    }
    else if (room == 13)
    {
        if(copper_key>=1){
            locked_13 = false;
            return main();

        }
        else{
            printf("You don't have copper keys to access this room\n");
            return main();

        }
    }
    else{
        printf("Current room is not locked\n");
            return main();

    }

  }

  // Check if the user entered the " help" command
  if (strcmp(command, "help\n") == 0) {

        printf("\n***Commands List***\n");
        printf("\n1. Direction commands: north, n, south, s, east, e, west, w\n");

        printf("\n2. Look Command : look, 1\n");

        printf("\n3. Fight commands: killMonster, killmonster, km \n");

        printf("\n4. Alternate commands: Kill Zombie, kill warewolf, kill dragon\n");

        printf("\n5. Get commands: get diamond cross, get sword, get Sword, get elixir\n");

        printf("\n6. Drop copper key, drop food, drop golden chalice.\n");

        printf("\n7. Inventory Command: inventory, i.\n");

        printf("\n8. Healing commands: eat food, drink elixir, use medpack\n");

        printf("\n9. Unlockin door: unlock door\n");

        printf("\n10.  exit\n");

        return 0;

  }

  if (strcmp(command, "Drop copper key\n") == 0) {
    if(copper_key>=1){
        copper_key=0;
        return main();
    }
    else{
        printf("You don't have copper key\n");
        return main();
    }

  }

  if (strcmp(command, "drop food\n") == 0) {
    if(food>=1){
        food=0;
        return main();
    }
    else{
        printf("You don't have food\n");
        return main();
    }

  }

  if (strcmp(command, "drop golden chalice\n") == 0) {
    if(golden_chalice>=1){
        golden_chalice=0;
        return main();
    }
    else{
        printf("You don't have golden chalice\n");
        return main();
    }

  }

    else{
        printf("Invalid command, kindly refer to the manual\n");
        return main();
    }

  // Return 1 to indicate that the game should continue
  return 1;
}


