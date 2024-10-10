#ifndef PLOTFUNC_H
#define PLOTFUNC_H


void plot_function(const char *function) {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Error opening GNUplot.\n");
        return;
    }

    // Plot settings
    fprintf(gnuplot, "set title 'Graph of %s'\n", function);
    fprintf(gnuplot, "set xlabel 'X-axis'\n");
    fprintf(gnuplot, "set ylabel 'Y-axis'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set xrange [-10:10]\n");  // Adjust range as needed
    fprintf(gnuplot, "set yrange [-10:10]\n");  // Adjust range as needed
    fprintf(gnuplot, "plot %s with lines title '%s'\n", function, function);

    fflush(gnuplot);  // Ensure commands are sent to GNUplot
    pclose(gnuplot);
}


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


#endif //PLOTFUNC_H