#ifndef BWFILTER_H
#define BWFILTER_H

#include "cbuff.h"

/*
   Ex:
   fc = 10Hz //Cut off frequency
   fs = 1kHz //Arduino sampling frequency
   Difference equation 4:th order HP Butterwothfilter:
   y[n] = 0.9212x[n] - 3.685x[n-1] + 5.527x[n-2] - 3.685x[n-3] + 0.9212x[n-4] + 3.836y[n-1] - 5.521y[n-2] + 3.534y[n-3] - 0.8486y[n-4]
   x is input
   y is output
*/

class BWfilter
{
  private:
    int SIZE = 5;
    Cbuff<float>* x = nullptr;
    Cbuff<float>* y = nullptr;
    float xin = 0;

  public:
    BWfilter();
    ~BWfilter();
    float get(float _xin);
};


#endif
