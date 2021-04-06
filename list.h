
//List, an ordered list of objects.
//Iterator, the interface for accessing an aggregate's objects in a sequence.

//ListIteractor, an iterator for traversing a List.
//Point, a two-dimensional point.
//Rect, an axis-aligned rectangle.

//If you compiler doesnt define bool

typedef int bool;
const int true = 1;
const int false = 0;

template < class Item >
class List{
	public:
		List(long size = DEFAULT_LIST_CAPACITY);
		List(List&);
		~List();
		List& operator=(const List&); //overriding the assign operator

		long Count() const;
		Item& Get(long index) const;
		Item& First() const;
		Item& Last() const;
		bool Includes(const Item&) const;

		void Append(const Item&);
		void Prepend(const Item&);

		void Remove(const Item&);
		void RemoveLast();
		void RemoveFirst();
		void RemoveAll();

		Item& Top() const;
		void Push(const Item&);
		Item& Pop();
} //Here is a full definition for the Iterator Pattern


//Construction, Destruction, Initialization, and Assignment
List(long size)

List(List&)

~List)

List& operator=(const List&)

//Accessing
long Count() const

Item& Get(long index) const

Item& First() const

Item& Last() const

//Adding

void Append(const Item&)

void Prepend(const Item&)

//Removing

void Remove(const Item&)

void RemoveFirst()

void RemoveLast()

void RemoveAll()

//Stack Interface
Item& Top() const

void Push(const Item&)

Item& Pop()

/* Iterator */

template <class Item>
class Iterator{
	public:
		virtual void First() = 0;
		virtual void Next() = 0;
		virtual bool IsDone() const = 0;
		virtual Item CurrentItem() const = 0;
	protected:
		Iterator();
}
//Explanation
virtual void First()

virtual void Next()

virtual bool IsDone() const

virtual Item CurrentItem() const

// ListIterator
template <class Item>
class ListIterator : public Iterator<Item> {
	public:
		ListIteractor(const List<Item>* aList);

		virtual void First();
		virtual void Next();
		virtual bool IsDone() const;
		virtual Item CurrentItem() const;

};

//Then, the List and its iterators are over. Next is the Point.

//Point

typedef float Coord;

class Point{
	public:
		static const Point Zero;

		Point(Coord x = 0.0, Coord y = 0.0);

		Coord X() const; void X(Coord x);
		Coord Y() const; void Y(Coord y);

		friend Point operator+(const Point&, const Point&);
		friend Point operator-(const Point&, const Point&);
		friend Point operator*(const Point&, const Point&);
		friend Point operator/(const Point&, const Point&);

		Point& operator+=(const Point&);
		Point& operator-=(const Point&);
		Point& operator*=(const Point&);
		Point& operator/=(const Point&);

		Point operator-();

		friend bool operator==(const Point&, const Point&);
		friend bool operator!=(const Point&, const Point&);

		friend ostream& operator<<(ostream&, const Point&);
		friend istream& operator>>(istream&, Point&);
};

//Rect
class Rect{
	public:
		static const Rect Zero;

		Rect(Coord x, Coord y, Coord w, Coord h);
		Rect(const Point& orign, const Point& extent);

		Coord Width() const; void Width(Coord);
		Coord Height() const; void Height(Coord);
		Coord Left() const; void Left(Coord);
		Coord Bottom() const; void Bottom(Coord);

		Point& Origin() const; void Origin(const Point&);
		Point& Extent() const; void Extent(const Point&);

		void MoveTo(const Point&);
		void MoveBy(const Point&);

		bool IsEmpty() const;
		bool Contains(const Point&) const;

}

Rect(Point(0, 0), Point(0, 0))


=======================================Abstract Factory=======================================




/// Creational Patterns
//Abstract Factory

#include <iostream>

class ProductA{
	public:
		virtual std::string getName() = 0;
//...
};

class ConcreteProductAX : public ProductA{
	public:
		std::string getName(){
			return "A-X";
		}
		//...
};

class ConcreteProductAY : public ProductA{
	public:
		std::string getName(){
			return "A-Y";
		}
		//...
};

class ProductB{
	public:
		virtual std::string getName() = 0;
};

class ConcreteProductBX : public ProductB{
	public:
		std::string getName(){
			return "B-X";
		}
};

class ConcreteProductBY : public ProductB{
	public:
		std::string getName(){
			return "B-Y";
		}

};

class AbstractFactory{
	public:
		virtual ProductA* createProductA() = 0;
		virtual ProductB* createProductB() = 0;
};


class ConcreteFactoryX : public AbstractFactroy{
	public:
		ProductA* createProductA(){
			return new ConcreteProductAX();
		}
		ProductB* createProductB(){
			return new ConcreteProductBX();
		}
};

class ConcreteFactoryY : public AbstractFactory{
	public:
		ProductA* createProductA(){
			return new ConcreteProductAY();
		}
		ProductB* createProductB(){
			return new ConcreteProductBY();
		}
};

