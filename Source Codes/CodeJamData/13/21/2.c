
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numcases, numcasecount;
  scanf("%d", &numcases);
  for(numcasecount = 0; numcasecount < numcases; numcasecount++)
    {
      int mymote;
      scanf("%d", &mymote);
      int nummotes, numeaten;
      int numops = 0;
      scanf("%d", &nummotes);
      int i, j;
      int* amotes = (int*)malloc(nummotes*sizeof(int));
      int* ayummy = (int*)malloc(nummotes*sizeof(int));
      int* anumops = (int*)malloc(nummotes*sizeof(int));
      for(i = 0; i <nummotes; i++)
	{
	  scanf("%d", amotes + i);
	  ayummy[i] = 0;
	  anumops[i] = 0;
	}
      for(numeaten = 1; numeaten <= nummotes; numeaten++)
	{
	  /* Find min of remaining */
	  int min = 10000000, minindex = 0;
	  for(i = 0; i < nummotes; i++)
	    {
	      if(min > amotes[i] && ayummy[i] == 0){
		min = amotes[i];
		minindex = i;
	      }
	    }
	  ayummy[minindex] = 1;
	  while(mymote <= min)
	    {
	      numops++;
	      mymote = (2*mymote - 1);
	      if(mymote <= 2){
		numops = nummotes + 15;
		break;
	      }
	    }
	  anumops[numeaten - 1] = numops + (nummotes - numeaten);
	  mymote += min;
	}
      int minops = nummotes;
      for(i = 0; i < nummotes; i++)
	{
	  if(minops > anumops[i]) minops = anumops[i];
	}
      printf("Case #%d: %d\n", numcasecount+1, minops);
    }
  return 0;
}
      
