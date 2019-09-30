
import math

t = int(input())
for i in range(1, t + 1):
  core_amount, K = [int(s) for s in  input().split(" ")];
  #print("gola:{}".format(goal))
  #data containers
  training = float(input())
  cores = [float(s) for s in  input().split(" ")];
  #solve
  cores.sort();
  while(training > 0):
    #print("cores {}".format(cores))
    smallest_amount = 0;
    pienin = cores[0];
    toiseks_pienin = 0;
    for c in range(len(cores)):
      if(cores[c] == cores[0]):
        smallest_amount += 1;
      else:
        toiseks_pienin = cores[c];
        break;

    #print("pienimpiä on {} pienin {} toiseks {}".format(smallest_amount,pienin,toiseks_pienin))
    if smallest_amount == len(cores):
      nousu = training / smallest_amount;
      for c in range(len(cores)):
        cores[c] += nousu;
      training -= nousu * smallest_amount
    else:
      max_nousu = training / smallest_amount;
      nousu = min(max_nousu, toiseks_pienin - pienin)
      for c in range(len(cores)):
        if(cores[c] == pienin):
          cores[c] += nousu;
        else:
          break;
    training -= nousu * smallest_amount

  #print("cores {}".format(cores))
  #laske tulos

  tulos = 1
  #kaikkien pitää toimia:
  for c in range(len (cores)):
    if(cores[c] >= 1):
      continue;
    else:
      tulos *= cores[c]

  print("Case #{0:.0f}: {1:.6f}".format(i, tulos));