int main()
{
	ConcreteFactoryX* factoryX = new ConcreteFactoryX();
	ConcreteFactoryY* factoryY = new ConcreteFactoryY();

	ProductA* p1 = factoryX->createProductA();
	std::cout << "Product: " << p1->getName() << std::endl;

	ProductA* p2 = factoryY->createProductB();
	std::cout << "Product: " << p2->getName() << std::endl;

	return 0;
}


================================================================

///Builder

#include <iostream>

class Product{
	public:
		void makeA(const std::string& part){
			partA = part;
		}
		void makeB(const std::string& part){
			partB = part;
		}
		void makeC(const std::string& part){
			partC = part;
		}
		std::string get(){
			return (partA + " " + partB + " " +partC);
		}
		//...
	private:
		std::string partA;
		std::string partB;
		std::string partC;

};

class Builder{ //The final composite index
	public:
		virtual ~Builder(){
			//...
		}
		Product get(){
			return product;
		}

		virtual void buildPartA() = 0;
		virtual void buildPartB() = 0;
		virtual void buildPartC() = 0;
		//..

	protected:
		Product product;
};

class ConcreteBuilderX : public Builder{
	public:
		void buildPartA(){
			product.makeA("A-X");
		}
		void buildPartB(){
			product.makeB("B-X");
		}
		void buildPartC(){
			product.makeC("C-X");
		}
};

class ConcreteBuilderY : public Builder{
	public:
		void buildPartA(){
			product.makeA("A-Y");
		}
		void buildPartB(){
			product.makeB("B-Y");
		}
		void buildPartC(){
			product.makeC("C-Y");
		}
};

//correct sequence of object creation

class Director{
	public:
		Director() : builder(nullptr) {}

		~Director() {
			if(builder){
				delete builder;
			}
		}

		void set(Builder* b){
			if(builder){
				delete builder;
			}
			builder = b;
		}

		Product get(){
			return builder->get();
		}

		void construct(){
			builder->buildPartA();
			builder->buildPartB();
			builder->buildPartC();
			//...
		}

	private:
		Builder* builder;

};

int main()
{
	Director director;
	director.set(new ConcreteBuilderX);
	director.construct();

	Product product1 = director.get();
	std::cout << "1st product parts: " << product1.get() << std::endl;

	director.set(new ConcreteBuilderY);
	director.construct();

	Product product2 = director.get();
	std::cout << "2nd product parts: " << product2.get() << std::end;

	return 0;
}

=============================Factory Method===================================


#include <iostream>

class Product{
	public:
		virtual std::string getName() = 0;
		//..
};

class ConcreteProductA : public Product{
	public:
		std::string getName(){
			return "type A";
		}
		//..
};

class ConcreteProductB : public Product{
	public:
		std::string getName(){
			return "type B";
		}
};

class Creator{
	public:
		virtual Product* createProductA() = 0;
		virtual Product* createProductB() = 0;
};

class ConcreteCreator : public Creator{
	public:
		Product* createProductA(){
			return new ConcreteProductA();
		}
		Product* createProductB(){
			return new ConcreteProductB();
		}
}

int main()
{
	Creator* creator = new ConcreteCreator();

	Product* p1 = creator->createProductA();
	std::cout << "Product: " << p1->getName() << std::endl;

	Product* p2 = creator->createProductB();
	std::cout << "Product: " << p2->getName() << std::endl;

	return 0;

}


===============================Prototype======================================-

#include <iostream>

class Prototype{
	public:
		virtual Prototype* clone() = 0; //pure function only used in the a base class
		virtual std::string type() = 0;
		//..
};


class ConcretePrototypeA : public Prototype{
	public:
		Prototype* clone(){
			return new ConcretePrototypeA;
		}
		std::string type(){
			return "type A";
		}

};

class ConcretePrototypeB: public Prototype{
	public:
		Prototype* clone(){
			return new ConcretePrototypeB;
		}
		std::string type(){
			return "type B";
		}

};

class Client{
	public:
		static Prototype* make(int index){
			return type[index]->clone();
		}

	private:
		static Prototype* types[2];
};

Prototype* Client::types[] =  //array init
{
	new ConcretePrototypeA,
	new ConcretePrototypeB
	//...
};

int main()
{
	Prototype* prototype;

	prototype = Client::make(0);
	std::cout << "Prototype: " << prototype->type() << std::endl;

	prototype = Client::make(1);
	std::cout << "Prototype: " << prototype->type() << std::endl;

	return 0;
}

==========================Singleton==============================================



#include <iostream>

class Singleton{
	public:
		static Singleton* get(){
			if(instance == NULL){
				instance = new Singleton();
			}
			return instance;

		}
		void tell(){
			std::cout << "This is Singleton." << std::endl;
			//..
		}
		//..
	private:
		Singleton() {}
		static Singleton* instance;
}
Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton::get()->tell();
	return 0;
}



