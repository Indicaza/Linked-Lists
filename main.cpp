// create a program that inserts 20 random integers from 0 to 100 into a vector
// the program will then that vector into a linked list
// the program will then create another vector containing 15 random integers from 0 to 100
// the program will then insert that vector into the linked list
// the program will then sort both linked lists from smallest to largest
// the program will then print the two linked lists
// the program will then merge the two linked lists into one linked list
// the program will then sort the merged linked list from smallest to largest
// the program will then print the merged linked list
// the program will then print the sum of the merged linked list
// the program will then print the average of the merged linked list
// finally the program will output all printed values to a file called output.txt

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;



class LinkedList {

public:


    struct node {
        int data;
        node* next;
    };


    // function to create a linked list from a vector
    node* createList(vector<int> v) {
        node* head = NULL;
        node* tail = NULL;
        for (int i : v) {
            node* temp = new node;
            temp->data = i;
            temp->next = NULL;
            if(head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
        }
        return head;
    }


    // function to sort a linked list from smallest to largest
    node* sortList(node *head) {
        node* temp = head;
        node* temp2 = head;
        while(temp != NULL) {
            temp2 = temp->next;
            while(temp2 != NULL) {
                if(temp->data > temp2->data) {
                    int temp_data = temp->data;
                    temp->data = temp2->data;
                    temp2->data = temp_data;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        return head;
    }


    // function to merge two linked lists
    node* mergeList(node* head1, node* head2) {
        node* temp = head1;
        node* temp2 = head2;
        node* head3 = NULL;
        node* tail3 = NULL;
        while(temp != NULL && temp2 != NULL) {
            if(temp->data < temp2->data) {
                node *temp3 = new node;
                temp3->data = temp->data;
                temp3->next = NULL;
                if(head3 == NULL) {
                    head3 = temp3;
                    tail3 = temp3;
                }
                else {
                    tail3->next = temp3;
                    tail3 = temp3;
                }
                temp = temp->next;
            } else {
                node *temp3 = new node;
                temp3->data = temp2->data;
                temp3->next = NULL;
                // if head3 is null, then this is the first node in the list
                if(head3 == NULL) {
                    head3 = temp3;
                    tail3 = temp3;
                } else {
                    tail3->next = temp3;
                    tail3 = temp3;
                }
                temp2 = temp2->next;
            }
        }
        if(temp != NULL) {
            while(temp != NULL) {
                node *temp3 = new node;
                temp3->data = temp->data;
                temp3->next = NULL;
                if(head3 == NULL) {
                    head3 = temp3;
                    tail3 = temp3;
                }
                else {
                    tail3->next = temp3;
                    tail3 = temp3;
                }
                temp = temp->next;
            }
        } else if(temp2 != NULL) {
            while(temp2 != NULL) {
                node *temp3 = new node;
                temp3->data = temp2->data;
                temp3->next = NULL;
                if(head3 == NULL) {
                    head3 = temp3;
                    tail3 = temp3;
                } else {
                    tail3->next = temp3;
                    tail3 = temp3;
                }
                temp2 = temp2->next;
            }
        }
        return head3;
    }


    // function to remove duplicates from a linked list
    node *removeDuplicates(node *head) {
        node *temp = head;
        node *temp2 = head;
        while(temp != NULL) {
            temp2 = temp->next;
            while(temp2 != NULL) {
                if(temp->data == temp2->data) {
                    temp->next = temp2->next;
                    temp2 = temp->next;
                } else {
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }


    // function to return the sum of a linked list
    int sumList(node *head) {
        int sum = 0;
        node *temp = head;
        while(temp != NULL) {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }


    // function to return the average of a linked list
    double averageList(node *head) {
        int sum = 0;
        int count = 0;
        node *temp = head;
        while(temp != NULL) {
            sum += temp->data;
            count++;
            temp = temp->next;
        }
        return (double)sum / count;
    }


    // function to create output.txt file
    void createOutput(node* head1, node* head2, node* head3) {
        ofstream output;
        output.open("output.txt");

        output << "List 1: " << endl;
        node *temp1 = head1;
        while(temp1 != NULL) {
            output << temp1->data << " ";
            temp1 = temp1->next;
        }
        output << endl;
        output << endl;

        output << "List 2:" << endl;
        node *temp2 = head2;
        while(temp2 != NULL) {
            output << temp2->data << " ";
            temp2 = temp2->next;
        }
        output << endl;
        output << endl;

        output << "List 3: " << endl;
        node *temp3 = head3;
        while(temp3 != NULL) {
            output << temp3->data << " ";
            temp3 = temp3->next;
        }
        output << endl;
        output << endl;

        output << "The sum of the linked list is: " << sumList(head3) << endl;
        output << "The average of the linked list is: " << averageList(head3) << endl;
        output.close();
    }
};



int main() {

    vector<int> vector1;
    vector<int> vector2;

    srand(time(0));

    for(int i = 0; i < 20; i++) {
        vector1.push_back(rand() % 100);
    }

    for(int i = 0; i < 15; i++) {
        vector2.push_back(rand() % 100);
    }


    LinkedList linkedList;

    LinkedList::node *head1 = linkedList.createList(vector1);
    head1 = linkedList.sortList(head1);
    head1 = linkedList.removeDuplicates(head1);

    LinkedList::node *head2 = linkedList.createList(vector2);
    head2 = linkedList.sortList(head2);
    head2 = linkedList.removeDuplicates(head2);

    LinkedList::node *head3 = linkedList.mergeList(head1, head2);
    head3 = linkedList.sortList(head3);
    head3 = linkedList.removeDuplicates(head3);


    linkedList.createOutput(head1, head2, head3);


    return 0;
}
