/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if you can convert a pointer to a reference in this project. Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int val, const char* str): value{val}, name{str} 
    {

    } //1
    int value;
    std::string name;
};

struct CompareDaFunk                             //4
{
    T* compare(T& a, T& b)
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;

        return nullptr;
    }
};

struct U
{
    float oldFunk { 0 }, newFunk { 0 };
    float regularFuncA(const float& updatedFunk )      //12
    {
        std::cout << "U's oldFunk value: " << oldFunk << std::endl;

        oldFunk = updatedFunk;
        std::cout << "U's oldFunk updated value: " << oldFunk << std::endl;
        while( std::abs(newFunk - oldFunk) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            newFunk += 0.01f;
        }
        std::cout << "U's newFunk updated value: " << newFunk << std::endl;
        return newFunk * oldFunk;
    }
};

struct MyUDT2
{
    static float staticFuncA(U& that, const float& updatedFunk )        //10
    {
        std::cout << "U's oldFunk value: " << that.oldFunk << std::endl;

        that.oldFunk = updatedFunk;
        std::cout << "U's oldFunk updated value: " << that.oldFunk << std::endl;
        while( std::abs(that.newFunk - that.oldFunk) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            that.newFunk += 0.01f;
        }
        std::cout << "U's newFunk updated value: " << that.newFunk << std::endl;
        return that.newFunk * that.oldFunk;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T george(1 , "George");                                 //6
    T bootsy(6 , "Bootsy");                                 //6
    
    CompareDaFunk f;                                        //7
    auto* smaller = f.compare(george , bootsy);           //8
    if (smaller != nullptr)
        std::cout << "the smaller one is " << smaller->name << std::endl; //9
    else
        std::cout << "they are the same." << std::endl; //9
    
    U funkBlaster3;
    float updatedValue = 5.f;
    std::cout << "[static func] staticFuncA's multiplied values: " << MyUDT2::staticFuncA(funkBlaster3 , updatedValue) << std::endl;                  //11
    
    U funkBlaster4;
    std::cout << "[member func] regularFuncA's multiplied values: " << funkBlaster4.regularFuncA(updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
