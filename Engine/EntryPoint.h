#pragma once
#include "Application.h"
extern HTE::Application* HTE::CreateApplication(); 
int main(int argc, char** argv)  
{
	HTE::Application* app = HTE::CreateApplication();
	app->Run();
	delete app;
}
