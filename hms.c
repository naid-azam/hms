#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define space for(int i=1; i<=70; i++) printf(" ");
#define space2 for(int j=1;j<=40;j++) printf(" ");

#define space for(int i=1; i<=70; i++) printf(" ");
#define space2 for(int j=1;j<=40;j++) printf(" ");
// Stack structure for bed allotment
#define MAX_BEDS 100
struct BedStack {
    int top;
    int beds[MAX_BEDS];
};
// Function to initialize the stack
void initStack(struct BedStack *stack) {
    stack->top = -1; // Stack is empty
}
// Function to push a bed number onto the stack
int push(struct BedStack *stack, int bedNumber) {
    if (stack->top >= MAX_BEDS - 1) {
        printf("Stack overflow: No more beds available.\n");
        return -1; // Stack is full
    }
    stack->beds[++stack->top] = bedNumber;
    return 0; // Success
}
// Function to pop a bed number from the stack
int pop(struct BedStack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow: No beds allocated.\n");
        return -1; // Stack is empty
    }
    return stack->beds[stack->top--]; // Return the bed number and decrement top
}
// Function to check if the stack is empty
int isEmpty(struct BedStack *stack) {
    return stack->top < 0;
}
///This login() funtion take the username and password from the staff members and then
/// only allow if it is correct
/// Only 3 trails is assign for login after that it will not take input.
int login()
{
    char usernm[80], password[80];
    int trials = 1;
    while (trials <= 3)
    {
        printf("\n\n\n");
        space printf("=============== Login Required ===============\n\n\n\n\n");
        space printf("Enter Username : ");
        scanf("%s", usernm);
        space printf("Enter Password : ");
        scanf("%s", password);

        ///Here it is comparing with the original username and password using strcmp function.
        if (strcmp(usernm, "AdminJi") == 0 && strcmp(password, "1234@") == 0)
        {
            space printf("Login successful!\n");
            return 1;
        }
        else
        {
            space printf("Invalid Username or Password. Try again.\n");
            trials++;
        }
    }
    space printf("Too many failed attempts. Access denied.\n");
    return 0;
}

struct patient
{
    char name[100], dis[100];
    int id, age, doc, tkn1, shift,bedNumber,cancel;
    char time1[30];
    float bill;
    float discount;
    float final_bill;
    struct patient *next;
} typedef pat;
struct doctor
{
    char nm[100], sft[100], deg[100];
    int rcd, rcd1;
};
struct tm
{
    int tkn;
    char time[30];
};
int choice, record, sft;
struct tm ar[] = {{1, "8:00 AM"}, {2, "8:15 AM"}, {3, "8:30 AM"}, {4, "8:45 AM"}, {5, "9:00 AM"}, {6, "9:15 AM"}, {7, "9:30 AM"}, {8, "9:45 AM"}, {9, "10:00 AM"}, {10, "10:15 AM"}, {11, "10:30 AM"}, {12, "10:45 AM"}, {13, "11:00 AM"}, {12, "11:15 AM"}, {13, "11:30 AM"}, {14, "11:45 AM"}};
struct tm ar1[] = {{1, "2:00 PM"}, {2, "2:15 PM"}, {3, "2:30 PM"}, {4, "2:45 PM"}, {5, "3:00 PM"}, {6, "3:15 PM"}, {7, "3:30 PM"}, {8, "3:45 PM"}, {9, "4:00 PM"}, {10, "4:15 PM"}, {11, "4:30 PM"}, {12, "4:45 PM"}, {13, "5:00 PM"}, {12, "5:15 PM"}, {13, "5:30 PM"}, {14, "5:45 PM"}};

