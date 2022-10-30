#pragma once
#include "Base.h"
class ApplicationInterface
{
public:
	virtual void Run()        = 0;
	virtual void Initialize() = 0;
	virtual void Update()     = 0;
};
class Application : private ApplicationInterface
{
public:
	Application() 
	{ 
		if (!s_Instance) s_Instance = this;
		else throw std::exception("App already exists ya noob");
	}
	~Application() 
	{
	}
protected:
	virtual void Run() = 0;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
private:
	static Application* s_Instance;
};

