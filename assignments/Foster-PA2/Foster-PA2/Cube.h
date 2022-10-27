#pragma once
#include "object.h"
class Cube : public Object
{
  public:
	  Cube() : Object() { this->createVertices(); }
	void createVertices() override;
	void Update(long long dt) override;
};

