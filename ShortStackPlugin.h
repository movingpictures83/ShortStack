#ifndef ShortStackPLUGIN_H
#define ShortStackPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class ShortStackPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "ShortStack";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
