#include <stdio.h>
#include <math.h>

/* Constants */

// Horizontal
#define H_BAR_SPACING 10
#define H_SECTION_COUNT 6
#define H_MID (H_BAR_SPACING * H_SECTION_COUNT) / 2
#define GRAPH_WIDTH (H_BAR_SPACING * H_SECTION_COUNT) + 1

// Vertical
#define V_BAR_SPACING V_SECTION_SPAN / RANGE_STEP
#define V_SECTION_SPAN 45
#define V_SECTION_COUNT 360 / V_SECTION_SPAN
#define GRAPH_HEIGHT (V_BAR_SPACING * V_SECTION_COUNT) + 1

// Graph range
#define RANGE_START 0
#define RANGE_STEP 5
#define RANGE_END V_BAR_SPACING * V_SECTION_COUNT * RANGE_STEP

/* Prototypes */
void init_graph(void);
void plot(double x, double y);
void draw_graph(void);
double deg_to_rad(int angle);

char graph[GRAPH_HEIGHT][GRAPH_WIDTH];

int main() {
    init_graph();
    
    /* Plot y = sin(x) */
    for (int x=RANGE_START; x<=RANGE_END; x+=RANGE_STEP)
        plot(x, sin(deg_to_rad(x)));
    
    draw_graph();
    
    return 0;
}

void init_graph() {
    int x, y;
    
    /* Draw vertical bars */
    for (y=0; y<GRAPH_HEIGHT; y++)
        for (x=0; x<GRAPH_WIDTH; x++)
            graph[y][x] = x%H_BAR_SPACING ? ' ' : '|';
    
    /* Draw horizontal bars */
    for (y=0; y<GRAPH_HEIGHT; y+=V_BAR_SPACING)
        for (x=0; x<GRAPH_WIDTH; x++)
            graph[y][x] = x%H_BAR_SPACING ? '-' : '+';
    
    /* Clear 1st column */
    for (y=0; y<GRAPH_HEIGHT; y++)
        graph[y][0] = ' ';
}

void plot(double x, double y) {
    int translated_x = x / RANGE_STEP;
    int translated_y = round(H_MID * (y+1));
    graph[translated_x][translated_y] = 'o';
}

void draw_graph() {
    int x, y;
    
    /* Print column header */
    printf("%3s%-30d%-30d%d\n", "", -1, 0, 1);
    
    for (y=0; y<GRAPH_HEIGHT; y++) {
        printf("%3.1d", y*RANGE_STEP);
        for (x=0; x<GRAPH_WIDTH; x++)
            putchar(graph[y][x]);
        putchar('\n');
    }
}

double deg_to_rad(int angle) {
    return angle * (M_PI / 180);
}
