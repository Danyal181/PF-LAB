#include <stdio.h>
#include <math.h>

struct Point {
    float x, y;
};

double findDistance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int isInsideRectangle(struct Point p, float x1, float x2, float y1, float y2) {
    if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
        return 1;
    return 0;
}

int main() {
    struct Point p1 = {2.5, 3.5}, p2 = {6.0, 7.0};
    printf("Distance: %.2lf\n", findDistance(p1, p2));

    if (isInsideRectangle(p1, 1.0, 4.0, 2.0, 5.0))
        printf("Point is inside the rectangle.\n");
    else
        printf("Point is outside the rectangle.\n");
    return 0;
}

