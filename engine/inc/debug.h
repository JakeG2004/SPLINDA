#ifndef DEBUG_H
#define DEBUG_H

#include <string>

class Debug {
    public:
        // Static method to get the single instance
        static Debug& Get() {
            static Debug instance;
            return instance;
        }

        void Print(std::string str);
        void Clear();

    private:
        Debug() {}
};

#endif