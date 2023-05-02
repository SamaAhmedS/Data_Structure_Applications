/*
    Name : Sama Ahmed Saeed       

*/

#include "SingleLinkedListWithProblems.cpp"
#include "Stack.cpp"
#include "DoubleLinkedList.cpp"
#include "ArrayBasedList.cpp"
#include "Queue.cpp"

int main() {

    // test on array based list functions
    // Don't remove all comments in one time 
    // test each function one by one 


   /* ArrayBasedList<int> arr;
    arr.insert(2);
    cout << arr.listSize() << endl;
    arr.insert(9);
    arr.insert(3);
    arr.print();
    arr.insertAt(8, 2);
    arr.insertAt(99,4);
    arr.print();
    arr.removeAt(2);
    arr.print();
    cout<<arr.isEmpty()<<endl;
    cout<<arr.isFull()<<endl;
    cout<<arr.isItemAtEqual(9, 1)<<endl;
    cout<<arr.listSize()<<endl;
    cout<<arr.maxListSize()<<endl;
    cout<<arr.retrieveAt(1)<<endl;
    arr.insert(56);
    arr.print();
    arr.replaceAt(7,3);
    arr.print();
    arr.insertAt(47,5);
    arr.print();*/

//----------------------------------------------------------------------------------------------------------------------
    // Test on single Linkedlist Functions
    // Don't remove all comments in one time 
    // test each function one by one 


    //singleLinkedList<int> l;
    // cout<<l.isEmpty()<<endl;
    // l.insertAtTail(7);
    // l.insertAtTail(8);
    // l.print();
    // l.insertAtTail(45);
    // l.print();
    // l.insertAtHead(78);
    // l.print();
    // l.insertAt(55 , 3);
    // l.print();
    // cout<<l.isEmpty()<<endl;
    // cout<<l.isExist(45)<<endl;
    // cout<<l.isItemAtEqual(45 , 4)<<endl;
    // cout<<l.linkedListSize()<<endl;
    // cout<<l.retrieveAt(4)<<endl;
    // l.replaceAt(32 , 3);
    // l.print();
    // l.swap(0 ,4);
    // l.print();
    // l.removeAtHead();
    // l.print();
    // l.removeAtTail();
    // l.print();
    // l.removeAt(1);
    // l.print();
    // l.removeAtTail();
    // l.print();
    // l.removeAtHead();
    // l.print();// l.clear();
    // cout<<l.isEmpty()<<endl;


//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------



    // Test on merge function

     //singleLinkedList<int> l11;
     //l11.insertAtTail(55);
     //l11.insertAtTail(77);
     //l11.insertAtTail(99);

     //singleLinkedList<int> l2;
     //l2.insertAtTail(5);
     //l2.insertAtTail(9);
     //l2.insertAtTail(10);

     //singleLinkedList<int> l3;
     //l3.insertAtTail(2);
     //l3.insertAtTail(4);
     //l3.insertAtTail(6);
     //l3.insertAtTail(9);


     //vector<node<int>*> k;
     //k.push_back(l11.get_First());
     //k.push_back(l2.get_First());
     //k.push_back(l3.get_First());


     //singleLinkedList<int> l4;

     //l4 = Merge(k);
     //
     //l4.print();
     //l4 = l2;
     //l4.print();
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------


    // Test on Combine between zeros function

    //singleLinkedList<int> l12 ;
    //l12.insertAtTail(0);
    //l12.insertAtTail(1);
    //l12.insertAtTail(2);
    //l12.insertAtTail(3);
    //l12.insertAtTail(0);
    //l12.insertAtTail(7);
    //l12.insertAtTail(8);
    //l12.insertAtTail(0);
    //l12.print();
    //l12 = CombineNodesBetZeros(l12);
    //l12.print();

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------



  // Test on double linked list function 
    // Don't remove all comments in one time 
    // test each function one by one 

    // DoublyLinkedList<int> dl;
    // cout<<dl.isEmpty()<<endl;
    // dl.insertAtTail(7);
    // dl.insertAtTail(8);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.insertAtTail(45);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.insertAtHead(78);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dNode<int>* cur = dl.get_First();
    // dl.insertAfter(cur->next, 16);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.reverse();
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.insertAt(55 , 4);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // cout<<dl.isEmpty()<<endl;
    // cout<<dl.isExist(78)<<endl;
    // cout<<dl.isItemAtEqual(78 , 0)<<endl;
    // cout<<dl.doubleLinkedListSize()<<endl;
    // cout<<dl.retrieveAt(2)<<endl;
    // dl.replaceAt(32 , 3);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.swap(0 ,4);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.removeAtHead();
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.removeAtTail();
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.removeAt(1);
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.removeAtTail();
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.removeAtHead();
    // dl.forwardTraversal();
    // dl.backwardTraversal();
    // dl.removeAtHead();
    // cout<<dl.isEmpty()<<endl;

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

    // Test on Stack Functions
    // Don't remove all comments in one time 
    // test each function one by one 

    // Stack<int> s;
    // cout<<s.isEmpty()<<endl;
    // s.push(45);
    // s.push(12);
    // s.push(95);
    // s.print();             // top from right to left
    // cout<<s.isEmpty()<<endl;
    // cout<<s.stackSize()<<endl;
    // cout<<s.top()<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.isEmpty()<<endl;
    // s.pop();
 
//---------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

    // test on convert from infix to postfix function 

    // infixConvert("X^Y / (5*Z) + 2");
    // infixConvert("A + B * C + D");
    // infixConvert("(A + B) * (C + D)");
    // infixConvert("2 + ((8 + 2 * 3) /2 ) - 1");

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

    // Test on Queue Functions
    // Don't remove all comments in one time 
    // test each function one by one 

     //Queue<int> q,q2;
     //cout<<q.isEmpty()<<endl;
     //q.enqueue(78);
     //q.enqueue(45);
     //q.enqueue(32);
     //q.print();
     //q2 = q;
     //q2.print();
     //q.dequeue();
     //q.print();
     //cout<<q.isEmpty()<<endl;
     //cout<<q.queueSize()<<endl;
     //q.dequeue();
     //q.dequeue();
     //cout<<q.isEmpty()<<endl;
     //cout<<q.queueSize()<<endl;


}