#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[20];
    int age;
    double height, weight;
    struct person *next;
    struct person *prev;
};

struct person* construct_person(int age, double height, double weight, char name[20]) {
    struct person *dummy = (struct person*) malloc(sizeof(struct person));
    dummy -> age = age;
    dummy -> height = height;
    dummy -> weight = weight;
    strcpy(dummy -> name, name);
    dummy -> next = NULL;
    // add prev to store previous person
    dummy -> prev = NULL;
    return dummy;
};

void delete(struct person* holder, char* s);

int main(int argc, char **argv) {
    FILE  *fp;
    if (argc != 2) {
        printf("Need 1 file name!\n");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    struct person *holder = construct_person(0, 0.0, 0.0, "ASKFDJLK");
    struct person *tail = holder;
    struct person *head;
    char name[20]; int age; double height, weight;
    while (fscanf(fp, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) > 0) {
        head = construct_person(age, height, weight, name);
        head -> prev = tail;
        tail -> next = head;
        tail = head;
    }

    char s[100];
    scanf("%s", s);
    printf("Looking for '%s' to erase...\n", s);

    delete(holder, s);

    holder = holder -> next;
    while (holder) {
        printf("Name: %s, Age: %d, Height: %lf, Weight: %lf\n", holder -> name, holder -> age, holder -> height, holder -> weight);
        holder = holder -> next;
    }
    return 0;
}

void delete(struct person* finder, char* s) {
    while (finder) {
        // if same string,
        if (strcmp(finder -> name, s) == 0){
            if (finder -> next) {
                // next's previous should be current previous
                finder -> next -> prev = finder -> prev;
            }
            // previous' next should be current next
            finder -> prev -> next = finder -> next;
            printf("Name erased!\n");
            return ;
        }
        finder = finder -> next;
    }
    // if name is not found,
    printf("Name %s not found sir....\nPrinting all names!\n", s);
}
