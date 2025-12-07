// student.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void calculateMarks(Student *s) {
    s->total = s->math + s->physics + s->chemistry + s->english + s->computer;
    s->percentage = (s->total / 500.0f) * 100.0f;
    s->grade = calculateGrade(s->percentage);
}

char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 80) return 'B';
    else if (percentage >= 70) return 'C';
    else if (percentage >= 60) return 'D';
    else if (percentage >= 50) return 'E';
    else return 'F';
}

int getNextId() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 1; // first student

    Student s;
    int maxId = 0;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id > maxId) maxId = s.id;
    }
    fclose(fp);
    return maxId + 1;
}

int addStudentToFile(Student *s) {
    FILE *fp = fopen(FILENAME, "ab");
    if (!fp) return 0;

    s->id = getNextId();
    calculateMarks(s);

    int written = fwrite(s, sizeof(Student), 1, fp);
    fclose(fp);
    return written == 1;
}

int findStudentById(int id, Student *out) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;

    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == id) {
            if (out) *out = s;
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int updateStudentInFile(const Student *sNew) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        fclose(fp);
        return 0;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == sNew->id) {
            fwrite(sNew, sizeof(Student), 1, temp);
            found = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    return found;
}

int deleteStudentFromFile(int id) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        fclose(fp);
        return 0;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == id) {
            found = 1; // skip
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    return found;
}

int readAllStudents(Student *buffer, int maxCount) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;

    int count = 0;
    while (count < maxCount &&
           fread(&buffer[count], sizeof(Student), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}