============================Here is a duplicate=============================================
============================Iterator==========================================
//Just find that, we can use c-feature writing when need efficiency, and use std writings when need readibility.
#include <iostream>
#include <stdexcept>
#include <vector>

class Iterator:
class ConcreteAggregate;

class Aggregate{
	public:
		virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate{
	public:
		ConcreteAggregate(const unsigned int size){
			list = new int[size]();
			count = size;
		}

		Iterator* createIterator();

		~ConcreteAggregate(){
			delete[] list;
		}

		unsigned int size() const{
			return count;
		}

		int at(unsigned int index){
			return list[index];
		}
		//...
	private:
		int* list;
		unsigned int count;
};

class Iterator{
	public:
		virtual ~Iterator(){/* ... */}

		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool isDone() const = 0;
		virtual int currentItem() const = 0;
};


class ConcreteIterator : public Iterator{
	public:
		ConcreteIterator(ConcreteAggregate* l) : list(l), index(0){}

		void first(){
			index = 0;
		}

		void next(){
			index++;
		}

		bool isDone() const {
			return (index >= list->size());
		}

		int currentItem() const {
			if(isDone()){
				return -1;
			}
			return list->at(index);
		}
		//...
	private:
		ConcreteAggregate* list;
		unsigned int index;
};

Iterator* ConcreteAggregate::createIterator(){
	return new ConcreteIterator(this);
}

int main()
{
	unsigned int size = 5;
	ConcreteAggregate list = ConcreteAggregate(size);

	Iterator* it = list.createIterator();
	for( ; !it->isDone(); it-next()){
		std::cout << "Item value: " << it->currentItem() << std::endl;
	}

	delete it;
	return 0;
}

===================================Adapter===============================================

///Structural Patterns

//Adapter--Class Adapter

#include <iostream>

class Target{
	public:
		virtual void request() = 0;
};

class Adaptee{
	public:
		void specificRequest(){
			std::cout<< "specific request" << std::endl;
			//...
		}
		//...
}


class Adapter : public Target, private Adaptee{ //combinly inherige
	public:
		virtual void request(){
			specificRequest();
		}
};

int main()
{
	Target* t = new Adapter();
	t->request();

	return 0;
}

//Adapter--Object Adapter

#include <iostream>

class Target{
	public:
		virtual void request() = 0;
		//...
};

class Adaptee{
	public:
		void specificRequest(){
			std::cout << "specific request" << std::endl;
			//...
		}
		//...
};

class Adapter : public Target{
	public:
		Adapter() : adaptee(){}

		~Adapter(){
			delete adaptee;
		}

		void request()
		{
			adaptee->specificRequest();
		}
		//...
	private:
		Adaptee* adaptee;
};

int main()
{
	Target* t = new Adapter();
	t->request();

	return 0;
}

===========================Bridge===================================

#include <iostream>

class Implementor{
	public:
		virtual void action() = 0;
		//...
};


class ConcreteImplementorA : public Implementor{
	public:
		void action(){
			std::cout << "concrete Implementor A" << std::endl;
		}
		//...
};

class ConcreteImplementorB : public Implementor{
	public:
		void action(){
			std::cout << "Concrete Implementor B" << std::endl;
		}
};

class Abstraction{
	public:
		virtual void operation() = 0;

};

class RefinedAbstraction : public Abstraction{
	public:
		RefinedAbstraction(Implementor* impl) : implementor(impl)
		{

		}

		void operation(){
			implementor->action();
		}
		//...
	private:
		Implementor* implementor;
};


int main()
{
	Implementor* ia = new ConcreteImplementorA;
	Implementor* ib = new ConcreteImplementorB;

	Abstraction* abstract1 = new RefinedAbstraction(ia);
	abstract1->operation();

	Abstraction* abstract2 = new RefinedAbstraction(ib);
	abstract2->operation();

	return 0;
}

============================Composite================================================


#include <iostream>
#include <vector>

class Component{
	public:
		virtual Componet* getChild(int) { return 0; }

		virtual void add(Component*) {/* ... */}
		virtual void remove(int) {/* ... */}

		virtual void operation() = 0;

};

class Composite : public Component{
	public:
		Component* getChild(int index){
			return children.at(index);
		}
		void add(Component* component)
		{
			children.push_back(component);
		}

		void remove(int index)
		{
			children.erase(children.begin() + index);
		}

		void operation()
		{
			for(unsigned int i=0; i<children.size(); ++i)
			{
				children.at(i)->operation();
			}
		}

		private:
		std::vector<Component*> children;


};



class Leaf: public Componet{
	public:
	Leaf(int i) : od(i){}

