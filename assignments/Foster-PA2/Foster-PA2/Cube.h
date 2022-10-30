#pragma once
#include "object.h"
class Cube : public Object
{
  public:
	  Cube() : Object() 
	  { 
		  this->createVertices();
		  float tvec1 = glm::linearRand(-5.f, 5.f);
		  float tvec2 = glm::linearRand(-5.f, 5.f);
		  float tvec3 = glm::linearRand(-2.f, 2.f);

		  translation = glm::translate(glm::mat4(1.0f), glm::vec3(tvec1, tvec2, tvec3));
	  }
	void createVertices() override;
	void Update(long long dt) override;
	bool m_Clockwise = true;
};

