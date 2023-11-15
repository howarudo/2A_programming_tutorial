#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[20];
    int age;
    double height, weight;
    struct person *next;
};

struct person* construct_person(int age, double height, double weight, char name[20]) {
    // allocate memory for person type
    // initiate next as null
    struct person *dummy = (struct person*) malloc(sizeof(struct person));
    dummy -> age = age;
    dummy -> height = height;
    dummy -> weight = weight;
    strcpy(dummy -> name, name);
    dummy -> next = NULL;
    return dummy;
};

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
    // holder hold the first person
    struct person *holder = construct_person(0, 0.0, 0.0, "ASKFDJLK");
    // tail hold the previous person
    struct person *tail = holder;
    // head hold the current person
    struct person *head;
    char name[20]; int age; double height, weight;
    while (fscanf(fp, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) > 0) {
        // head will hold current person's info,
        // then tail (previous person's) next should point at the current person
        head = construct_person(age, height, weight, name);
        tail -> next = head;
        tail = head;
    }
    holder = holder -> next;
    while (holder) {
        // while holder is not NULL
        printf("Name: %s, Age: %d, Height: %lf, Weight: %lf\n", holder -> name, holder -> age, holder -> height, holder -> weight);
        holder = holder -> next;
    }
    return 0;
}
