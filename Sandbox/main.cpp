#include "Logger.h"
#include <Hearth.h>
class Sandbox: public HTE::Application {
	public:
		Sandbox() {

		}

		~Sandbox() {

		}


}; 

HTE::Application* HTE::CreateApplication()
{
	HTE::Logger log;
	log.log(ERROR, "Something Terrible Happend"); 
	log.log(INFO, "Something Terrible Happend"); 
	log.log(DEBUG, "Something Terrible Happend"); 
	log.log(WARN, "Something Terrible Happend"); 
	return new Sandbox(); 
}

