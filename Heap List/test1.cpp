#include "program1.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int depth, priority, job;

    /*
    Initial test block. Ensures the heap starts empty and all functions
    Work correctly when empty.
    */
    depth = GetDepth(16);
    if (depth != -1)
    {
        cout << "Incorrect depth 0";
        return -1;
    }
    priority = GetPriority(0); // Get priority causes a segemntation fault. Needs to be fixed.
    if (priority != -1)
    {
        cout << "Incorrect priority 0";
        return -1;
    }
    job = GetJob();
    if (job != -1)
    {
        cout << "Incorrect job 0";
        return -1;
    }

    /*
    This test block. Ensures adding works correctly, initial depth
    is calculated correctly, and that GetPriority will work correctly given
    a correct index.
    */
    AddJob(18);
    AddJob(20);
    AddJob(59);
    depth = GetDepth(59);
    if (depth != 0)
    {
        cout << "Incorrect depth 1";
        return -1;
    }
    depth = GetDepth(20);
    if (depth != 1)
    {
        cout << "Incorrect depth 2";
        return -1;
    }
    depth = GetDepth(5);
    if (depth != -1)
    {
        cout << "Incorrect depth 3";
        return -1;
    }
    priority = GetPriority(1);
    if (priority != 59)
    {
        cout << "Incorrect priority 1";
        return -1;
    }
    priority = GetPriority(2);
    if (priority != 18)
    {
        cout << "Incorrect priority 2";
        return -1;
    }
    priority = GetPriority(3);
    if (priority != 20)
    {
        cout << "Incorrect priority 3";
        return -1;
    }

    /*
        This block ensures jobs get added correctly, and checks depth
        to ensure growth is correct, and depth calculation is correct.
        */
    AddJob(15);
    AddJob(80);
    AddJob(12);
    depth = GetDepth(80);
    if (depth != 0)
    {
        cout << "Incorrect depth 3";
        return -1;
    }
    depth = GetDepth(12);
    if (depth != 2)
    {
        cout << "Incorrect depth 4";
        return -1;
    }
    depth = GetDepth(-5);
    if (depth != -1)
    {
        cout << "Incorrect depth 5";
        return -1;
    }

    /*
     This block ensure that GetPriority works correctly.
     All items should be at the index specified, and the last one
     ensures that it will fail correctly given a wrong priority.
     */
    priority = GetPriority(1);
    if (priority != 80)
    {
        cout << "Incorrect priority 4";
        return -1;
    }
    priority = GetPriority(2);
    if (priority != 18)
    {
        cout << "Incorrect priority 5";
        return -1;
    }
    priority = GetPriority(3);
    if (priority != 20)
    {
        cout << "Incorrect priority 6";
        return -1;
    }
    priority = GetPriority(4);
    if (priority != 15)
    {
        cout << "Incorrect priority 7";
        return -1;
    }
    priority = GetPriority(5);
    if (priority != 59)
    {
        cout << "Incorrect priority 8";
        return -1;
    }
    priority = GetPriority(6);
    if (priority != 12) // This goes missing??
    {
        cout << "Incorrect priority 9";
        return -1;
    }
    priority = GetPriority(87);
    if (priority != -1)
    {
        cout << "Incorrect priority 10";
        return -1;
    }
    /*
    This block ensure that adding negative values doesn't work,
    by checking the depth of the negative value that was added.
    Also does a priority check.
    */
    AddJob(-7);
    depth = GetDepth(-7);
    if (depth != -1)
    {
        cout << "Incorrect depth 9";
        return -1;
    }

    job = GetJob();
    if (job != 80)
    {
        cout << "Incorrect job 1";
        return -1;
    }
    printList();
    job = GetJob();
    if (job != 59)
    {
        cout << job << endl
            << endl;
        cout << "Incorrect job 2";
        return -1;
    }
    printList();
    priority = GetPriority(1);
    if (priority != 20)
    {
        cout << "Incorrect priority 11";
        return -1;
    }
    AddJob(21);
    cout << "\n Added 21";
    printList();
    AddJob(22);
    cout << "\n Added 22";
    printList();
    AddJob(23);
    cout << "\n Added 23";
    printList();
    /*
    This block ensures that when the heap reorders itself correctly when
    removing items that have been in the queue for a long time.
    All items will increment by two after being in after 5 GetJobs.
    Also tests to make sure that if you call remove on an empty heap,
    it returns the correct value.
    Will also try GetPriority and GetDepth on empty heap, to ensure
    correct return values.
    */
    job = GetJob();
    if (job != 23)
    {
        cout << "\n Incorrect job 3";
        return -1;
    }
    //printList();
    job = GetJob();
    if (job != 22)
    {
        cout << "Incorrect job 4";
        return -1;
    }
    printList();
    AddJob(20);
    cout << "\n Added 20";
    printList();
    job = GetJob(); // Broken
    if (job != 21)
    {
        cout << "Incorrect job 5";
        return -1;
    }
    // printList();
    job = GetJob();
    if (job != 22)
    {
        cout << "Incorrect job 6";
        return -1;
    }
    printList();
    job = GetJob();
    if (job != 22)
    {
        cout << "Incorrect job 7";
        return -1;
    }
    printList();
    job = GetJob();
    if (job != 21)
    {
        cout << "Incorrect job 8";
        return -1;
    }
    printList();
    // This is where the code is breaking. 12 turns into 18 for some reason..
    job = GetJob();
    if (job != 20)
    {
        cout << "Incorrect job 9";
        return -1;
    }
    job = GetJob();
    if (job != 22)
    {
        cout << "Incorrect job 10";
        return -1;
    }
    job = GetJob();
    if (job != -1)
    {
        cout << "Incorrect job 11";
        return -1;
    }
    depth = GetDepth(20);
    if (depth != -1)
    {
        cout << "Incorrect depth 10";
        return -1;
    }
    priority = GetPriority(0);
    if (priority != -1)
    {
        cout << "Incorrect priority 12";
        return -1;
    }
    priority = GetPriority(36);
    if (priority != -1)
    {
        cout << "Incorrect priority 13";
        return -1;
    }
    priority = GetPriority(4);
    if (priority != -1)
    {
        cout << "Incorrect priority 14";
        return -1;
    }

    /*
    This giant ass test block ensure expansion works correctly, and that
    the heap grows in the correct order.
    It also calls GetJob too many times, to ensure the heap empties
    correctly, and that priorities increment and reorder correctly.
    */
    AddJob(1);
    AddJob(2);
    AddJob(3);
    AddJob(4);
    AddJob(5);
    AddJob(6);
    AddJob(7);
    AddJob(8);
    AddJob(9);
    AddJob(10);
    AddJob(11);
    AddJob(12);
    AddJob(13);
    AddJob(14);
    AddJob(15);
    AddJob(16);
    AddJob(17);
    AddJob(18);
    AddJob(19);
    AddJob(20);
    job = GetJob();
    if (job != 20)
    {
        cout << "Incorrect job 12";
        return -1;
    }

    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();
    job = GetJob();

    /*
    This text block adds a bunch of items, and then empties the heap.
    Then, calls all the initial test block functions to ensure
    Empty Heap works correctly.
    */
    AddJob(1);
    AddJob(2);
    AddJob(3);
    AddJob(4);
    AddJob(5);
    AddJob(6);
    AddJob(7);
    AddJob(8);
    AddJob(9);
    AddJob(10);
    AddJob(11);
    AddJob(12);
    AddJob(13);
    AddJob(14);
    AddJob(15);
    AddJob(16);
    AddJob(17);
    AddJob(18);
    AddJob(19);
    AddJob(21);
    AddJob(22);
    AddJob(23);
    AddJob(24);
    AddJob(25);
    AddJob(26);
    AddJob(27);
    AddJob(28);
    AddJob(29);
    AddJob(30);
    AddJob(31);
    AddJob(32);
    AddJob(33);
    // EmptyHeap();
    priority = GetPriority(23);
    cout << priority << endl;
    depth = GetDepth(8);
    cout << depth;
    cout << endl
        << endl;
    cout << "You have ascended." << endl
        << endl
        << endl;
    return 0;
}