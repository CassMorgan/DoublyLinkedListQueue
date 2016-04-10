//Cass Morgan II
//CSC 375 Homework 03
//Date 04/09/16

#include <iostream>
#include "queue.h"
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

    Queue<Profile> p_list;
    Profile temp;
    string line;

    ifstream file("presidents.txt");

if (file.is_open())
{
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, temp.name, '\t');
        getline(ss, temp.state, '\t');
        p_list.enqueue(temp);
    }
}

    //testing print_forward()
    cout<< "Printing the queue list from front to back..." <<endl<<endl;
    p_list.print_forward();

    // testing enqueue()
    Profile my_name;
    my_name.name = "Cass Lewis Morgan II";
    my_name.state = "MI";

    p_list.enqueue(my_name);
    cout<< "\nPrinting the queue front to back after enqueue of my_name..." <<endl<<endl;
    p_list.print_forward();

    p_list.dequeue(my_name);
    cout<< "\nDequeue() called.." <<endl<<endl;
    p_list.print_forward();

    // testing print_backward()
    cout<< "\nPrinting the queue from back to front..." <<endl<<endl;
    p_list.print_backward();

    // testing make_empty()
    cout<< "\nmake_empty() called..." <<endl;
    p_list.make_empty();

    // testing is_empty()
    p_list.is_empty();

    file.close();
    return 0;
}
