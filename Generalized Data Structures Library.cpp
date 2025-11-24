#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of queue
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        T Dequeue();
        void Display();
        int Count();
};

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void QueueX<T> :: Enqueue(T no) // InsertLast
{
    struct Queuenode<T> *temp = NULL;
    struct Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
T QueueX<T> :: Dequeue()         // DeleteFirst
{
    struct Queuenode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int QueueX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of stack
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: Push(T no) // InsertFirst
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: Pop()         // DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of singly circular linked list
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyCLL
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is constructor of class Singly_Circular_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertFirst
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Singly Circular Linked List.
//
//	Returns:
//		Integer
//		If the function succeeds, the return value .
//	
//
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertLast
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Singly Circular Linked List.
//
//	Returns:
//		void
//		The input given by the user is added at the end using InsertLast."
//	
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes first node from Singly Circular Linked List.
//
//	Returns:
//		void
//
////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes LAst node from Singly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function displays Singly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Count
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Singly Circular Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//					NONE
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Singly Circular Linked List.
//
//	Returns:
//		void
//		
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Singly Circular Linked List.
//
//	Returns:
//		Integer
//		    "Insert the data at the given position."
//           
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of doubly cirular Linked List
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyCLL
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is constructor of class Doubly_Circular_Liner_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertFirst
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Doubly Circular Linked List.
//
//	Returns:
//		Integer
//		If the function succeeds, the return value .
//	
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertLast
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Doubly Circular Linked List.
//
//	Returns:
//		void
//		The input given by the user is added at the end using InsertLast."
//	
//
/////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function displays Doubly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}


//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Count
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Doubly Circular Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes first node from Dobly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes LAst node from Doubly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil  Gambhir
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Doubly Circular Linked List.
//
//	Returns:
//	     void
//		    "Insert the data at the given position."
//           
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//					NONE
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Doubly Circular Linked List.
//
//	Returns:
//		void
//		
//
/////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLL
//  Description :   Generic implementation of singly linear Linked List
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template <class T>
 struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template <class T>
class SinglyLL
{
    private:
        struct SinglyLLnode<T> * first;
        int iCount;

    public:
        SinglyLL();
        ~SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Singly_linkedList
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is constructor of class Singly_Liner_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor of SinglyLL\n";

    this->first = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Singly_linkedList
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is destructor of class Singly_Liner_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>::~SinglyLL()
{
    while (first != NULL)
    {
        DeleteFirst();
    }

}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertFirst
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Singly Linear Linked List.
//
//	Returns:
//		Integer
//		If the function succeeds, the return value .
//	
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void  SinglyLL<T>:: InsertFirst( T no)
{
   SinglyLLnode<T> * newn = new SinglyLLnode<T>;

    newn->data = no;
    newn->next = first;
    first = newn;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertLast
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Singly Linear Linked List.
//
//	Returns:
//		void
//		The input given by the user is added at the end using InsertLast."
//	
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T no)
{ 
    SinglyLLnode<T> * newn = new SinglyLLnode<T>;
    SinglyLLnode<T>* temp = NULL;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function displays Singly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    SinglyLLnode<T>* temp = first;  
    while(temp != NULL)
    {
        cout<<"|"<<" |"<<temp ->data <<" | ->";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Count
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Singly Linear Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: Count()
{
    SinglyLLnode<T>* temp = first;

    int iCount = 0;

    while(temp != NULL)
    {
        iCount++;
        temp = temp -> next;
    }

    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes first node from Singly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    SinglyLLnode <T>* temp = NULL;

    if(first == NULL)                  // Empty LL
    {
        return;
    }
    else if((first) -> next == NULL)    // Single node
    {
        delete first;
        first = NULL;
    }
    else                                // More than 1 node
    {
        temp = first;
        
        first = first -> next;

        delete  temp;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes LAst node from Singly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteLast()
{
     SinglyLLnode<T> *temp = NULL;
    
    if(first == NULL)                  // Empty LL
    {
        return;
    }
    else if(first -> next == NULL)    // Single node
    {
       delete first;
        first = NULL;
    }
    else                                // More than 1 node
    {
        temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

       delete temp -> next;
        temp->next = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Singly Linear Linked List.
//
//	Returns:
//		Integer
//		    "Insert the data at the given position."
//           
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int pos)
{
    T iCount = 0, i = 0;
    SinglyLLnode <T>* temp = NULL;
    SinglyLLnode <T>* newn = new SinglyLLnode<T>;
    
    iCount = Count();

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;

        for(i = 1; i<= pos-2; i++)
        {
            temp = temp -> next;
        }

        newn->data = no;
        newn->next = NULL;

        newn->next = temp -> next;
        temp -> next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//					NONE
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Singly Linear Linked List.
//
//	Returns:
//		void
//		
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    T iCount = 0, i = 0;
    SinglyLLnode<T> * temp = NULL;
    SinglyLLnode<T> * target = NULL;
    
    iCount = Count();

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i<= pos-2; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;  // temp->next = temp->next->next;
       delete target;
    }
}




///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLL
//  Description :   Generic implementation of doubly linear Linked List
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

// Add code
template <class T>
struct DoublyLLnode
{
    T data;
    struct DoublyLLnode<T> *next;
    struct DoublyLLnode<T> *prev;      // $
};


template <class T>
class DoublyLL
{
    private:
        struct DoublyLLnode<T> * first;
        int iCount;

    public:
        DoublyLL();
        ~DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyLL
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is constructor of class Doubly_Liner_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside constructor of DoublyLL\n";

    this->first = NULL;
    this->iCount = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyLL
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is Disstructor of class Doubly_Liner_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLL<T>::~DoublyLL()
{
    while (first != NULL)
    {
        DeleteFirst();
    }

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function displays Doubly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display()
{
    DoublyLLnode<T>* temp = first;  
   cout << "NULL <=> ";

    while(temp != NULL)
    {
        printf("| %d | <=> ",temp->data);
        temp = temp -> next;
    }
    
    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Count
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Doubly Linear Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////


template <class T>
int DoublyLL<T>:: Count()
{
    int iCount = 0;

    DoublyLLnode<T>* temp = first;

    while(temp != NULL)
    {
        iCount++;
        temp = temp -> next;
    }

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertFirst
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Doubly Linear Linked List.
//
//	Returns:
//		void
//		If the function succeeds, the return value .
//	
//
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    DoublyLLnode<T>* newn = new DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;          // $

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;    // $
        first = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: InsertLast
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Doubly Linear Linked List.
//
//	Returns:
//		void
//		The input given by the user is added at the end using InsertLast."
//	
//
/////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    
    DoublyLLnode<T>* temp = NULL;

    DoublyLLnode<T>* newn = new DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;          // $

    if(first == NULL)
    {//210,200,267,,257,253,243 error ahe
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }

        newn->prev = temp;      // $
        temp->next = newn;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes first node from Doubly Linear Linked List.
//
//	Returns:
//		void
//
////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if((first) -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first -> next;
       delete first -> prev;         // $
        first -> prev = NULL;        // $
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//
//	Parameters:
//					NONE
//	Description:
//		This function removes LAst node from Doubly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    DoublyLLnode<T>* temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != NULL) // CHANGE ZALA AHE TU NIWANT GHE
        {   
            temp = temp -> next;
        }

        temp->prev->next = NULL;        // $
       delete temp;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//					NONE
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Doubly Linear Linked List.
//
//	Returns:
//		void
//		
//
///////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    int iCount = Count();
    T iCnt = 0;




    if((pos < 1) || (pos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
       DoublyLLnode<T>* temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

       DoublyLLnode<T>* target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;      // $

        delete target;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPost
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Doubly Linear Linked List.
//
//	Returns:
//		void
//		    "Insert the data at the given position."
//           
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int pos)
{
    int iCount = Count();
    T iCnt = 0;

    DoublyLLnode<T> * temp = NULL;


    if((pos < 1) || (pos > iCount +1))
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
       DoublyLLnode<T>* newn = new DoublyLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

       temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        newn->next->prev = newn;        // $
        temp->next = newn;
        newn->prev = temp;              // $
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         BST 
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////


template <class T>
struct BSTnode
{
    T data;
    struct BSTnode *lchild;
    struct BSTnode *rchild;
};

template <class T>
class BST
{
    private:
        struct BSTnode<T> * first;
        int iCount;

    public:
        BST();

    void Insert(T no);
    void Inorder(BSTnode<T>* first);
    void Preorder(BSTnode<T>* first);
    void Postorder(BSTnode<T>* first);
    bool Search(BSTnode<T>* first, T no);
    int Count(BSTnode<T>* first);
    int CountLeafNodes(BSTnode<T>* first);
    int CountParentNodes(BSTnode<T>* first ); 
    
    BSTnode<T>* getRoot()
    {
        return first;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BST(Binary Search Tree)
//	Function Date			:	15/09/2025
//	Function Author			:	Nikhil Gambhir
//	Parameters:				: NONE
//	Description:
//		This is constructor of class Binary_Search_Tree..
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
BST<T>::BST()
{
    cout<<"Inside constructor of BST\n";

    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: Insert
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] T no
//		Holds the entry which is to be added.
//
//	Description:
//		Inserts a new node into the Binary Search Tree (BST) while maintaining
//      the BST property. Duplicate values are not inserted.
//
//	Returns:
//		void
//	
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Insert(T no)
{
    BSTnode<T>* newn = new BSTnode<T>;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)  // BST is empty
    {
        first = newn;
    }
    else                // BST contains atleast 1 node
    {
        BSTnode<T>* temp = first;

        while(1)
        {
            if(no == temp->data)
            {
                cout << "Duplicate element : Unable to insert node\n";
                delete newn;
                break;
            }
            else if(no > temp->data)    // rchild
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)    // lchild
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: Inorder
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] BSTnode first
//		Pointer to the root node (or current subtree node) from which
//		inorder traversal will begin.
//
//	Description:
//		 Performs inorder traversal of the Binary Search Tree (BST)
//       and displays node values in sorted (ascending) order.
//
//	Returns:
//		void
//	
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>:: Inorder(BSTnode<T>* first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout << first->data << "\t";
        Inorder(first->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: Perorder
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] BSTnode first
//		Pointer to the root node (or current subtree node) from which
//		inorder traversal will begin.
//
//	Description:
//		  Performs preorder traversal of BST and prints nodes.
//
//	Returns:
//		void
//	
//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>:: Preorder(BSTnode<T>* first)
{
    if(first != NULL)
    {
        cout << first->data << "\t";
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: Postorder
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] BSTnode first
//		Pointer to the root node (or current subtree node) from which
//		inorder traversal will begin.
//
//	Description:
//		  Performs postorder traversal of BST and prints nodes 
//       (left subtree → right subtree → root).
//
//	Returns:
//		void
//	
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void BST<T>:: Postorder(BSTnode<T>* first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout << first->data << "\t";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			: Search
//	Function Date			:	15/09/2025
//	Function Author		:	Nikhil Gambhir
//	Parameters:
//
//		[IN] BSTnode first,T no
//		Pointer to the root node (or current subtree node) from which
//		inorder traversal will begin.Holds the entry which is to be added.
//
//	Description:
//	       Iterative search in BST with time complexity count.	  
//
//	Returns:
//		BOOL
//
//	
//////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    bool  BST<T>:: Search(BSTnode<T>* first,  T no)
    {
        bool bFlag = false;
        T TimeComplexity = 0;

        while(first != NULL)
        {
            if(no == first->data)
            {
                bFlag = true;
                break;
            }
            else if(no > first->data)
            {   
                first = first->rchild;
            }
            else if(no < first->data)
            {
                first = first->lchild;
            }
            TimeComplexity++;
        }

        cout << "Time complexity of search is : " << TimeComplexity << "\n";

        return bFlag;
    }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Count
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Binary Search Tree .
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int BST<T>:: Count (BSTnode<T>* first)
    {
        if(first == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + Count(first->lchild) + Count(first->rchild);
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountLefNodes
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		ounts the number of leaf nodes in the Binary Search Tree (BST).  
//
// Returns:  
//   int → Total leaf node count.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int BST<T>:: CountLeafNodes(BSTnode<T>* first)
{
    if(first == NULL)
    {
        return 0;
    }
    if(first->lchild == NULL && first->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return CountLeafNodes(first->lchild) + CountLeafNodes(first->rchild);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountParentnode
//	Function Date		:	15/09/2025
//	Function Author	:	Nikhil Gambhir
//	Parameters:
//					NONE
//	Description:
//		   Counts the number of parent nodes (nodes having at least one child) in BST.  
//
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int BST<T>:: CountParentNodes(BSTnode<T>* first)
{
    if(first == NULL)
    {
        return 0;
    }
    if(first->lchild != NULL || first->rchild != NULL)
    {
        return 1 + CountParentNodes(first->lchild) + CountParentNodes(first->rchild);
    }
    else
    {
        return 0;
    }
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting  -> generic
//  Description :   Generic implementation of sorting algorithms
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template <class T>
class ArrayXSortX
{
    private:
             T *Arr;
             int iSize;
             bool Sorted;

    public:
       ArrayXSortX (int no);
        ~ArrayXSortX();


             void Accept();
             void Display();
             void BubbleSort();
             void BubbleSortEfficient();
             void SelectionSort();
             void InsertionSort();

        
};

    template<class T>
    ArrayXSortX<T>:: ArrayXSortX(int no)
    {
        iSize = no;
        Arr = new int[iSize];
        Sorted = true;
    }
    template<class T>
    ArrayXSortX<T>::~ArrayXSortX()
    {
        delete []Arr;
    }

    template<class T>
    void ArrayXSortX<T>::Accept()
    {
        cout<<"Enter "<<iSize<<" elements : \n";
        
        T i =0;                   // 11       

        for(i = 0; i < iSize;i++)
        {
            cout<<"Enter the element no : "<<i+1<<"\n";
            cin>>Arr[i];

            if((i > 0) && (Sorted == true))     // IMP
            {
                if(Arr[i] < Arr[i-1])
                {
                    Sorted = false;
                }
            }
        }
    }
    template<class T>
    void ArrayXSortX<T>::Display()
    {
        cout<<"Elements of the array are : \n";
        
        int i = 0;

        for(i = 0; i < iSize; i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
    }

    template<class T>
    void ArrayXSortX<T>::BubbleSort()
    {
        T i = 0, j = 0, temp = 0;

        if(Sorted == true)
        {
            return;
        }
        
        for(i = 0; i < iSize ; i++)         // Outer loop
        {
            for(j = 0; j < iSize - 1; j++)      // Inner loop
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                }
            }

            cout<<"Data after Pass : "<<i+1<<"\n";

            Display();
        }
    }

    template<class T>
   void ArrayXSortX<T>::BubbleSortEfficient()
    {
        T i = 0, j = 0, temp = 0;
        bool bFlag = true;

        if(Sorted == true)
        {
            return;
        }
        
        for(i = 0; (i < iSize && bFlag == true) ; i++)         // Outer loop
        {
            bFlag = false;

            for(j = 0; j < iSize - 1 - i; j++)      // Inner loop
            {
                if(Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }

            cout<<"Data after Pass : "<<i+1<<"\n";

            Display();
        }
    }

    template<class T>
    void ArrayXSortX<T>::SelectionSort()
    {
        T i = 0, j = 0, min_index = 0, temp = 0;

        for(i = 0 ; i < iSize-1; i++)
        {
            min_index = i;

            for(j = i + 1; j < iSize; j++)
            {
                if(Arr[j] < Arr[min_index])
                {
                    min_index = j;
                }
            }

            if(i != min_index)
            {
                temp = Arr[i];
                Arr[i] = Arr[min_index];
                Arr[min_index] = temp;
            }
        }
    }

    template<class T>
    void ArrayXSortX<T>::InsertionSort()
    {
        T i = 0, j = 0, selected = 0;

        for(i = 1; i < iSize; i++)
        {
            for(j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
            {
                Arr[j + 1] = Arr[j];
            }
            Arr[j + 1] = selected;
        }
    }


///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching  
//  Description :   Generic implementation of searching algorithms
//  Author :        Nikhil Kailas Gambhir
//
///////////////////////////////////////////////////////////////////////

template <class T>
class ArraySearchX
{
    private :
        T *Arr;
        int iSize;
        bool Sorted;

        public :
           ArraySearchX(int no);
           ~ArraySearchX();

             
             void Accept();
             void Display();
             bool LinearSearch(T no);
             bool BinarySearchEfficientInc(T no);
};

       template<class T>
       ArraySearchX<T>::ArraySearchX(int no)
        {
            iSize = no;
            Arr = new T[iSize];
            Sorted = true;
        }

        template<class T>
       ArraySearchX<T>::~ArraySearchX()
        {
            delete []Arr;
        }

         template<class T>
       void ArraySearchX<T>::Accept()

        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            for(int i = 0; i < iSize; i++)
            {
                cout<<"Enter element no "<<i+1<<": ";
                cin>>Arr[i];

                if((i > 0) && (Sorted == true))
                {
                    if(Arr[i] < Arr[i-1])
                    {
                        Sorted = false;
                    }
                }
            }
        }

        template<class T>
        void ArraySearchX<T>::Display()
        {
            cout<<"Elements of the array are : \n";
            for(int i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<"\t";
            }
            cout<<"\n";
        }

        template<class T>
        bool ArraySearchX<T>::LinearSearch(T no)
        {
            bool bFlag = false;

            if(Sorted == true)
            {
                cout<<"Data is sorted\n";
                return BinarySearchEfficientInc(no);
            }

            for(int i = 0; i < iSize; i++)
            {
                if(Arr[i] == no)
                {
                    bFlag = true;
                    break;
                }
            }
            return bFlag;
        }

        template<class T>
        bool ArraySearchX<T>::BinarySearchEfficientInc(T no)
        {
            int iStart = 0, iEnd = iSize - 1, iMid = 0;
            bool bFlag = false;

            if(Sorted == false)
            {
                cout<<"Data is not sorted\n";
                return LinearSearch(no);
            }

            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))
                {
                    bFlag = true;
                    break;
                }
                else if(no < Arr[iMid])
                {
                    iEnd = iMid - 1;
                }
                else
                {
                    iStart = iMid + 1;
                }
            }

            return bFlag;
        }



int main()
{
    int choice = 0;

    while (1)
    {
        cout << "\n==========================================\n";
        cout << "   GENERIC DATA STRUCTURE PROJECT MENU   \n";
        cout << "==========================================\n";
        cout << "1. Singly Linear Linked List\n";
        cout << "2. Doubly Linear Linked List\n";
        cout << "3. Singly Circular Linked List\n";
        cout << "4. Doubly Circular Linked List\n";
        cout << "5. Stack\n";
        cout << "6. Queue\n";
        cout << "7. Binary Search Tree (BST)\n";
        cout << "8. Sorting\n";
        cout << "9. Searching\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            SinglyLL<int> obj;
            int ch, val, pos;
            do
            {
                cout << "\n--- Singly Linear Linked List ---\n";
                cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     obj.InsertFirst(val); 
                     break;

                case 2: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     obj.InsertLast(val); 
                     break;

                case 3: 
                     cout << "Enter value & position: "; 
                     cin >> val >> pos; 
                     obj.InsertAtPos(val,pos); 
                     break;

                case 4: 
                     obj.DeleteFirst(); 
                     break;

                case 5: 
                     obj.DeleteLast(); 
                     break;

                case 6: 
                    cout << "Enter position: "; 
                    cin >> pos; 
                    obj.DeleteAtPos(pos); 
                    break;

                case 7: 
                     obj.Display(); 
                     break;

                case 8: 
                     cout << "Count: " << obj.Count() << "\n"; 
                     break;
                }
            } while (ch != 0);
            break;
        }

        case 2:
        {
            DoublyLL<int> obj;
            int ch, val, pos;
            do
            {
                cout << "\n--- Doubly Linear Linked List ---\n";
                cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1: 
                    cout << "Enter value: ";
                    cin >> val;
                    obj.InsertFirst(val); 
                    break;

                case 2: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     obj.InsertLast(val); 
                     break;

                case 3: 
                    cout << "Enter value & position: "; 
                    cin >> val >> pos; 
                    obj.InsertAtPos(val,pos); 
                    break;

                case 4: 
                     obj.DeleteFirst();
                     break;

                case 5: 
                     obj.DeleteLast(); 
                     break;

                case 6: 
                     cout << "Enter position: "; 
                     cin >> pos; 
                     obj.DeleteAtPos(pos); 
                     break;

                case 7: 
                     obj.Display(); 
                     break;

                case 8: 
                     cout << "Count: " << obj.Count() << "\n"; 
                     break;
                }
            } while (ch != 0);
            break;
        }
        case 3:
        {
            SinglyCLL<int> obj;
            int ch , val, pos;
            do
            {
                cout << "\n--- Singly Circular Linear Linked List ---\n";
                cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

            switch (ch)
                {
                case 1: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     obj.InsertFirst(val); 
                     break;

                case 2: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     obj.InsertLast(val); 
                     break;

                case 3: 
                     cout << "Enter value & position: "; 
                     cin >> val >> pos; 
                     obj.InsertAtPos(val,pos); 
                     break;

                case 4: 
                     obj.DeleteFirst(); 
                     break;

                case 5: 
                     obj.DeleteLast(); 
                     break;

                case 6: 
                     cout << "Enter position: "; 
                     cin >> pos; 
                     obj.DeleteAtPos(pos); 
                     break;

                case 7: 
                     obj.Display(); 
                     break;

                case 8: 
                    cout << "Count: " << obj.Count() << "\n"; 
                    break;
                }
            } while (ch != 0);
            break;
        }
         case 4:
        {
            DoublyCLL<int> obj;
            int ch, val, pos;
            do
            {
                cout << "\n--- Doubly Circular Linear Linked List ---\n";
                cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1: 
                    cout << "Enter value: ";
                    cin >> val;
                    obj.InsertFirst(val); 
                    break;

                case 2: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     obj.InsertLast(val); 
                     break;

                case 3: 
                    cout << "Enter value & position: "; 
                    cin >> val >> pos; 
                    obj.InsertAtPos(val,pos); 
                    break;

                case 4: 
                     obj.DeleteFirst();
                     break;

                case 5: 
                     obj.DeleteLast(); 
                     break;

                case 6: 
                     cout << "Enter position: "; 
                     cin >> pos; 
                     obj.DeleteAtPos(pos); 
                     break;

                case 7: 
                     obj.Display(); 
                     break;

                case 8: 
                     cout << "Count: " << obj.Count() << "\n"; 
                     break;
                }
            } while (ch != 0);
            break;
        }

        case 5:
        {
            StackX<int> st;
            int ch, val;
            do
            {
                cout << "\n--- Stack Operations ---\n";
                cout << "1. Push\n2. Pop\n3. Display\n4. Count\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1: 
                     cout << "Enter value: "; 
                     cin >> val; 
                     st.Push(val); 
                     break;

                case 2: 
                     cout << "Popped element: " << st.Pop() << "\n"; 
                     break;

                case 3: 
                     st.Display(); 
                     break;

                case 4: 
                     cout << "Count: " << st.Count() << "\n"; 
                     break;
                }
            } while (ch != 0);
            break;
        }

        case 6:
        {
            QueueX<int> q;
            int ch, val;
            do
            {
                cout << "\n--- Queue Operations ---\n";
                cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1: 
                     cout << "Enter value: "; 
                     cin >> val; q.Enqueue(val); 
                     break;

                case 2: 
                    cout << "Dequeued element: " << q.Dequeue() << "\n"; 
                    break;

                case 3: 
                     q.Display(); 
                     break;

                case 4: 
                     cout << "Count: " << q.Count() << "\n"; 
                     break;
                }
            } while (ch != 0);
            break;
        }

        case 7:
        {
            BST<int> bst;
            int ch, val;
            do
            {
                cout << "\n--- Binary Search Tree ---\n";
                cout << "1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Count Nodes\n6. Count Leaf Nodes\n7. Count Parent Nodes\n8. Search\n0. Back\n";
                cout << "Enter choice: ";
                cin >> ch;

                switch (ch)
                {
                case 1: 
                     cout << "Enter value: "; 
                     cin >> val; bst.Insert(val); 
                     break;

                case 2: 
                     bst.Inorder(bst.getRoot()); 
                     cout << "\n"; 
                     break;

                case 3:  
                      bst.Preorder(bst.getRoot()); 
                      cout << "\n"; 
                      break;

                case 4: 
                     bst.Postorder(bst.getRoot()); 
                     cout << "\n"; 
                     break;

                case 5: 
                    cout << "Total Nodes: " << bst.Count(bst.getRoot()) << "\n"; 
                    break;

                case 6: 
                     cout << "Leaf Nodes: " << bst.CountLeafNodes(bst.getRoot()) << "\n"; 
                     break;

                case 7: 
                     cout << "Parent Nodes: " << bst.CountParentNodes(bst.getRoot()) << "\n"; 
                     break;

                case 8: 
                     cout << "Enter value to search: "; 
                     cin >> val;
                     if (bst.Search(bst.getRoot(), val)) cout << "Found!\n"; 
                     else cout << "Not Found!\n";
                    break;
                }
            } while (ch != 0);
            break;
        }

        case 8:
        {
            int n;
            cout << "Enter size of array: ";
            cin >> n;
            ArrayXSortX<int> sobj(n);
            sobj.Accept();
            sobj.Display();
            cout << "\n1. BubbleSort\n2. BubbleSortEfficient\n3. SelectionSort\n4. InsertionSort\nChoice: ";
            int ch; cin >> ch;
            switch (ch)
            {
                case 1: 
                     sobj.BubbleSort(); 
                     break;

                case 2: 
                     sobj.BubbleSortEfficient(); 
                     break;

                case 3: 
                     sobj.SelectionSort(); 
                     break;

                case 4: 
                     sobj.InsertionSort(); 
                     break;
            }
            sobj.Display();
            break;
        }

        case 9:
        {
            int n, val;
            cout << "Enter size of array: ";
            cin >> n;
            ArraySearchX<int> sobj(n);
            sobj.Accept();
            sobj.Display();
            cout << "Enter value to search: ";
            cin >> val;
            if (sobj.LinearSearch(val))
                cout << "Element found!\n";
            else
                cout << "Element not found!\n";
            break;
        }

        case 0:
            cout<<"==============================================================\n";
            cout<< "Thank you for using the Generic Data Structure Project........!\n";
            cout<<"==============================================================\n";

            return 0;

        default:
            cout<<"===============================\n";
            cout<< "Invalid choice. Try again.....!\n";
            cout<<"===============================\n";

        }
    }
}


