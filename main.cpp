#include <iostream>
using namespace std;

// Node class (used for trains, train details, and customer queue)
class Node {
public:
    // Common train information
    int trainID;
    string trainName;
    int availableSeats;
    string destination;
    Node* next;

    // For train detail stack
    string detail;
    Node* detailTop;

    // For customer queue
    string customerName;

    // Constructor for Train Node
    Node(int id, string name, string des, int seats) {
        trainID = id;
        trainName = name;
        availableSeats = seats;
        destination = des;
        next = nullptr;
        detailTop = nullptr;
    }

    // Constructor for Stack Node
    Node(string d) {
        detail = d;
        next = nullptr;
    }

    // Constructor for Customer Queue Node
    Node(string cname, int id) {
        customerName = cname;
        trainID = id;
        next = nullptr;
    }
};

// Global pointers
Node* trainHead = nullptr;       // Linked list for trains
Node* customerFront = nullptr;   // Queue front
Node* customerRear = nullptr;    // Queue rear

// Push formatted train info to stack
void pushTrainInfoToStack(Node* train) {
    string detail = "ID: " + to_string(train->trainID) + ", Name: " + train->trainName +
                    ", Destination: " + train->destination +
                    ", Seats: " + to_string(train->availableSeats);

    Node* newDetail = new Node(detail);
    newDetail->next = train->detailTop;
    train->detailTop = newDetail;
}

// Install a train and save details in its stack
void installTrain(int id, string name, string des, int seats) {
    Node* newTrain = new Node(id, name, des, seats);
    newTrain->next = trainHead;
    trainHead = newTrain;

    pushTrainInfoToStack(newTrain); // Save info to stack
    cout << "Train record installed successfully!\n";
}

// Reserve a ticket
void reserveTicket(string cname, string des, int tid) {
    Node* temp = trainHead;
    while (temp != nullptr) {
        if (temp->trainID == tid) {
            if (temp->availableSeats > 0) {
                Node* newCustomer = new Node(cname, tid);
                if (customerFront == nullptr) {
                    customerFront = customerRear = newCustomer;
                } else {
                    customerRear->next = newCustomer;
                    customerRear = newCustomer;
                }
                temp->availableSeats--;
                cout << "Ticket reserved for " << cname << " in Train: " << temp->trainName << "\n";
            } else {
                cout << "No seats available in this train!\n";
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Train ID not found!\n";
}

// Show details of a single train
void showTrainDetails(int tid) {
    Node* temp = trainHead;
    while (temp != nullptr) {
        if (temp->trainID == tid) {
            /*cout << "Train ID: " << temp->trainID << "\n";
            cout << "Train Name: " << temp->trainName << "\n";
            cout << "Destination: " << temp->destination << "\n";
            cout << "Available Seats: " << temp->availableSeats << "\n";*/
            cout << "Saved Detail (from stack):\n";
            if (temp->detailTop != nullptr) {
                cout << "  " << temp->detailTop->detail << "\n";
            } else {
                cout << "  No details saved.\n";
            }
            return;
        }
        temp = temp->next;
    }
      cout << "Train ID not found!\n";
}

// Show all train records
void showAllTrains() {
    Node* temp = trainHead;
    if (temp == nullptr) {
        cout << "No trains available.\n";
        return;
    }
    cout << "All Train Report:\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->trainID
             << ", Name: " << temp->trainName
             << ", Destination: " << temp->destination
             << ", Seats: " << temp->availableSeats << "\n";
        temp = temp->next;
    }
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n--- Train Ticket Reservation System ---\n";
        cout << "1. Install Train Record (Admin Only)\n";
        cout << "2. Reserve Ticket\n";
        cout << "3. Show Train Details\n";
        cout << "4. Show All Trains\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            string username, password;
            cout << "Enter Admin Username: ";
            cin >> username;
            cout << "Enter Admin Password: ";
            cin >> password;

            if (username == "cse207" && password == "section5") {
                int id, seats;
                string name, des;
                cout << "Access granted. Please, install train record...\n";
                cout << "Enter Train ID: ";
                cin >> id;
                cin.ignore(); // clear buffer
                cout << "Enter Destination: ";
                getline(cin, des);
                cout << "Enter Train Name: ";
                getline(cin, name);
                cout << "Enter Number of Seats: ";
                cin >> seats;
                installTrain(id, name, des, seats);
            } else {
                cout << "Access Denied! Invalid Username or Password.\n";
            }
        }
        else if (choice == 2) {
            string cname, des;
            int tid;
            cin.ignore(); // clear buffer
            cout << "Enter Customer Name: ";
            getline(cin, cname);
            cout << "Enter Your Destination: ";
            getline(cin, des);
            cout << "Enter Train ID to reserve: ";
            cin >> tid;
            reserveTicket(cname, des, tid);
        }
        else if (choice == 3) {
            int tid;
            cout << "Enter Train ID to view details: ";
            cin >> tid;
            showTrainDetails(tid);
        }
        else if (choice == 4) {
            showAllTrains();
        }
        else if (choice == 5) {
            cout << "Thank you for using Online Train Reservation\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