	void operation(){
		std::cout << "Leaf" <<id <<"operation" <<std::endl;

	}
	private:
	int id;
};

int main()
{
	Composite composite;

	for(unsigned int i= 0; i< 10; ++i)
	{
		composite.add(new Leaf(i));
	}

	composite.operation();

	return 0;

}

==========================Decorator============================


#incldue <iostream>

class Component{
	public:
		virtual void operation() =0;
		//...
};

class ConcreteComponent : public Component{
	public:
	void operation(){
		std::cout << "Concrete Component operation" <<std::endl;
	}
};

class Decorator : public Component{
	public:
		Decorator(Component* c): component(c){}

		virtual void operation(){
			component->operation();
		}
		//...
	private:
		Component* component;
};

class ConcreteDecoratorA : public Decorator {
	public:
		ConcreteDecoratorA(Component* c): Decorator(c){}

		void operation(){
			Decorator::operation();
			std::cout << "Decorator A" <<std::endl;
		}
		//...
};

class ConcreteDecoratorB : public Decorator{
	public:
		ConcreteDecoratorB(Component* c):Decorator(c) {}

		void operation(){
			Decorator::operation();
			std::cout << "Decorator B" << std::endl;
		}
};

int main()
{
	Component* component = new ConcretDecoratorA(
				new ConcreteDecoratorB(new ConcreteComponent)
	);

	component->operation();
	return 0;
}


==============================Facade===============================

#include <iostream>

class SubsystemA {
	public:
	void suboperation(){
		std:: cout<< "Subsystem A method" << std::endl;
		// ...
	}
	// ...
};

class SubsystemB {
	public:
	void  suboperation(){
		std::cout << "Subsystem B method" << std::endl;
		// ...
	}
	// ...
};

class SubsystemC {
	public:
	void suboperation() {
		std::cout << "Subsystem C method" << std::endl;
		// ...
	}
	// ...
};

/* Facade
	delegates client requests to appropriate subsytem object
	and unified interface that is easier to use
 */

 class Facade{
	public:
	Facade() : subsystemA(), subsystemB(), subsystemC()
	{}

	void operation1() {
		subsystemA->suboperation();
		subsystemB->suboperation();
		// ...
	}

	void operation2(){
		subsystemC->suboperation();
	}

	private:
	SubsystemA* subsystemA;
	SubsystemB* subsystemB;
	SubsystemC* subsystemC;
 };

 int main()
 {
	 Facade* facade = new Facade();
	 facade->operation1();
	 facade->operation2();

	 return 0;
 }


 ==============================Flyweight========================================

 #include <iostream>
 #include <map>

 /* Flyweight: declare an interface through which flyweights can receive
	and act on extrinsic state
 */

 class Flyweight{
	 public:
	 virtual ~Flyweight() {/* ... */}
	 virtual void operation() = 0;
	 // ...
 };

 /* UnsharedConcreteFlyweight
	not all subclasses need to be shared
 */
 class UnsharedConcreteFlyweight : public Flyweight{
	 public:
	 UnsharedConcreteFlyweight(int intrinsic_state) :
		state(intrinsic_state) {}

	void operation(){
		std::cout << "Unshared Flyweigt with state" << state <<s std::endl;
	}
	// ...
	private:
	int state;
 };

 /*
	ConcreteFlyweight
	Implements the Flyweight interface and adds storage
	for intrinsic state
 */

 class ConcreteFlyweight : public Flyweight{
	 public:
	 ConcreteFlyweight(int all_state) :
	 state(all_state) {}

	 void operation(){
		 std::cout << "Concrete Flyweight with state" << state << std::endl;
	 }
	 // ...

	 private:
	 int state;

 };


 /*
  Flyweight Factory
  creates and manages flyweights objects and ensures
  that flyweights are shared property
 */


 class FlyweightFactory{
	 public:
	 virtual ~FlyweightFactory(){
		 for(auto it = flies.begin(); it != flies.end() ; it++)
		 {
			 delete it->second;
		 }
		 flies.clear();
	 }

	 Flyweight* getFlyweight(int key){
		 if(flies.find(key) != flies.end()){
			 return flies[key];
		 }
		 Flyweight* fly = new ConcreteFlyweight(key);
		 flies.insert(std::pair<int, Flyweight *>(key, fly));
		 return fly;
	 }
	 // ...
	 private:
	 std::map<int, Flyweight *> flies;
	 // ...
 };

 int main()
 {
	 FlyweightFactory* factory = new FlyweightFactory;
	 factory->getFlyweight(1)->operation();
	 factory->getFlyweight(2)->operation();

	 return 0;
 }

 ==============================Proxy Pattern======================================

 #include <iostream>

 /* Subject
	defines the common interface for RealSubject and Proxy
	so that a Proxy can be used anywhere a RealSubject is expected
 */

 class Subject{
	 public:
	 virtual ~Subject(){ /* .... */}

	 virtual void request() = 0;
	 //...
 };


/*
	Real Subject
	defines the real object that the proxy represents
*/

class RealSubject : public Subject{
	public:
	void request(){
		std::cout << "Real Subject request" << std::endl;
	}
	// ...
};

/*
	Proxy
	maintains a reference that lets the proxy access the real subject
*/

class Proxy : public Subject{
	public:
	Proxy(){
		subject = new RealSubject();
	}

