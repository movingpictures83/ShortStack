#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "ShortStackPlugin.h"

void ShortStackPlugin::input(std::string file) {
   readParameterFile(file);
}

void ShortStackPlugin::run() {}

void ShortStackPlugin::output(std::string file) {
	// ./ShortStack --readfile /biorg/data/RNA/UMiami/FASTA/S12_R1.fasta --genomefile /biorg/data/DB/SILVA/silva.bacteria.fasta --outdir output
       	std::string outputfile = file;
       	std::string myCommand = "ShortStack --readfile "+myParameters["reads"]+" --genomefile "+myParameters["database"]+" --outdir "+outputfile;
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
 myCommand = "cp "+file+"/* "+std::string(PluginManager::prefix());
 system(myCommand.c_str());
}

PluginProxy<ShortStackPlugin> ShortStackPluginProxy = PluginProxy<ShortStackPlugin>("ShortStack", PluginManager::getInstance());
