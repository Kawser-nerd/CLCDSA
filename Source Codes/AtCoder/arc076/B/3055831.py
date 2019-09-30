n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
a = sorted(a)
gra = []
for i in range(n):
  a[i].append(i)
for i in range(n-1):
  gra.append([a[i][2],a[i+1][2],a[i+1][0]-a[i][0]])
a = sorted(a,key= lambda x:x[1])
for i in range(n-1):
  gra.append([a[i][2],a[i+1][2],a[i+1][1]-a[i][1]])
union = [0] *  n
uc = 0
ans = 0
gra = sorted(gra, key = lambda x: x[2])
class UnionFind():
    #?????????????
    #???????????
    def __init__(self,size):
        self.table = [-1 for _  in range(size)]

    #?????????
    def find(self,x):
        while self.table[x] >= 0:
            #?????,self.table[??index]???????x = ??index????????
            x = self.table[x]
        return x

    #??
    def union(self,x,y):
        s1 = self.find(x)#??index,table[s1]???????
        s2 = self.find(y)
        if s1 != s2:#???????
            if self.table[s1] != self.table[s2]:#????????????
                if self.table[s1] < self.table[s2]:
                    self.table[s2] = s1
                else:
                    self.table[s1] = s2
            else:
                #???????????,??????????????
                #???,????1???????????
                self.table[s1] += -1
                self.table[s2] = s1
        return
uni = UnionFind(n)
for i in range(len(gra)):
  hen = gra[i]
  if (uni.find(hen[0]) != uni.find(hen[1])):
    ans += hen[2]
    uni.union(hen[0],hen[1])
    uc += 1
  if uc == n-1:
    break
print(ans)