//Marco Leonardo Valencia Martinez
//A01412017@ITESM.MX
/*This program sells tickets to the Benefit of Mr. G.
 * The venue has 400 rows, 50 seats on the side, 100 on the center and other 50 in the other side.
 * this program also stores the purchase data, as well as gives a feedback of all purchases,
 * places occupied by area and in total, etc.
 */
#include <stdio.h>

//Here we are going to register a person in a determiante space
void fillseat(char *seats[50][40], int x, int y, const char *filler) {
    int x2;
    int y2;
    int i;
    int j;
    int k = 0;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 40; j++) {
            if (x == i && y == j) {
                if (strcmp(seats[i][j], "ava") == 0) {
                    seats[i][j] = filler;
                    break;
                } else {
                    printf("The seat is already taken by ", seats[i][j], ", try another seat\n");
                    scanf("%i", &x2);
                    scanf("%i", &y2);
                    fillseat(seats, x2, y2, filler);
                    break;
                }
            }
        }
    }
}

//Here we are going to fill al the seat available for them to not be null
void init(char *seats[50][40]) {
    int i;
    int j;
    int k = 0;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 40; j++) {
            seats[i][j] = "ava";
        }

    }
}

//Here we assignate the first empty seat
void firstEmpty(char *seats[50][40], const char *filler) {
    int i;
    int j;
    int k = 0;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 40; j++) {
            if (strcmp(seats[i][j], "ava") == 0) {
                seats[i][j] = filler;
                break;
            }
        }
    }
}

//Here we assignate the first seat which is near a determinate position
void firstNextTo(char *seats[50][40], int x, int y, const char *filler) {
    x++;
    y++;
    int i;
    int j;
    int k = 0;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 40; j++) {
            if (x == i && y == j) {
                if (strcmp(seats[i][j], "ava") == 0) {
                    seats[i][j] = filler;
                    break;
                } else {
                    printf("The adjacent seat is already taken, you will be moved to closest one \n");
                    firstNextTo(seats, x, y, filler);
                    break;
                }
            }
        }
    }
}

//Here we ask the values
void input(char *seats[50][40]) {
    char blank[1000];
    char name[50];
    int question;
    int funt;
    int strow;
    int stl;
    int hr;
    float cost;
    printf("Enter the day, 0 for saturday and 1 for sunday: \n");
    scanf("%i", &funt);
    printf("Enter the hour, 18 or 21?\n");
    scanf("%i", &hr);
    printf("Enter:\n 0 if you want the first available seat on the theatre\n 1 if you want the first available seat next to a especific one\n 2 if you want a especific seat");
    scanf("%i", &question);
    switch (question) {
        case 0:
            printf("Enter the your name\n");
            fgets(blank, sizeof(blank), stdin);
            fgets(name, sizeof(name), stdin);
            firstEmpty(seats, name);
            break;
        case 1:
            printf("Enter the your name\n");
            fgets(blank, sizeof(blank), stdin);
            fgets(name, sizeof(name), stdin);
            printf("Enter the row of the seat you want to be next to:\n");
            scanf("%i", &strow);
            printf("Enter the line:\n");
            scanf("%i", &stl);
            firstNextTo(seats, strow, stl, name);
            break;
        case 2:
            printf("Enter the your name\n");
            fgets(blank, sizeof(blank), stdin);
            fgets(name, sizeof(name), stdin);
            printf("Enter the row of the seat you want:\n");
            scanf("%i", &strow);
            printf("Enter the line:\n");
            scanf("%i", &stl);
            fillseat(seats, strow, stl, name);
            if (strow == 1) {
                cost = 20;
            } else if (strow >= 2 && strow <= 5) {
                cost = 15;
            } else if (strow >= 6 && strow <= 15) {
                cost = 12;
            } else {
                cost = 10;
            }
            break;
    }
    if (hr == 18) {
        cost = cost + cost * .10;
    } else {
        cost = cost + cost * .20;
    }
}

//And here we finally call all the fucntions we made above
int main() {

    int flag = 0;//Here we will define a variable that will stop the program.
    char *seats[50][40];//here we will create a tridimensional array for the seats.
    init(seats);
    while (flag < 2) {
        input(seats);
        flag++;
    }
    printf(seats[0][0]);
    printf(seats[0][2]);


    return 0;
}

//At the moment I called the array I fill the position 0,0 and then 0,2 it fills the position 0,0 with 0,2
//I think it is a problem with Fgets and scanf because it tried do it manualkly but
//I couldn´t resolve how to fix this problem
//I tried my best