	~Proxy(){
		delete subject;
	}

	void request(){
		subject->request();
	}
	// ...

	private:
	RealSubject* subject;
};

int main()
{
	Proxy* proxy = new Proxy;
	proxy->request();

	return 0;
}

============================Behavioral Patterns================================
====================Chain of Responsibility===================================

#include <iostream>

/*
	Handler
	defines an interface for handling request and
	optionally implements the successor link
*/


class Handler{
	public:
	virtual void setHandler(Handler* s){
		sucessor = s;
	}

	virtual void handleRequest(){
		if(successor != 0){
			successor->handleRequest();
		}
	}
	// ...
	private:
	Handler* successor;
};

/*
	Concrete Handlers
	handle requests they are responsible for
*/
class ConcreteHandler1 : public Handler{
	public:
	bool canHandle(){
		// ...
		return false;
	}

	virtual void handleRequest(){
		if(canHandle()){
			std::cout << "Handled by Concrete Handler 1" <<std::endl;
		}else{
			std::cout << "Cannot be handled by Handler 1" <<std::endl;
			Handler::handleRequest();
		}
		//...
	}
	//...
};

class ConcreteHandler2 : public Handler{
	public:
	bool canHandle(){
		// .. .
		return true;
	}

	virtual void handleRequest(){
		if(canHandle()){
			std::cout << "Handled by Handler 2" << std::endl;
		}else{
			std::cout << "Cannot be handled by Handler 2" << std::endl;
			Handler::handleRequest();
		}
		//...
	}
	//...
};

int main()
{
	ConcreteHandler1 handler1;
	ConcreteHandler2 handler2;

	handler1.setHandler(&handler2);
	handler1.handleRequest();

	return 0;
}

=========================Command Pattern=================================

#include <iostream>

/*
	Receiver
	knows how to perform the operation associated
	with carrying out a request
*/

class Receiver{
	public:
	void action(){
		std::cout << "Receiver: execute action" << std::endl;
	}
	//...
};

/*
	Command
	declares an interface for all commands
*/
class Command {
	public:
	virtual ~Command() {}
	virtual void execute() = 0;
	//...

	protected:
	Command() {}
};

/*
	Concrete Command
	implements execute by invoking the corresponding
	operation(s) on Receiver
*/
class ConcreteCommand : public Command(){
	public:
	ConcreteCommand(Receiver* r) : receiver(r)
	{}
	~ConcreteCommand(){
		if(receiver){
			delete receiver;
		}
	}

	void execute(){
		receiver->action();
	}
	//...
	private:
	Receiver* receiver;
	//...
};

/*
	Invoker
	asks the command to carry out the request
*/
class Invoker{
	public:
	void set(Command* c){
		command = c;
	}

	void confirm(){
		if(command){
			command->execute();
		}
	}
	//...
	private:
	Command* command;
};

int main()
{
	Receiver receiver = Receiver();
	ConcreteCommand command = ConcreteCommand(&receiver);

	Invoker invoker = Invoker();
	invoker.set(&command);
	invoker.confirm();

	return 0;
}

=========================Interpreter Pattern==============================

#include <iostream>
#include <map>

/*
	Context
	contains information that's global to the interpreter
*/

class Context{
	public:
	void set(std::string var, bool value){
		vars.insert(std::pair<std::string, bool>(var, value));
	}

	bool get(std::string exp){
		return vars[exp];
	}

	//...
	private:
	std::map<std::string, bool> vars;
};
/*
	Abstract Expression
	declares an abstract Interpret operation that is common to all nodes
	in the abstract syntax tree
*/

class AbstractExpression{
	public:
	virtual ~AbstractExpression(){}
	virtual bool interpret(Context* ){
		return false;
	}
	//...
};

/*
	Terminal Expression
	implements an Interpret operation associated with terminal symbols
	in the grammar (an instance is required for every terminal symbol in a sentence)
*/
class TerminalExpression : public AbstractExpression{
	public:
	TerminalExpression(std::string val) : value(val){}

	~TerminalExpression(){}

	bool interpret(Context* context){
		return context->get(value);
	}
	//...

	private:
	std::string value;
}

/*
	Nonterminal Expression
	implements an Interpret operation for nonterminal symbols
	in the grammar (one such class is required for every rule in the grammar)
*/
class NonterminalExpression : public AbstractExpression{
	public:
	NonterminalExpression(AbstractExpression* left, AbstractExpression* right)
	: lop(left), rop(right)
	{}
	~NonterminalExpression(){
		delete lop;
		delete rop;
	}

