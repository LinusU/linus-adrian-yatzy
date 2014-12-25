#include <stdlib.h>
#include <stdio.h>

int House_yatze(int array[]) {

  int HoScTh, HoScPa = 0;
  int misstag = 0;

  for (int i=1; i<7; i++) {
    int apa=0;
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        apa++;
        if (apa==3) {
          HoScTh = i*3;
          misstag = i;
        }
      }
    }
  }
  if (HoScTh == 0) {
    return 0;
  }
  for (int k=1; k<7; k++) {
    int apa2=0;
    for (int l=0; l<5; l++) {
      if (array[l]==k) {
        apa2=apa2+1;
        if (apa2==2) {
          if (misstag!=k) {
            HoScPa = 2*k;
          }
        }
      }
    }
  }
  if (HoScPa == 0) {
    return 0;
  }
return (HoScTh + HoScPa);
}
