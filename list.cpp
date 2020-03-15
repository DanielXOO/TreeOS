/*
LAST CHANGE: 15.03.2020
NUBER OF CHANGES: 1
TODO: add output, rewrite in tamplates and classes, compile in lib ;)
*/
#define NULL nullptr
struct List
{
	List* NEXT;
	int val;
};

struct addr {
	List* HEAD;                                     //addres of first element
	List* LAST;                                     //BTW addres of last element 
};
void constr_of_create(addr& l) {                    // then use it as constructure in class :)      
	l.HEAD = NULL;                                   // better to use nullptr() but i'm need freestanding lib 
}
bool empty_check(addr l){
	return (l.HEAD == NULL);
}
void add(int v, addr &mover) {
	List* obj = new List();                          // give memory in heap
	obj->val = v;                                    // in stupid language obj.val = v 
	obj->NEXT = NULL;
	if (empty_check(mover)) mover.HEAD = obj;        // if it empty and don't have adress get it from obj
	else
	{
		obj->NEXT = obj;
		mover.LAST = obj;
	}
}
int main()
{
	addr poss;
	constr_of_create(poss);
	add(10, poss);
	return 0;
}