	bool interpret(Context* context){
		return lop->interpret(context) &&
		rop->interpret(context);
	}
	//...
	private:
	AbstractExpression* lop;
	AbstractExpression* rop;
	//...
};

int main(){
	// An example of very simple expression tree
	// that corresponds to expression (A AND B)
	AbstractExpression* A = new TerminalExpression("A");
	AbstractExpression* B = new TerminalExpression("B");
	AbstractExpression* exp = new TerminalExpression(A, B);

	Context context;
	context.set("A", true);
	context.set("B", false);

	std::cout << context.get("A") << "AND" << context.get("B");
	std::cout << " = " << exp->interpret(&context) << std::endl;

	delete exp;
	return 0;
}


=========================Iterator Pattern ****==============================
#include <iostream>
#include <stdexcept>
#include <vector>

class Iterator;
class ConcreteAggregate;

/*
	Aggregate
	defines an interface for aggregates and it decouples your client
	from the implementation of your collection of objects
*/
class Aggregate{
	public:
	virtual Iterator* createInterator() = 0;
	//...
};

/*
	Concrete Aggregates
	has a collection of objects and implements the method
	that returns an Iterator for its collection
*/
class ConcreteAggregate : public Aggregate{
	public:
	ConcreteAggregate(const unsigned int size)
	{
		list = new int [size]();
		count = size;
	}

	Iterator* createIterator();

	~ConcreteAggregate(){
		delete[] list;
	}

	unsigned int size() const{
		return count;
	}

	int at(unsigned int index){
		return list[index];
	}
	//...
	private:
	int* list;
	unsigned int count;
};

/*
	Iterator
	provides the interface that all iterators must implement and
	a set of methods for traversing over elements
*/
class Iterator{
	public:
	virtual ~Iterator() {/* ... */}

	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual int currentItem() const = 0;
	//...
};

/*
	Concrete Iterator
	implements the interface and is responsible for  managing
	the current position of the iterator
*/
class ConcreteIterator : public Iterator{
	public:
	ConcreteIterator(ConcreteAggregate* l)
	: list (l), index(0) {}

	void first() {
		index = 0;
	}

	void next() {
		index++;
	}

	bool isDone() const {
		return (index > = list->size());
	}

	int currentItem() const {
		if(isDone()){
			return -1;
		}
		return list->at(index);
	}
	//....
	private:
	ConcreteAggregate* list;
	unsigned int index;
	//...
};

Iterator* ConcreteAggregate::createIterator(){
	return new ConcreteAggregate(this);
}

int main()
{
	unsigned int size = 5;
	ConcreteAggregate list = ConcreteAggregate(size);

	Iterator* it = list.createIterator();
	for( ; !it->isDone(); it->next()){
		std::cout << "Item value: " << it->currentItem() << std::endl;
	}

	delete it;
	return 0;
}

==========================Mediator Pattern==================================

#include <iostream>
#include <vector>

class Mediator;

/*
	Colleague classes
	each colleague communicates with its mediator whenever
	it would have otherwise communicated with another colleague
*/

class Colleague{
	public:
	Colleague(Mediator* m, unsigned int i)
	:mediator(m), id(i)
	{}

	virtual ~Colleague(){}

	unsigned int getID(){
		return id;
	}

	virtual void send(std::string) = 0;
	virtual void receive(std::string) = 0;

	protected:
	Mediator* mediator;
	unsigned int id;
};

class ConcreteColleague : public Colleague{
	public:
	ConcreteColleague(Mediator* m, unsigned int i)
	: Colleague(m, i){}

	void send(std::string msg);

	void receive(std::string msg){
		std::cout << "Message '" << msg << "' received by Colleague '" << id << std::endl;
	}
};

/*
	Mediator
	defines an interface for communicating with Colleague objects
*/

class Mediator{
	public:
	virtual ~Mediator(){}

	virtual void add(Colleague* c) = 0;
	virtual void distribute(Colleague* sender, std::string msg) = 0;

	protected:
	Mediator(){}
};

/*
	Concrete Mediator
	implements cooperative behavior by coordinating Colleague objects
	and knows its colleagues
*/

class ConcreteMediator : public Mediator{
	~ConcreteMeidator(){
		for(unsigned int i = 0; i < colleagues.size(); i++){
			delete colleagues[i];
		}
		colleagues.clear();
	}

	void add(Colleague* c)
	{
		colleagues.push_back(c);
	}

	void distribute(Colleague* sender, std::string msg){
		for(unsigned int i = 0; i < colleagues.size(); i++){
			if(colleagues.at(i)->getID() != sender->getID()){
				colleagues.at(i)->receive(msg);
			}
		}
	}

	private:
	std::vector<Colleague* > colleagues;
};


void ConcreteColleague::send(std::string msg){
	std::cout << "Message '" << msg << "' sent by Colleague '" << id << std::endl;
	mediator->distribute(this, msg);
}

int main()
{
	Mediator* mediator = new ConcreteMediator;

	Colleague* c1 = new ConcreteColleague(mediator, 1);
	Colleague* c2 = new ConcreteColleague(mediator, 2);
	Colleague* c3 = new ConcreteColleague(mediator, 3);

	mediator->add(c1);
	mediator->add(c2);
	mediator->add(c3);

	c1->send("Hi!");
	c3->send("Hello!");

	delete mediator;
	return 0;
}


==============================Memento=================================

#include <iostream>
#incldue <vector>

/*
* Memonto
	stores internal state of the Originator object and protects
	against access by objects other than originator
*
*/
class Memento{
	private:
	//accessible only to Originator
	friend class Originator:
	Memento(int s):
		state(s) {}

