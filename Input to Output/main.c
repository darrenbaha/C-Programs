#include <stdio.h>
#include <stdlib.h>

FILE *filePtr, *outputfilePtr;

typedef struct {

   int studentid;
   float homework, lab, midterm, exam, finalmark;

} Array;

int main() {

filePtr = fopen("marks.txt", "r");
outputfilePtr = fopen("marks_final.txt", "w");

//Find the File
if (filePtr == NULL) {
    printf("Error 1 : Cannot find marks.txt file!\n");
} else {
//Grab all the data
    int entrycount, i;

    fscanf(filePtr, "%i", &entrycount);
    //printf("%i", entrycount);

    Array *rows = malloc(sizeof(Array) * entrycount); //Assign enough memory for the array
    printf("Number of Students : %i\n", entrycount);
    printf("Found Data : \n");
    for (i = 0; i < entrycount; i++) {
        //Assigns the student id and mark into the array
        fscanf(filePtr, "%i %f %f %f %f", &rows[i].studentid, &rows[i].homework, &rows[i].lab, &rows[i].midterm, &rows[i].exam);
        printf("%i %f %f %f %f\n", rows[i].studentid, rows[i].homework, rows[i].lab, rows[i].midterm, rows[i].exam);

        //Now modify the data to our liking! i.e xxxstudentid and final mark
        //final mark calculation
        float mark1,mark2,mark3,mark4, calculated;
        mark1 = rows[i].homework / 100;
        mark2 = rows[i].lab / 100;
        mark3 = rows[i].midterm / 100;
        mark4 = rows[i].exam / 100;
        calculated = (mark1 * 10) + (mark2 * 20) + (mark3 * 30) + (mark4 *40);
        //printf(" %f\n", calculated);
        //store the mark
        rows[i].finalmark = calculated;
        //printf(" %f\n", rows[i].finalmark);

        //Now lets modify the student id!
        //This cuts out the first three nnumbers in the student ID
        //the xxx part will be added when we outprint the file
            int x = rows[i].studentid % 10; //7
            int x2 = (rows[i].studentid / 10) %10 *10;
            int x3 = (rows[i].studentid / 100) %10 *100;
            int x4 = (rows[i].studentid / 1000) %10 *1000;
            int xFinal = x4 + x3 + x2 + x;
            rows[i].studentid = xFinal;

            //Everything is done!

    }
    //outprint file
    fprintf(outputfilePtr, "ID      Homework      Lab     Midterm     Exam    Final\n");
    for (i = 0; i < entrycount; i++) {
        fprintf(outputfilePtr, "xxx%i %f %f %f %f %f\n", rows[i].studentid, rows[i].homework, rows[i].lab, rows[i].midterm, rows[i].exam, rows[i].finalmark);

    }
    printf("\n");
    printf("\n");
    printf("Final_Marks.txt created successfully!");
    printf("\n");
    printf("\n");
}
    fclose(filePtr);
    return 0;
}
