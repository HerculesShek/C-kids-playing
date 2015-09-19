#include <stdio.h>
void var_int()
{
  int fahr, celsius;
  int lower, upper, step;
  
  lower = 0;
  upper = 300;
  step = 20;
  
  fahr = lower;
  while(fahr <= upper){
    celsius = 5 * (fahr - 32) / 9;
    printf("%3d\t%5d\n", fahr, celsius);
    fahr = fahr + step;
  }
}

void var_float()
{
  float fahr, celsius;
  int lower, upper, step;
  
  lower = 0;
  upper = 300;
  step = 20;

  
  fahr = lower;
  printf("%s %s\n", "fahr", "celsius");
  while(fahr <= upper){
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

main(){
  // var_int();
  var_float();
}




