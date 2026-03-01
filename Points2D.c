#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int AreSame(double a, double b) {
    return fabs(a - b) < __DBL_EPSILON__;
}

int findEqtn(double x1, double y1, double x2, double y2, double xmid, double ymid) {
    double m = 0;
    if(x1 != x2) {
        m = (y2 - y1) / (x2 - x1);
        
        double c = y1 - (m*x1);
        //printf("Checkpoint 1.\n");

        //c = y1-m*x1
            //y1 - (m*x1) -c = 0
        //printf("%lf\n", ((m*xmid) + c));

        if(AreSame(ymid, ((m*xmid) + c)) != 0 ) {
        //printf("Checkpoint 1a.\n");
        return 1;
        }
        else {
            //printf("Checkpoint 2.\n");
            return 0;
        }   
    }
    else {
        if(xmid == x1) {
            return 1;
        }
        return 0;
    }
}

int checkIdentical(double x1, double y1, double x2, double y2) {
    if (x1 == x2 && y1 == y2) {
        return 1;
    }
    else return 0;
}

int main() {
    double x1, x2, x3; //Initialize X points
    double y1, y2, y3; //Initialize Y points
    int read;
    //double i, j;       //Initialize variables for slope.

    //If the slope of (X1,Y1 & X2,Y2) is equal to the slope of (X2,Y2 & X3,Y3) then there exists a line that connects all three. 

    printf("Point A:\n");
    read = scanf("%lf %lf", &x1, &y1);
    if(read != 2) {
        printf("Invalid input.\n");
        exit (EXIT_FAILURE);
    }

    printf("Point B:\n");
    read = scanf("%lf %lf", &x2, &y2);
    if(read != 2) {
        printf("Invalid input.\n");
        exit (EXIT_FAILURE);
    }

    printf("Point C:\n");
    read = scanf("%lf %lf", &x3, &y3);
    if(read != 2) {
        printf("Invalid input.\n");
        exit (EXIT_FAILURE);
    }
    
    //check identical points
    if( checkIdentical(x1,y1,x2,y2) == 1 || checkIdentical(x2,y2,x3,y3) == 1 || checkIdentical(x1,y1,x3,y3) == 1) {
        printf("Some points are identical.\n");
        exit (EXIT_SUCCESS);
    }

    
/*
    while( x1==x2 && x2==x3 && x1==x3) {
    printf("There exists a line connecting all three points.\n"); 
    if( y1 > y2 ) {
        if( y2 > y3) {
            printf("Point B is in the middle.\n"); 
            exit (EXIT_SUCCESS);
        }
        else {
            printf("Point C is in the middle.\n");
            exit (EXIT_SUCCESS);
        }
    }
    else if( y2 > y1 ) {
        if( y1 > y3) {
            printf("Point A is in the middle.\n"); 
            exit (EXIT_SUCCESS);
        }
        else {
            printf("Point C is in the middle.\n");
            exit (EXIT_SUCCESS);
        }
    else if( y3 > y1) {

    }
    }
    }*/
    //func check if all x is 0 or y is 0 or the same

    //finding the middle point
    double dist1 = 0, dist2 = 0, dist3 = 0;
    dist1 = sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) ) + sqrt( (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) ); //X1
    dist2 = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) ) + sqrt( (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) ); //X2
    dist3 = sqrt( (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) ) + sqrt( (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) ); //X3

    /*printf("1 %lf\n", dist1);
    printf("2 %lf\n", dist2);
    printf("3 %lf\n", dist3);*/
    
    //double min_dist;
    if( dist1 < dist2 && dist1 < dist3 ) { 
        //min_dist = dist1; 
        if(findEqtn(x2,y2,x3,y3,x1,y1) == 1) {
            printf("There exists a line connecting all three points.\n");
            printf("Point A is in the middle.\n");
            exit (EXIT_SUCCESS);
        }
        else{
        printf("No line connects all points.\n");
        exit (EXIT_SUCCESS);
    } 
    }

    else if( dist2 < dist3 && dist2 < dist1) { 
        //min_dist = dist2;
        if(findEqtn(x1,y1,x3,y3,x2,y2) == 1) {
            printf("There exists a line connecting all three points.\n");
            printf("Point B is in the middle.\n");
            exit (EXIT_SUCCESS);
        }
        else{
        printf("No line connects all points.\n");
        exit (EXIT_SUCCESS);
    } 
    }

    else if ( dist3 < dist1 && dist3 < dist2 ) { 
        //min_dist = dist3;
        if(findEqtn(x1,y1,x2,y2,x3,y3) == 1) {
            printf("There exists a line connecting all three points.\n");
            printf("Point C is in the middle.\n");
            exit (EXIT_SUCCESS);
        }
        else{
        printf("No line connects all points.\n");
        exit (EXIT_SUCCESS);
    }   
    }

    else{
        printf("No line connects all points.\n");
        exit (EXIT_SUCCESS);
    }

    //printf("Checkpoint 4.\n");

/*
    i = (y2 - y1) / (x2 - x1); //Slope point 1
    j = (y3 - y2) / (x3 - x2); //Slope point 2

    printf("%lf %lf\n", i, j);
    
    if( i == j ) {
        printf("There exists a line connecting all three points.\n");
        exit (EXIT_SUCCESS);
    }

    else{
        printf("No line connects all points.\n");
        exit (EXIT_SUCCESS);
    }
*/
    return EXIT_SUCCESS;
}