	void setState(int s){
		state = s;
	}

	int getState(){
		return state;
	}
	//...

	private:
	int state;
	//...
};


/*
	Originator
	creates a memento containing a snmapshot of its current internaal
	state and uses the memento to restore its internal state

*/
class Originator{
	public:
	//implemented only for printijng purpose
	void setState(int s){
		std::cout << "Set state to " << s << "." << std::endl;
		state = s;
	}

	//implemented only for printing purpose
	int getState()
	{
		return state;
	}

	void setMemento(Memento* m)
	{
		state = m->getState();
	}

	Memento* createMemento() {
		return new Memento(state);
	}

	private:
	int state;
	//...
};

/*
	CareTaker
	is responsible for the memento's safe keeping
*/
class CareTaker{
	public:
	CareTaker(Originator* o)
	: originator(o) {}

	~CareTaker()
	{
		for(unsigned int i=0; i < history.size(); ++i)
		{
			delete  history.at(i);
		}
		history.clear();
	}

	void save(){
		std::cout << "Save state." << std::endl;
		history.push_back(originator->createMemento());
	}

	void undo(){
		std::cout << "Undo state." << std::endl;
		originator->setMemento(history.back());
		history.pop_back();
	}
	//...
	private:
	Originator* originator;
	std::vector<Memento*> history;
};

int main()
{
	Originator* originator = new Originator;
	CareTaker* caretaker = new CareTaker(originator);

	originator->setState(1);
	caretaker->save();

	originator->setState(2);
	caretaker->save();

	originator->setState(3);
	caretaker->undo();

	std::cout << "Actual state is " << originator->getState() << "." << std::endl;

	delete originator;
	delete caretaker;

	return 0;
}


-------------------------------Observer------------------------------------

#include <iostream>
#include <vector>

class Subject;

/*
	Observer
	defines an updating interface for objects that should be notified
	of changes in a subject
*/
class Observer{
	public:
	virtual int getState() = 0;
	virtual void update(Subject* subject) = 0;
	//...
};

/*
	Concrete Observer
	stores state of intererst to ConcreteObserver objects and
	sends a notification to its observers when its state changes
*/
class ConcreteObserver : public Observer{
	public:
	ConcreteObserver(int state)
	: observer_state(state) {}

	int getState(){
		return observer_state;
	}

	void update(Subject* subject);
	//...

	private:
	int observer_state;
	//...
};

/*
	Subject
	knows its observer and provides an interface for attaching
	and detaching observers
*/
class Subject{
	public:
	void attach(Observer* observer){
		observers.push_back(observer);
	}

	void detach(int index){
		observers.erase(observers.begin() + index);
	}

	void notify(){
		for(unsigned int i=0; i < observers.size(); ++i)
		{
			observers.at(i)->update(this);
		}
	}

	virtual int getState() = 0;
	virtual void setState(int s) = 0;

	//...
	private:
	std::vector<Observer*> observers;
};
/*
	Concrete Subject
	stores state that should stay consistent with the subject's
*/
class ConcreteSubject : public Subject{
	public:
	int getState(){
		return subject_state;
	}

	void setState(int s) {
		subject_state = s;
	}
	//...

	private:
	int subject_state;
};

void ConcreteObserver::update(Subject* subject){
	observer_state = subject-getState();
	std::cout << "Observer state updated." << std::endl;
}

int main()
{
	ConcreteObserver observer(1);
	ConcreteObserver observer(2);

	std::cout << "Observer 1 state: " << observer1.getState() << std::endl;
	std::cout << "Observer 2 state: " << observer2.getState() << std::endl;

	Subject* subject = new ConcreteSubject;
	subject->attach(&observer1);
	subject->attach(&observer2);

	subject->setState(10);
	subject->notify();

	std::cout << "Observer 1 state: " << observer1.getState() << std::endl;
	std::cout << "Observer 2 state: " << observer2.getState() << std::endl;

	return 0;
}

----------------------------State------------------------------------

#include <iostream>

/*
	State
	defines an interface for encapsulating the behavior associated
	with a particular state of the Context
*/
class State{
	public:
	virtual ~State() {/* ... */}
	virtual void handle() = 0;
	//...
};

/*
	Concrete States
	each subclass implements a behavior associated with a state
	of the Context
*/
class ConcreteStateA : public State{
	public:
	~ConcreteStateA(){/* ... */}

	void handle(){
		std::cout << "State A handled." << std::endl;
	}
	//...
};

class ConcreteStateB : public State{
	public:
	~ConcreteStateB() { /* ... */}