struct doctor b[] = {{"DR.SHANKAR", "8 AM to 12PM  2 PM to 6 PM (Sunday off)", "MBBS - MD", 0},
                     {"DR.RIYA SINGH", "8 AM to 12PM  2 PM to 6 PM (Saturday off)", "MBBS- MS(ORTHOPEDIC SURGEON)", 0},
                     {"DR.M PUNDIR", "8 AM to 12PM  2 PM to 6 PM (Sunday off)", "BDS -  MDS", 0},
                     {"DR.R YADAV", "8 AM to 12PM   2 PM to 6 PM (Friday off)", "BAMS - BUMS", 0},
                     {"DR ISHA MITTAL", "8 AM to 12PM  2 PM to 6 PM (Monday off)", "MBBS - GYNECOLOGIST", 0},
                     {"DR.P RATURI", "8 AM to 12PM  2 PM to 6 PM (Sunday off)", "MBBS - MD - DERMETOLOGIST", 0}};

float doc_fees[] = {500.0, 600.0, 700.0, 650.0, 550.0, 700.0};
pat *f = NULL;
pat *r = NULL;
// Initialize the bed stack
struct BedStack bedStack;
/// Funtion that taking the details and storing a circular link list.
void det()
{
    int i;
    char bedChoice[4];
    srand(time(NULL));
    /// Declaring a new Node aka Patient appointment in linklist
    pat *newPatient;
    /// Dynamically providing space in heap;
    newPatient = (pat *)malloc(sizeof(pat));
    /// Details part:-
    newPatient->cancel=1;
    newPatient->id= rand() % 10000 + 1;
    space printf("Enter your name ");
    scanf("%s", newPatient->name);
    space printf("Enter your age  ");
    scanf("%d", &newPatient->age);

    space printf("which disease are you suffering from  ");
    scanf("%s", newPatient->dis);
    space printf("which doctor's appointment do you want\n\n\n");

    space2 printf("%-5s %-25s %-40s %-30s\n", "ID", "Name", "Degree", "Shifts");

    // Print doctor list
    for (i = 0; i < 6; i++)
    {
        space2 printf("%-5d %-25s %-40s %-30s\n", i + 1, b[i].nm, b[i].deg, b[i].sft);
    }
    space printf("Enter your choice");
    scanf("%d", &newPatient->doc);
    while (1)
    {
        space printf("Enter your convinient shift\n");
        space printf("Enter 1 for morning and 2 for evening\n");
        space printf("Enter your choice  ");
        scanf("%d", &sft);
        if (sft < 1 || sft > 2)
        {
            space printf("Invalid shift...Please re-enter\n\n\n");
        }
        else
        {
            break;
        }
    }

    newPatient->shift = sft;
        // Ask the patient if they want a bed
        space printf("Do you want a bed assigned? (Y/N): ");
        scanf("%s", bedChoice);
        if (strcmp(bedChoice, "Y") == 0 || strcmp(bedChoice, "y") == 0) {
            // Allocate a bed for the patient
            if (push(&bedStack, newPatient->id) == 0) { // Assuming bed number is the patient ID for simplicity
                newPatient->bedNumber = newPatient->id; // Assign bed number
            } else {
                newPatient->bedNumber = -1; // No bed assigned
                space printf("No beds available, bed assignment failed.\n");
            }
        } else {
            newPatient->bedNumber = 0; // No bed assigned
        }

    if (sft == 1)
    {

        choice = (newPatient->doc);
        b[choice - 1].rcd += 1;
        record = b[choice - 1].rcd;
        newPatient->tkn1 = ar[record - 1].tkn;
        strcpy(newPatient->time1, ar[record - 1].time);
        newPatient->bill = doc_fees[choice - 1];
        if (newPatient->age >= 60)
        {
            newPatient->discount = newPatient->bill * 0.10;
        }
        else
        {
            newPatient->discount = 0.0;
        }
        newPatient->final_bill = newPatient->bill - newPatient->discount;
    }
    else
    {
        choice = (newPatient->doc);
        b[choice - 1].rcd1 += 1;
        record = b[choice - 1].rcd1;
        newPatient->tkn1 = ar1[record - 1].tkn;
        strcpy(newPatient->time1, ar1[record - 1].time);
        newPatient->bill = doc_fees[choice - 1];
        if (newPatient->age >= 60)
        {
            newPatient->discount = newPatient->bill * 0.10;
        }
        else
        {
            newPatient->discount = 0.0;
        }
        newPatient->final_bill = newPatient->bill - newPatient->discount;
    }

    /// link list now pointing the Node to next Node.
    newPatient->next = NULL;
    /// condition check
    if (r == NULL)
    {
        f = r = newPatient;
        r->next = f;
    }
    else
    {
        r->next = newPatient;
        r = newPatient;
        r->next = f;
    }
}
void emergencyCase() {
    int i;
   space printf("--- Emergency Case Entry ---\n");
    pat *new1;
    new1 = (pat *)malloc(sizeof(pat));
    if (new1 == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(new1->time1,"...");
    new1->bedNumber=0;

    new1->id = rand() % 1000;
    space printf("Enter Patient Name: ");
    scanf("%s", new1->name);
    space printf("Enter Age: ");
    scanf("%d", &new1->age);
    space printf("Enter Disease: ");
    scanf("%s", new1->dis);

    for (i = 0; i < 6; i++)
    {
        space2 printf("%-5d %-25s %-40s %-30s\n", i + 1, b[i].nm, b[i].deg, b[i].sft);
    }
    space printf("Enter your choice");
    scanf("%d", &new1->doc);

    space printf("Enter Shift (1 for Morning, 2 for Evening): ");
    scanf("%d", &new1->shift);

    // Assign token
    if (new1->shift == 1)
        new1->tkn1 = 1;
    else
        new1->tkn1 = 1;

    // Bill
    if (new1->age >= 60){
        new1->bill = 1500;
        new1->discount=0.0;
        new1->final_bill=1500;
    }

    else{
        new1->bill = 2000;
        new1->discount=0.0;
        new1->final_bill=2000;
    }




    // High priority insertion just after head
    if (f == NULL) {
    new1->next = new1;
    f = r = new1;
} else {
    new1->next = f->next;
    f->next = new1;
}


    // Save emergency case to file
    FILE *fp = fopen("HOSPITAL.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "\n[EMERGENCY] ID: %d, Name: %s, Age: %d, Disease: %s, Doctor: %s, Shift: %d, Token: %d, Bill: %.2f\n",
                new1->id, new1->name, new1->age, new1->dis, b[new1->doc - 1].nm, new1->shift, new1->tkn1, new1->bill);
        fclose(fp);
    }

    space printf(" Emergency patient added successfully!\n");
    space printf(" ID: %d |  Token: %d |  Bill: %.2f\n", new1->id, new1->tkn1, new1->bill);
}



