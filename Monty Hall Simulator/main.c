#include <stdio.h>
#include <stdlib.h>

//These variables are for the game mode
int close, menu, prizeDoor, totalgames, wins, gamemode, research, doorChosen, falsedoor1, falsedoor2, numberOfDoors, finalChose;
//These variables are for the research mode
int selection, games, researchwins;
float totalgames2;
close = 1;
totalgames = 0;
wins = 0;


//Core of the program
int main()
{
    printf("Program by : Darren Bahadoor\n");
    printf("Student # : 8910771\n");
    printf("Professor : Dr.Fadi Malek\n");
    printf("\n");
    printf("\n");
    while (close) {
        printf("Monty Hall Game\n");
        printf("Enter one of the following options : \n");
        printf("1.  Game Mode\n");
        printf("2.  Research Mode\n");
        printf("3.  Exit\n");
        printf(": ");
        scanf("%i", &menu);
        if (menu == 1) {
            //Game mode
            gamemode = 1;
            GameMode(gamemode);
        } else if (menu == 2) {
            research = 1;
            ResearchMode(research);
        } else if (menu == 3) {
        printf("Exiting...");
        close = 0;
        }
    }

}
//Game related content goes here
int GameMode() {
     while (gamemode) {


        prizeDoor = rand()%(4 - 1) + 1;
        //end of the random
        printf("Total games : %i, Total Wins : %i\n", totalgames, wins);
        printf("There are three doors, 1, 2, and 3\n");
        printf("One of them has your dream car, while the other two have goats.\n");
        printf("Which door do you pick?\n");
        printf("                Door 1 = 1\n");
        printf("                Door 2 = 2\n");
        printf("                Door 3 = 3\n");
        printf("                Door # : ");
        scanf("%i", &doorChosen);
        printf("You chose door : %i\n", doorChosen);
        AssignOptionDoor(prizeDoor);
        if (falsedoor1 == doorChosen) {
        printf("However, door %i has been opened and it contains a goat which leaves door %i, would you like to switch?\n", falsedoor2, prizeDoor);
        printf("1 = Yes\n");
        printf("2 = No\n");
        scanf("%i", &finalChose);
        if (finalChose == 1) {
            doorChosen = prizeDoor;
        } else {
        //Do noting
        }
        } else if (falsedoor2 == doorChosen) {
        printf("However, door %i has been opened and it contains a goat which leaves door %i, would you like to switch?\n", falsedoor1, prizeDoor);
        printf("1 = Yes\n");
        printf("2 = No\n");
        scanf("%i", &finalChose);
        if (finalChose == 1) {
            doorChosen = prizeDoor;
        } else {
        //Do nothing
        }
        } else {
        printf("However, door %i has been opened and it contains a goat which leaves door %i, would you like to switch?\n", falsedoor1, falsedoor2);
        printf("1 = Yes\n");
        printf("2 = No\n");
        scanf("%i", &finalChose);
        if (finalChose == 1) {
            doorChosen = falsedoor2;
        } else {
        //Do nothing
        }
        }
        printf("\n");
        printf("\n");
        printf("Your Door : %i\n", doorChosen);
        printf("The prize door : %i\n", prizeDoor);
        /* These are for testing purposes */
        //printf("False door 1 : %i\n", falsedoor1);
        //printf("False door 2 : %i\n", falsedoor2);

        if (doorChosen == prizeDoor) {
            printf("You won!\n");
            wins = wins + 1;
        } else {
            printf("You lost!\n");
        }
        totalgames = totalgames + 1; //Always add 1 to the total amount of games
        gamemode = 0; //When this line is used, the program will go back to the original core

     }
}

//Reseach related content goes here
int ResearchMode() {
    researchwins = 0;
    totalgames2 = 0;
    while (research) {
        printf("Please select one of the modes : \n");
        printf("1 - always-switch\n");
        printf("2 - never-switch\n");
        printf("3 - back to main menu\n");
        printf(":");
        scanf("%i", &selection);
        if (selection == 1) { //always switch
            printf("# of games to simulate : \n");
            printf(": ");
            scanf("%i", &games);

            loopGames1(games, researchwins, totalgames2);

            research = 0;
        } else if (selection == 2) { //never switch
            printf("# of games to simulate : \n");
            printf(": ");
            scanf("%i", &games);

            loopGames2(games, researchwins, totalgames2);

            research = 0;
        } else if (selection == 3) { //exit
            research = 0;
        } else {
          printf("Please enter a valid number : ");
        }

    }
}

//This function finds the doors that don't have the prize.
int AssignOptionDoor() {
for (numberOfDoors = 3; numberOfDoors > 0; numberOfDoors = numberOfDoors - 1) {
    if (prizeDoor == numberOfDoors) {

    } else {
    falsedoor1 = numberOfDoors;
    }
}
for (numberOfDoors = 3; numberOfDoors > 0; numberOfDoors = numberOfDoors - 1) {
    if (prizeDoor == numberOfDoors) {

    } else if (falsedoor1 == numberOfDoors) {

    } else {
       falsedoor2 = numberOfDoors;
    }
}
}

//This function is used to loop the games for N number of games(always-switch)

int loopGames1() {
    int loopTimes;
    float probability;
    doorChosen = 1;

for (loopTimes = games; games > 0; games = games - 1) {
    prizeDoor = rand()%(4 - 1) + 1;
    AssignOptionDoor(prizeDoor);
        //always switch doors
        if (falsedoor1 == doorChosen) {
            doorChosen = prizeDoor;
        } else if (falsedoor2 == doorChosen) {
            doorChosen = prizeDoor;
        } else {
            doorChosen = falsedoor2;
        }
        //win or lose
        if (doorChosen == prizeDoor) {
            researchwins = researchwins + 1;
        } else {

        }
        totalgames2 = totalgames2 + 1.0;
}
probability = ((researchwins / totalgames2) * 100);
printf("total wins : %i\n", researchwins);
printf("total games : %i\n", loopTimes);
printf("Probability : %f\n", probability);

}

//This function is used to loop the games for N number of games as well(never-switch)

int loopGames2() {

    int loopTimes;
    float probability;
    doorChosen = 1;

for (loopTimes = games; games > 0; games = games - 1) {
    prizeDoor = rand()%(4 - 1) + 1;
    AssignOptionDoor(prizeDoor);
        //never switch doors
        if (falsedoor1 == doorChosen) {

        } else if (falsedoor2 == doorChosen) {

        } else {

        }
        //win or lose
        if (doorChosen == prizeDoor) {
            researchwins = researchwins + 1;
        } else {

        }
        totalgames2 = totalgames2 + 1.0;
}
probability = ((researchwins / totalgames2) * 100);
printf("total wins : %i\n", researchwins);
printf("total games : %i\n", loopTimes);
printf("Probability : %f\n", probability);

}

