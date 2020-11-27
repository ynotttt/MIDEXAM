#include "source.cpp"


void mainMenu() {
    int patients, vacc;
    int day, year; char month[30], name[255];
    scanf("%d %d", &patients, &vacc);

    for (int i = 0; i < patients; i++)
    {
        scanf("%d %s %d", &day, month, &year); getchar();
        scanf(" - %[^\n]", name);
        pushPQ(name, day, month, year);
    }

    patients <= vacc ? printf("All patients got the cure, %d cure left\n", vacc-patients) : printf("Need %d more cure\n", patients-vacc);
    if (patients <= vacc) {
        return;
    }
    else {
        for (int i = 1; i <= vacc; i++) {
            popHead();
        }
    }
    print();
}