// student.h
#ifndef STUDENT_H
#define STUDENT_H

#define FILENAME "students.dat"
#define MAX_NAME 50
#define MAX_ADDRESS 100

typedef struct {
    int id;
    char name[MAX_NAME];
    int age;
    char gender;
    char address[MAX_ADDRESS];
    char phone[15];
    char email[MAX_NAME];
    float math;
    float physics;
    float chemistry;
    float english;
    float computer;
    float total;
    float percentage;
    char grade;
} Student;

// Logic
void calculateMarks(Student *s);
char calculateGrade(float percentage);
int  getNextId();

// File operations
int addStudentToFile(Student *s);
int findStudentById(int id, Student *out);
int updateStudentInFile(const Student *s);
int deleteStudentFromFile(int id);
int readAllStudents(Student *buffer, int maxCount);

#endif