void deleteAppointment()
{
    if (f == NULL)
    {
        /// If the list is empty, there's no appointment to delete

        space printf("No appointments to delete.\n");
        return;
    }
    /// temp holds the first patient node to be deleted

    pat *temp = f;

    /// If there's only one node
    if (f == r)
    {
        f = r = NULL;
    }
    else
    {
        f = f->next;
        r->next = f; /// maintain circular nature
    }
    // Free the bed when the patient is discharged
pop(&bedStack);

    /// Appointed patient details
    space printf("Patient Name :%s\n", temp->name);
    space printf("Doctor: %s | token: %d | time: %s | Bed number: %d\n",b[temp->doc - 1].nm, temp->tkn1, temp->time1, temp->bedNumber);
    space printf("Patient has been attended. Appointment slot cleared.\n");
    /// finally remove from the list
    free(temp);
}
void cancelAppointment() {
    if (f == NULL) {
        space printf("No appointments to cancel.\n");
        return;
    }
    int pid, found = 0;
    pat *current = f;
    pat *previous = NULL;
    space printf("Enter patient ID to cancel appointment: ");
    scanf("%d", &pid);
    do {
        if (current->id == pid) {
            found = 1;
            if (previous == NULL) {
                // If the node to be deleted is the first node
                f = current->next;
                r->next = f; // Maintain circular nature
            } else {
                previous->next = current->next; // Bypass the current node
                if (current == r) {
                    r = previous; // Update the last node if needed
                }
            }
            // Free the bed if it was assigned
            if (current->bedNumber != -1) {
                    current->cancel=0;
                pop(&bedStack);
            }
            space printf("Appointment for patient %s (ID: %d) has been canceled.\n", current->name, current->id);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    } while (current != f);
    if (!found) {
        space printf("No appointment found with ID %d.\n", pid);
    }
}
void PatientUnderDoctor(int docId, int sf)
{
    if (f == NULL)
    {
        space printf("No appointments exists.\n");
        return;
    }
    int found = 0;
    pat *t = f;
    /// patient under this Doctor.

    do
    {
        if (t->doc == docId && t->shift == sf)
        {
            found = 1;
            space printf("Patient Name :%s\n", t->name);
            space printf("Patient Age: %d\n", t->age);
            space printf("Patient ID: %d\n", t->id);
            space printf("Disease: %s\n", t->dis);
            space printf("Your token number is %d\n", t->tkn1);
            space printf("You have to come at %s\n", t->time1);
            space printf("-----------------------------------------------\n\n\n");
        }
        t = t->next;
    } while (t != f);
    if (found == 0)
    {
        space printf("No patient is booked for this shift yet!");
    }
}
void display(int sf)
{
    int found = 0;
    if (f == NULL)
    {
        printf("\n");
        space printf("No appointments booked yet.\n");
        return;
    }
    else
    {
        pat *t = f;

        /// simple f me abhi first node hai i.e first patient details hai jo further linked hai.

        do
        {
            if (t->shift == sf&&t->cancel==1)
            {
                found = 1;
                space printf("Patient Name: %s\n", t->name);
                space printf("Patient Age: %d\n", t->age);
                space printf("Patient ID: %d\n", t->id);
                space printf("Disease: %s\n", t->dis);
                space printf("Doctor booked is %s\n", b[t->doc - 1]);
                space printf("Your token number is %d\n", t->tkn1);
                space printf("You have to come at %s\n", t->time1);
                space printf("Bed Number: %d\n", t->bedNumber);
                space printf("bill amount :Rs %0.2f\n", t->bill);
                space printf("discount: Rs %0.2f \n", t->discount);
                space printf("final bill to pay :Rs %0.2f\n", t->final_bill);
                space printf("-----------------------------------------------\n\n\n");
            }
            t = t->next;
        } while (t != f); /// Stop when we circle back to the front
    }
    if (found == 0)
    {
        space printf("No appointments\n");
    }
}

void display1()
{
    if (f == NULL)
    {
        printf("\n");
        space printf("No appointments booked yet.\n");
    }
    else
    {
        pat *t1 = r;

        /// simple f me abhi first node hai i.e first patient details hai jo further linked hai.

        space printf("Patient Name: %s\n", t1->name);
        space printf("Patient Age: %d\n", t1->age);
        space printf("Patient ID: %d\n", t1->id);
        space printf("Disease: %s\n", t1->dis);

        space printf("Doctor booked is %s\n", b[t1->doc - 1]);
        space printf("Your token number is %d\n", t1->tkn1);
        space printf("You have to come at %s\n\n\n", t1->time1);
        space printf("Bed Number: %d\n", t1->bedNumber);
        space printf("YOUR BILL\n\n");
        space printf("bill amount: Rs %0.2f\n", t1->bill);
        space printf("discount: Rs %0.2f \n", t1->discount);
        space printf("final bill to pay :Rs %0.2f\n", t1->final_bill);
        space printf("-----------------------------------------------\n\n\n");

        /// Stop when we circle back to the front
    }
}
void addToFile(){
    if(f==NULL)
        {
        printf("\n");
        space printf("No appointments booked yet.\n");
    }
    else{
        pat *t=r;
        FILE *fp=NULL;
        fp=fopen("HOSPITAL.txt","w");
        if(fp==NULL){
            space printf("Cant open file\n");
        }
        else{
            if(t->shift==1)
            fprintf(fp,"\n%-10s %-10d %-10d %-10s %-10s %-10d %-10s %-10s\n",t->name,t->age,t->id,t->dis, b[t->doc - 1].nm,t->tkn1,t->time1,"MORNING");
            else

            fprintf(fp,"\n%-10s %-10d %-10d %-10s %-10s %-10d %-10s %-10s\n",t->name,t->age,t->id,t->dis, b[t->doc - 1].nm,t->tkn1,t->time1,"EVENING");
        }
        fclose(fp);
    }

}
void searchById()
{
    char ch;
    if (f == NULL)
    {
        space printf("no appointment to search \n");
        return;
    }

    int pid, found = 0;
    pat *t = f;
    space printf("enter patient id to search: ");
    scanf("%d", &pid);
    do
    {
        if (t->id == pid)
        {
            found = 1;
            space printf("patient name : %s\n", t->name);
            space printf("age :%d \n", t->age);
            space printf("disease:%s \n", t->dis);
            space printf("token  :%d \n", t->tkn1);
            space printf("time :%s \n", t->time1);
            space printf("YOUR BILL\n\n");
            space printf("bill amount: Rs %0.2f\n", t->bill);
            space printf("discount: Rs %0.2f \n", t->discount);
            space printf("final bill to pay :Rs %0.2f\n", t->final_bill);
            space printf("--------------------------------------------\n");


            break;
        }
        t = t->next;
    } while (t != f);
    if (!found)
    {
        space printf("no appointment found with ID %d \n", pid);
    }
}

int main()
{
        // Initialize the bed stack
        initStack(&bedStack);
    int i, j, k, ch2, ch, docId;

    printf("\n\n\n\n");
    for (j = 1; j <= 6; j++)
    {

        space

            for (k = 1; k <= 40; k++)
        {

            if (k == 40 || k == 1 || j == 1 || j == 6)
                printf(".");
            else if (j == 3 && k >= 5 && k <= 35)
            {
                char text[] = "MAX HOSPITAL---------NEW DELHI";
                printf("%c", text[k - 5]); // Print each character one by one
            }

            else
                printf(" ");
        }

        printf("\n");
    }

    /// Calling the login Function which take the security handle and then if it return 0 program will not work further otherwise else will work
    if (!login())
    {
        exit(0);
    }

    else
    {
        while (1)
        {
            printf("\n\n\n\n");
            fflush(stdin);
            space printf("1.Book an appointment\n");
            space printf("2.Check todays appointment\n");
            space printf("3.Check particular doctor's appointments\n");
            space printf("4.Delete a apointment\n");
            space printf("5.search appointment by patient id\n");
            space printf("6.Cancel an appointment\n");
             space printf("7.Emergency appointment\n");
            space printf("Enter your choice  ");

            scanf("%d", &ch);
            printf("\n\n");

            switch (ch)
            {
            case 1:

                det();
                addToFile();
                printf("\n\n\n");
                space printf("THANKS FOR APPROACHING\t\t your appointment has been booked sucssessfully\n\n");
                space printf("HERE ARE YOUR DETAILS, PLEASE CHECK THE APPOINTMENT TIME \n\n");
                display1();

                break;

            case 2:

                space printf("TODAYS APPOINTMENTS\n\n");
                space printf("MORNING SHIFT\n");
                display(1);
                printf("\n\n");
                space printf("EVENING SHIFT\n");
                display(2);
                break;
            case 3:
                while (1)
                {
                    space printf("Enter Doctor's ID  ");
                    scanf("%d", &docId);

                    if (docId >= 1 && docId <= 6)
                    {
                        space printf("Patients Under the Doctor : %s\n", b[docId - 1].nm);
                        space printf("MORNING SHIFT\n");
                        PatientUnderDoctor(docId, 1);
                        printf("\n\n");
                        space printf("EVENING SHIFT\n");
                        PatientUnderDoctor(docId, 2);

                        break;
                    }
                    else
                        space printf("INVALID ID, Please Re-enter\n");
                }
                break;
            case 4:
                space printf("PROCESSING APPOINTMENT COMPLETION");
                printf("\n\n");
                deleteAppointment();
                break;
            case 5:
                searchById();
                break;
            case 6:
                 cancelAppointment();
                 break;
            case 7:
                emergencyCase();
                break;

            default:
                exit(0);
            }
            printf("\n\n\n");
        }
    }
}
