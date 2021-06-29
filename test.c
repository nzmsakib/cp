#include <stdio.h>
#include <string.h>

// Create structure
struct Person {
    char name[100];
    int age;
} x, y, a, b;

int main(void) {
    
    // Initialize two variables
    strcpy(x.name, "Afifa");
    x.age = 22;
    strcpy(y.name, "Alam");
    y.age = 21;

    // Write to file
    FILE *filew = fopen("records.txt", "w");
    fprintf(filew, "%s %d\n", x.name, x.age);
    fprintf(filew, "%s %d\n", y.name, y.age);
    fclose(filew);

    // Read from file
    FILE *filer = fopen("records.txt", "r");
    fscanf(filer, "%s %d\n", a.name, &a.age);
    fscanf(filer, "%s %d\n", b.name, &b.age);
    fclose(filer);

    // Calculate average and print
    printf("Avg Age: %0.2f\n", (a.age + b.age)/2.0);

    return 0;
}