#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int option, close, calc1, calc2, calc3, calc4, color1, color2, color3, color4;
int main()

{

close = 1;

while (close) {
printf("Please choose one of the options : \n");
printf("  1. Calculate resistance value\n");
printf("  2. Help\n");
printf("  3. Exit\n");
    scanf("%i", &option);
    if (option == 1) {

    printf("Starting calculator...\n");
    printf("Please input the # that correlates to the color of the band :\n 0 = Black\n 1 = Brown\n 2 = Red\n 3 = Orange\n 4 = Yellow\n 5 = Green\n 6 = Blue\n 7 = Violet\n 8 = Gray\n 9 = White\n");
    printf("Resistor color 1 : ");
    calc1 = 1;
    while (calc1) {
    scanf("%i", &color1);
    if (color1 <= 9 && color1 >= 0) {
    calc1 = 0;
    calc2 = 1;
    printf("Resistor color 2 : ");
    } else {
        printf("Please enter a valid color : ");
    }
    }
    while (calc2) {
    scanf("%i", &color2);
    if (color2 <= 9 && color2 >= 0) {
    calc2 = 0;
    calc3 = 1;
    printf("10 = Gold\n");
    printf("11 = Silver\n");
    printf("Resistor color 3 : ");
    } else {
        printf("Please enter a valid color : ");
    }

    }
    while (calc3) {
    scanf("%i", &color3);
    if (color3 <= 11 && color3 >= 0) {
    calc3 = 0;
    calc4 = 1;
    printf("~~~~Resistance tolerance~~~~\n");
    printf("1 = Gold ~5%%\n");
    printf("2 = Silver ~10%%\n");
    printf("Resistor color 4 : ");
    } else {
        printf("Please enter a valid color : ");
    }

    }
    while (calc4) {
    scanf("%i", &color4);
    if (color4 <= 2 && color4 >= 1) {
    printf("Your selections : %i, %i, %i, %i\n", color1, color2, color3, color4);
    //calculator(int color1, int color2, int color3, int color4);
    calculator(color1, color2, color3, color4);
    calc4 = 0;
    } else {
        printf("Please enter a valid color : ");
    }

    }

    } else if (option == 2) {
    printf("Welcome to the resistance calculator created by Darren Bahadoor\n");
    printf("To use this program, please input the integer 1 to get into the actual calculator\n");
    printf("Once there, input the number that correlates to the desired band four times.\n");
    printf("The final resistance will be calculated for you!\n");
    printf("\n");
    } else if (option == 3) {
    printf("Exiting..");
    close = 0;
    } else {
    printf("Please enter one of the options : ");
    }
  }
}

int calculator(int color1, int color2, int color3, int color4) {
    float result;
    result = 0;

if (color1 == 0) {
    result = result + 0;
} else if (color1 == 1) {
    result = result + 10;
} else if (color1 == 2) {
    result = result + 20;
} else if (color1 == 3) {
    result = result + 30;
} else if (color1 == 4) {
    result = result + 40;
} else if (color1 == 5) {
    result = result + 50;
} else if (color1 == 6) {
    result = result + 60;
} else if (color1 == 7) {
    result = result + 70;
} else if (color1 == 8) {
    result = result + 80;
} else if (color1 == 9) {
    result = result + 90;
}

if (color2 == 0) {
    result = result + 0;
} else if (color2 == 1) {
    result = result + 1;
} else if (color2 == 2) {
    result = result + 2;
} else if (color2 == 3) {
    result = result + 3;
} else if (color2 == 4) {
    result = result + 4;
} else if (color2 == 5) {
    result = result + 5;
} else if (color2 == 6) {
    result = result + 6;
} else if (color2 == 7) {
    result = result + 7;
} else if (color2 == 8) {
    result = result + 8;
} else if (color2 == 9) {
    result = result + 9;
}

if (color3 == 0) {
    result = result * pow(10, 0);
} else if (color3 == 1) {
    result = result * pow(10, 1);
} else if (color3 == 2) {
    result = result * pow(10, 2);
} else if (color3 == 3) {
    result = result * pow(10, 3);
} else if (color3 == 4) {
    result = result * pow(10, 4);
} else if (color3 == 5) {
    result = result * pow(10, 5);
} else if (color3 == 6) {
    result = result * pow(10, 6);
} else if (color3 == 7) {
    result = result * pow(10, 7);
} else if (color3 == 8) {
    result = result * pow(10, 8);
} else if (color3 == 9) {
    result = result * pow(10, 9);
} else if (color3 == 10) {
    result = result * pow(10, -1);
} else if (color3 == 11) {
    result = result * pow(10, -2);
}
if (color4 == 1) {
printf("Resistance  : %f ~5%% KiloOhms\n", result);
} else {
printf("Resistance  : %f ~10%% KiloOhms\n", result);
}
}
