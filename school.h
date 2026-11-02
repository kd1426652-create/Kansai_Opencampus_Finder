#ifndef SCHOOL_H
#define SCHOOL_H

// Review/Rating Structure
typedef struct {
    char student_name[50];
    int rating;             // 1 to 5 Stars
    char comment[200];
} Review;

// School Structure
typedef struct {
    int id;
    char name[100];         // school name 
    char location[50];      // Osaka, Kyoto, Kobe
    char category[50];      // IT, Web, web,Business,AI
    char open_campus_url[200]; // Open Campus Link
    Review reviews[10];    // Reviews
    int review_count;      // Review count
} School;

#endif
