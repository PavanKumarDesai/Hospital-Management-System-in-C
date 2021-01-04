#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct PatientDetails {
char firstname[20];
char lastname[20];
int age;
int priority;
 };
typedef struct PatientDetails Patient;

struct node {
 Patient c;
 struct node *link;
 };
typedef struct node node_t;

struct priority_queue {
	node_t *head;
}; typedef struct priority_queue priority_queue_t;

void init(priority_queue_t *p_queue);
void add_new_patient(priority_queue_t *p_queue, const Patient* p_comp);
void discharge(priority_queue_t *p_queue, Patient* p_comp);
void disp(const priority_queue_t* p_q);
void clean_queue(priority_queue_t *p_queue);
void searchpatient(const priority_queue_t* p_q);

int main()
{
	priority_queue_t q;
	init(&q);
	Patient c;
	FILE *fp;
	fp = fopen("patients.txt","a+");
	int option;
	system("cls");
	printf("                                   ************************************\n\n");
	printf("                                        Select Your option :\n");
	printf("                                        1 :Add a new patient\n");
	printf("                                        2 :Discharge patient\n");
	printf("                                        3 :View all Patients Admitted\n");
	printf("                                        4 :Search a Patient\n");
	printf("                                        0 :exit\n\n\n");
	printf("                                   ************************************\n\n");
	scanf("%d", &option);
	system("cls");
	while(option != 0)
	{
		switch(option)
		{
			case 1:
					printf("Enter patient Firstname : \n");
					scanf("%s", c.firstname);
					printf("Enter patient Lastname : \n");
					scanf("%s",c.lastname);
					printf("Enter patient Age : \n");
					scanf("%d",&c.age);
					printf("Explain Emergency on a scale of 1-10: \n");
					printf("(note:higher number implies high emergency)\n");
					scanf("%d",&c.priority);
					add_new_patient(&q, &c);
					fprintf(fp,"%s %s\n",c.firstname,c.lastname);
					break;
			case 2 :
					discharge(&q, &c);
					break;
			case 3:
					disp(&q);
					break;
			case 4:
					searchpatient(&q);
					break;
		}
	printf("                                   ************************************\n\n");
	printf("                                        Select Your option :\n");
	printf("                                        1 :Add a new patient\n");
	printf("                                        2 :Discharge patient\n");
	printf("                                        3 :View all Patients Admitted\n");
	printf("                                        4 :Search a Patient\n");
	printf("                                        0 :exit\n\n\n");
	printf("                                   ************************************\n\n");
	scanf("%d", &option);
	system("cls");
	}
clean_queue(&q);
fclose(fp);

}


void init(priority_queue_t *p_queue)
{
p_queue->head = NULL;
}

void add_new_patient(priority_queue_t *p_queue, const Patient* p_comp)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->c.priority = p_comp->priority;
	strcpy(temp->c.firstname, p_comp->firstname);
	strcpy(temp->c.lastname, p_comp->lastname);
	temp->c.age = p_comp->age;
	temp->link = p_queue->head;
	p_queue->head = temp;
}

void discharge(priority_queue_t *p_queue, Patient* p_comp)
{
	int y,z;
    printf("\n\n");
	node_t* prev = NULL;
	node_t* pres = p_queue->head;
	int max = 0;
	node_t* prev_max;
	if(pres == NULL)
    {
        printf("All Patients discharged\n");
		return;
    }
	else
	{
	while(pres != NULL)
	{
		if(pres->c.priority >= max)
		{
			max = pres->c.priority;
			prev_max = prev;
		}
		prev = pres;
		pres = pres->link;
	}
	node_t* temp;
	if(prev_max != NULL )
	{
		strcpy(p_comp->firstname, prev_max->link->c.firstname);
		strcpy(p_comp->lastname, prev_max->link->c.lastname);
		p_comp->priority = prev_max->link->c.priority;
		p_comp->age = prev_max->link->c.age;
		temp = prev_max->link;
		prev_max->link = prev_max->link->link;
		printf("Discharged Patient Details:\n");
		printf("Patient Name:%s %s\n",temp->c.firstname,temp->c.lastname);
		printf("Patient Age:%d\n",temp->c.age);
		free(temp);
	}
	else
	{
		strcpy(p_comp->firstname, p_queue->head->c.firstname);
		strcpy(p_comp->lastname, p_queue->head->c.lastname);
		p_comp->age = p_queue->head->c.age;
		p_comp->priority = p_queue->head->c.priority;
		temp = p_queue->head;
		p_queue->head = p_queue->head->link;
		printf("Discharged Patient Details:\n");
		printf("Patient Name:%s %s\n",temp->c.firstname,temp->c.lastname);
		printf("Patient Age:%d\n",temp->c.age);
		free(temp);
	}
	}
	
}


void disp(const priority_queue_t* p_q)
{
    printf("\n\n");
	node_t *p = p_q ->head;
    if(p == NULL)
	{
		printf("No Patients Found\n");
	}
	else
	{
		while(p != NULL)
		{
			printf("Patient Name:%s %s\nPatient Age:%d\nPatient Emergency:%d\n\n",p->c.firstname,p->c.lastname,p->c.age,p->c.priority);
			p = p->link;
		}
	}

}

void searchpatient(const priority_queue_t* p_q)
{
    printf("\n\n");
	char pn[20];
	int x;
	printf("Enter Patient's firstname\n");
	scanf("%s",pn);
	node_t *p=p_q->head;
	if(p==NULL)
	{
		printf("Patient not found\n");
	}
	else
	{
		while(p!=NULL)
		{
			x=strcmp(p->c.firstname,pn);
			if(x==0)
			{
				printf("Patient found\n");
				printf("Patient Name:%s %s\n",p->c.firstname,p->c.lastname);
				printf("Patient Age:%d\n",p->c.age);
				return;
			}
			else
			{
				p=p->link;
			}

		}
		printf("Patient not found\n");
		return;
	}
}

void clean_queue(priority_queue_t *p_queue)
{
	node_t* p=p_queue->head;
	node_t* r;
	while(p!=NULL)
	{
		r=p;
		p=p->link;
		free(r);
	}
}







