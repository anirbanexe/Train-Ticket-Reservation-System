# Train-Ticket-Reservation-System
A simple C++ Train Ticket Reservation System using linked list, stack, and queue. Admins can install train records with seat availability, while customers can reserve tickets. Features include storing train details in a stack, maintaining a customer queue, and displaying train reports.
Train Ticket Reservation 
3 
Introduction:  
The Train Ticket Reservation System is a simple C++ console application designed to simulate a basic train reservation mechanism. The project will help people to understand real word problems using some data structures like Linked List (Singly Linked List) and Queue in their practical field.  This system allows administrators to manage train records, and passengers to reserve their tickets.  And also, some things are being used by both the administrators and passengers as well. The primary goal of this project is to demonstrate the basic practical implementation of data structures in a real-world scenario.  
Data Structures Used:  
1. Linked List: - Linked list is mainly used to make the size dynamic. We have used Singly  Linked List here.  Actually, we don’t know how many trains or customers will be added. So we had to use linked list so that we can add as much as we want. Besides, insertion in linked list is easy.  
2. Queue: - Used for storing customer reservations in the order they are made (FIFO). Each node stores the customer name and train ID. Mainly Queue is used to reserve the sits in train. The main concept of FIFO is first in first out. So the passenger who booked the ticket first will get the ticket first. To maintain this sequence we used queue.  
3. Stack:- Stack is optional here we can use it on storing the train details here. But for future enhancements, if we want to update the code like if we want to add storing train logs or history we can use stack. The key concept of the stack is last in first out. So we can see history using the stack. 
4. Node Class:- A single Node class is reused to represent train records, customer reservations, and stack (we have commented here). Also, another node class is declared for using the Queue data structure in the code. These demonstrate object reuse and dynamic memory allocation using constructors. 
Functionalities: 
In this project is based on mainly two features or functionalities. 
One is Admin feature, and another one is Passenger feature. 
At first we need to choose a Valid Number from the menu. Otherwise, the system will show “Invalid Choice” in the output.
In admin feature we used- 
At first it requires a USERNAME and a PASSWORD for accessing the admin mode. So that, not everyone can entry the train details to the system without authorized people. If the person enters either the USERNAME or the PASSWORD wrong, the system will deny access.
Install Train Record: Add new trains with details like ID, name, destination, and available seats.
A function named installTrain is called in the main method to perform it’s functionalities of adding train details using the choice 1 from menu. Each train’s data is stored in a single node of the data structure. Like this, we can install data in the system for multiple times for multiple trains. Each train detail will be recorded on a new node of Singly Linked List.
Show Train Details: View details of a specific train by entering its ID. Under the menu choices, if we select Show Train Details, it calls showTrainDetails function in the main method and display the specific train details using the Searching Operation of Singly Linked List. If there is no train record installed in the system, the output shows, “Train Not Found.”
Show All Trains: The function showAllTrains is used to view all the available trains and their data. It is also selected from the main method and if there is no train record installed in the system, the output shows, “No Train Available.” The function is used to display all the train details together that are installed on the system using Linked List data structure. Even if anyone reserves a seat in a particular train the function is being updated and then show the data again if required.

In passenger feature we used- 
A passenger can use ‘Show Train Details’ and ‘Show All Trains’ function and see train data as well like an Admin.
Reserve Ticket: Reserve a seat in a specific train by providing a customer’s name and train ID. When a customer is trying to reserve a seat in a train he remains in a queue. Which allows the customer to get ‘FIRST COME, FIRST SERVICE’ which maintains the FIFO characteristics of Queue data structure. If a customer tries to enter the system for reserving a seat the function reserveTicket checks if the customer is behind any other customer or not. If not, then the customer is declared as a new customer and he/she can reserve any seat. If any new customer is behind any other customer, then the customer is placed after the previous customer in the data structure. Thus, the reservation is being completed, and the seat number decreases in the system for any particular train.
Exit: After completing the required work on the system, we can simply exit the system by choosing Exit option, and it shows a Thank you message. It can be used by both admin and customers.

Advantages and Future Work:
1.	The program is easy to understand, and it can be modified in future according to administrators’ demands. 
2.	The program maintains security for the authorized people and ensures that no unnecessary train record is being installed on the system.
3.	The basics of data structure like Linked List and Queue are followed here.
4.	There is no size limitations needed as we used dynamic memory allocation.
Limitations of using this program: 
In this program we haven’t use any function for payment. So, the passengers can’t use this program efficiently. Besides, we haven’t mentioned the price of the tickets for different categories. If we add those categories and also mention the price then it will be more easier to use for the customers. On the other hand, we haven’t also mentioned the time schedule of trains. There is no return policy of ticket in this program also. So, this are some limitations of this program. Also, we have to install the train details again and again after we exit the system. This is a backoff for this project. 

Conclusion:
This project provides a simplified yet efficient simulation of a train ticket reservation system using C++. It combines multiple core concepts such as linked lists, queues, and Stack to solve a real-life problem. Though simple but the project serves as a stepping stone for developing more advanced systems
