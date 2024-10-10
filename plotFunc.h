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




#endif //PLOTFUNC_H