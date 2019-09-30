
import math

class pannukakku:
  radius = 0
  height = 0
  size_h = 0
  size_r = 0
  def size(self, current_r):
    if(self.radius > current_r):
      return self.size_h + self.size_r - math.pi * current_r * current_r;
    return self.size_h;

def poista_isoin(kakut, current_r):
  isoin_index = 0;
  isoin_size = kakut[0].size(current_r);
  for p in range(1, len(kakut)):
    if(kakut[p].size(current_r) > isoin_size):
      isoin_index = p;
      isoin_size = kakut[p].size(current_r);
  return kakut.pop(isoin_index);

t = int(input())
for i in range(1, t + 1):

  pannukakkuja, tilauksen_koko = [int(s) for s in  input().split(" ")];
  #print("gola:{}".format(goal))
  #data containers
  radiuses = [0 for h in range(pannukakkuja)]
  heigths = [0 for h in range(pannukakkuja)]
  sizes = [0 for h in range(pannukakkuja)]
  kakut = [pannukakku() for h in range(pannukakkuja)]
  #read input
  for h in range(0, pannukakkuja):
    r, s = [int(s) for s in input().split(" ")];
    kakut[h].radius = r;
    kakut[h].heigth = s;
    kakut[h].size_h = math.pi * 2 *r * s;
    kakut[h].size_r = math.pi * r * r;

  total = 0;
  current_r = 0;
  for p in range(tilauksen_koko):
    isoin = poista_isoin(kakut, current_r);
    total += isoin.size(current_r);
    current_r = max(current_r, isoin.radius);


  #print("time to goal {}".format(timeToGoal))
  #print(speeds)
  #PRINT RESULT
  #vastausaika = sizes[0]

  print("Case #{0:.0f}: {1:.6f}".format(i, total));









