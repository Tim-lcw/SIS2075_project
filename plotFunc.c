#include <stdio.h>
#include<stdlib.h>
#include "plotFunc.h"

void plotGraph() {
    char func1[100], func2[100];
    int choice;

    printf("Select operation:\n");
    printf("1. Plot a function\n");
    printf("2. Plot points of intersection between two functions\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the function to plot (e.g., sin(x), x**2): ");
        scanf("%s", func1);
        plot_function(func1);
    } else if (choice == 2) {
        printf("Enter the first function (e.g., x**2, sin(x)): ");
        scanf("%s", func1);
        printf("Enter the second function (e.g., x-2): ");
        scanf("%s", func2);
        plot_intersection(func1, func2);
    } else {
        printf("Invalid choice.\n");
    }
}

void plot_intersection(const char *func1, const char *func2) {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Error opening GNUplot.\n");
        return;
    }

    // Plot settings for both functions and their intersection
    fprintf(gnuplot, "set title 'Intersection of %s and %s'\n", func1, func2);
    fprintf(gnuplot, "set xlabel 'X-axis'\n");
    fprintf(gnuplot, "set ylabel 'Y-axis'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set xrange [-10:10]\n");  // Adjust range as needed
    fprintf(gnuplot, "set yrange [-10:10]\n");  // Adjust range as needed
    fprintf(gnuplot, "plot %s with lines title '%s', %s with lines title '%s'\n", func1, func1, func2, func2);

    fflush(gnuplot);  // Ensure commands are sent to GNUplot
    pclose(gnuplot);

    return 0;
}