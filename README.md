# Hospital-Management-System-in-C
Implementation of Hospital Management System in C using priority queues.

Introduction:
Hospital are the essential part of our lives, providing best medical facilities to people suffering from various ailments, 
which may be due to change in climatic conditions, increased work-load, emotional trauma stress etc. 
It is necessary for the hospitals to keep track of its day-to-day activities & records of its patients.
But keeping track of all the activities and their records on paper is very cumbersome and error prone. 
It also is very inefficient and a time-consuming process Observing the continuous increase in population and 
number of people visiting the hospital. 
Recording and maintaining all these records is highly unreliable, inefficient and error-prone. 
It is also not economically & technically feasible to maintain these records on paper. 
Thus keeping the working of the manual system as the basis of our project. 
We have developed an automated version of the manual system, named as “Hospital Management System”


Aim: The project “Hospital management system” is aimed to develop to maintain the day –to-day state of admission/discharge of patients.

It is designed to achieve the following objectives: 
1. To computerize all details regarding patient details. 
2. Scheduling the appointment of patient with doctors to make it convenient for both. 
3. Scheduling the services of specialized doctors and emergency properly,
so that facilities provided by hospital are fully utilized in effective and efficient manner.
 
Data Structures used: Priority Queues

Functionality:

Our project mainly focusses on keeping track of patients who are admitted
This project has 4 modules

1.Adding a new patient
	
	The records of every patient admitted are to be kept.
	Above module handles this.
	This module has a field 'emergency' which actually tells the severeness of the disease, the patient currently having
	so this tells about how quickly he/she should be diagnosed.
	
2.Discharging a admitted patient
	
	As mentioned above,
	the person with high emergency sholud be treated first,
	So in this process,
	the person with high emergency or more severeness is discharged first.
	
3.Search a patient
	
	This module helps in searching a patient,
	whether he/she is admitted or not.
	
4.Dispalying all the admitted patients
	
	This module helps in managing and running the hospital,
	it displays all the patients to be treated yet,
	So helps in managing  and estimating time.
	
Atlast,

Advantages:
	The project Hospital Management System (HMS) is for computerizing the working in a hospital. 
	It is a great improvement over the manual system. The computerization of the system with speed up the process.
	This project helps in treating the emergency case first
	which helps in saving lot many lives as possible.
	
Drawback:
	This project deals with only patients records
	It can be extended to all hospital staff such as doctors
	which makes it more effective.
	
(Note: This was tested on Windows10,
gcc --version - gcc (MinGW.org GCC-8.2.0-1) 8.2.0)

Steps to Run:

--> gcc main.c

--> a

(after successfull completion of execution, a local file named "patients.txt" gets created, which contains the records of patient)
