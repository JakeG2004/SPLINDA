#ifndef HWMGR_H
#define HWMGR_H

class HWManager {
private:
    // The static instance pointer
    static HWManager* instance;

    // Private constructor: Prevents other classes from "newing" this up
    HWManager();
    void InitScreens();

public:
    // Static method to access the instance
    static HWManager* getInstance();
    
    // Optional: Setup method to initialize the singleton
    static void Create();

    static void RenderScreens();
};

#endif