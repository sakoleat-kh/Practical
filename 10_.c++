#include <iostream>
#include <string>

class Resource {
    private:
    static bool isResourceAllocated;

    std::string name;
    bool hasResource;

public:
    Resource(std::string n) : name(n), hasResource(false){}
    static bool isResourceFree() {
        return !isResourceAllocated;
    }

    void requestResource() {
        if (isResourceFree()) {
            isResourceAllocated = true;
            hasResource = true;
            std::cout << name << " successfully acquired the resource." << std::endl;
        } else {
            std::cout << name << " could not acquire the resource. It is cuurently held by another instance." << std::endl;
        }
    }
};
bool Resource::isResourceAllocated = false;

int main() {
    Resource r1("Object_A");
    Resource r2("Object_B");

    std::cout << "Initial stateL Resource is " << (Resource::isResourceFree() ? "Free" : "Busy") << "\n" << std::endl;
    r1.requestResource();
    r2.requestResource();

    std::cout << "\nFinal after A's request: Resource is " << (Resource::isResourceFree() ? "Free" : "Busy") << "\n" << std::endl;

    r1.requestResource();
    r2.requestResource();

    return 0;
}