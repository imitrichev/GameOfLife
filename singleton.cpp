#include <iostream>
#include <vector>
using namespace std;
// based on http://www.devartplus.com/3-simple-ways-to-create-singleton-in-c/
// Meyers' singleton with inheritance
template<class T, class U> class Singleton
{
public:
    static T& GetSingletonInstance()
    {
	// protecting from access on creation
        is_singleton_creating = true;
	// the only our object
        static T single;
        is_singleton_creating = false;
        return single;
    }

protected:
    // turn off constructor (ctor), copy ctor, assignment operator (=)
    // by making them protected (not private bacuase we need inherit them) 
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    //flag
    static bool is_singleton_creating;
public:
    virtual U applyRule(const vector<U*> & objects) = 0;
    virtual int countAlive(const vector<U*> & objects) = 0;
};

// Static variable initialization
template<class T, class U> bool Singleton<T,U>::is_singleton_creating = false;

class ChildBoolSingleton : public Singleton<ChildBoolSingleton,bool>
{
public:
    /*ChildBoolSingleton ()
    {
        if (!is_singleton_creating)
            throw "Singleton must not be initialized";
    }*/

    // The rule: two "true" values in objects vector -> applyRule gives "true"
    virtual bool applyRule(const vector<bool*> & objects)
    {
	int alive_count = countAlive(objects);
        if (alive_count == 2)
	    return true;
	return false;
    }
    virtual int countAlive(const vector<bool*> & objects)
    {
	int count=0;
        vector<bool*>::const_iterator it;
        for(it = objects.begin(); it != objects.end(); ++it)
        {
            if (*(*it))
                count++;
        }
	return count;
    }
};


int main()
{
        vector<bool*> vec;
	for (int i=0; i<2; i++)
            vec.push_back(new bool(false));
        for (int i=0; i<2; i++)
            vec.push_back(new bool(true));

        // two "true" values in vec -> applyRule gives "true"
        std::cout<< \
        ChildBoolSingleton::GetSingletonInstance().applyRule(vec)<<"\n";

        vec.push_back(new bool(true));
        // two "true" values in vec -> applyRule gives "false"
        std::cout<< \
        ChildBoolSingleton::GetSingletonInstance().applyRule(vec)<<"\n";

	//delete pointer contents
	for (int i=0; i<vec.size(); i++)
		delete vec[i];
}
