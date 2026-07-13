#pragma once
namespace HTE 
{
	class Application 
	{
		public:
			Application(); 
			virtual ~Application(); 
			void Run(); 

	}; 
	Application* CreateApplication(); 
}
