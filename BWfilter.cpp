#include "BWfilter.h"

BWfilter::BWfilter()
{
  x = new Cbuff<float> (SIZE);
  y = new Cbuff<float> (SIZE);
}

BWfilter::~BWfilter()
{
  delete x;
  delete y;
}

float BWfilter::get(float _xin)
{
  //y[n] = 0.9212x[n] - 3.685x[n-1] + 5.527x[n-2] - 3.685x[n-3] + 0.9212x[n-4] + 3.836y[n-1] - 5.521y[n-2] + 3.534y[n-3] - 0.8486y[n-4]
  x->push(_xin);
  y->push(0.9212*x->get(0) - 3.685*x->get(1) + 5.527*x->get(2) - 3.685*x->get(3) + 0.9212*x->get(4) + 3.836*y->get(1) - 5.521*y->get(2) + 3.534*y->get(3) - 0.8486*y->get(4));
  return y->get(0);
}