	void handle(){
		std::cout << "State B handled." << std::endl;
	}
	//...
};

/*
	Context
	defines the interface of interest to clients
*/
class Context{
	public:
	Context() : state(){/* ... */}

	~Context() {
		delete state;
	}

	void setState(State* s){
		if(state){
			delete state;
		}
		state = s;
	}

	void request(){
		state->handle();
	}
	//...
};

int main()
{
	State* stateA = new ConcreteStateA;
	State* stateB = new ConcreteStateB;

	Context* context = new Context;

	context->setState(stateA);
	context->request();

	context->setState(stateB);
	context->request();

	delete context;
	return 0;
}

===========================Strategy============================

#include <iostream>

/*
	Strategy
	declares an interface common to all supported algorithms
*/
class Strategy{
	public:
	virtual ~Strategy() {/* ... */}
	virtual void algorithmInterface() = 0;
	//...
};

/*
	Concrete Strategies
	implement the algorithm using the Strategy interface
*/
class ConcreteStrategyA: public Strategy{
	public:
	~ConcreteStragyA() {
		/*... */
	}
	void algorithmInterface()
	{
		std::cout << "Concrete Strategy A" << std::endl;
	}
	//...
};

class ConcreteStrategyB : public Strategy{
	public:
	~ConcreteStrategyB() {/* ... */}

	void algorithmInterface(){
		std::cout << "Concrete Strategy B" << std::endl;
	}
	//...
}

class ConcreteStrategyC : public Strategy{
	public:
	~ConcreteStrategyC(){/* ... */}

	void algorithmInterface() {
		std::cout << "Concrete Strategy C" << std::endl;
	}
	//...

};

/*
	Context
	maintains a reference to a Strategy object
*/

class Context{
	public:
	Context(Strategy* s) : strategy(s) {}

	~Context(){
		delete strategy;
	}

	void contextInterface(){
		strategy->algorithmInterface();
	}
	//...
	private:
	Strategy* strategy;
};

int main()
{
	ConcreteStrategyA strategy;
	ConcreteStrategyB strategy;
	ConcreteStrategyC strategy;

	Context context(&strategy);
	context.contextInterface();

	return 0;
}


=============================Template Method=======================================
#include <iostream>

/*
	AbstractClass
	implement a template method defining the skeleton of an algorithm
*/
class AbstractClass{
	public:
	void templateMethod(){
		//...
		primitiveOperation1();
		//...
		primitiveOperation2();
		//...
	}

	virtual void primitiveOperation1() = 0;
	virtual void primitiveOperation2() = 0;
	//...
};

/*
	Concrete Class
	implements the primitive operations to carry out specific steps
	of the algorithm, there may be many Concrete classes, each implementing
	the full set of the required operation
*/
class ConcreteClass : public AbstractClass{
	public:
	void primitiveOperation1(){
		std::cout << "Primitive operation 1" << std::endl;
		// ...
	}

	void primitiveOperation2(){
		std::cout << "Primitive operation 2" << std::endl;
		//...
	}
	//...
};

int main()
{
	AbstractClass* tm = new ConcreteClass;
	tm->templateMethod();
	return 0;
}

======================================Visitor=====================================

#include <iostream>

class Element;
class ConcreteElementA;
class ConcreteElementB;

/*
	Visitor
	declares a Visit operation for each class of ConcreteElement
	in the object structure
*/
class Visitor{
	public:
	virtual void visitElementA(ConcreteElementA* element) = 0;
	virtual void visitElementB(ConcreteElementB* element) = 0;
	//...
};

/*
	Concrete Visitors
	implement each operation declared by Visitor, which implement
	a fragment of the algorithm defined for the corresponding class
	of object in the structure.
*/
class ConcreteVisitor1 : public Visitor{
	public:
	void visitElementA(ConcreteElementA*){
		std::cout << "Concrete Visitor 1: Element A visited." << std::endl;
	}

	void visitElementB(ConcreteElementB*){
		std::cout << "Concrete Visitor 2: Element B visited." << std::endl;
	}
	//...
};

/*
	Element
	defines an accepet operation that takes a visitor as an argument
*/
class Element{
	public:
	virtual void accept(Visitor& visitor) = 0;
}
/*
	Concrete Elements
	implement an accepet operation that takes a visitor as an argument
*/
class ConcreteElementA : public Element{
	public:
	void accept(Visitor& visitor){
		visitor.visitElementA(this);
	}
	//...
};

class ConcreteElementB : public Element{
	void accpet(Visitor& visitor){
		visitor.visitElementB(this);
	}
	//...
};

int main()
{
	ConcreteElementA elementA;
	ConcreteElementB elementB;

	ConcreteVisitor1 visitor1;
	ConcreteVisitor2 visitor2;

	elementA.accept(visitor1);
	elementA.accpet(visitor2);

	elementB.accept(visitor1);
	elementB.accpet(visitor2);

	return 0;
}












