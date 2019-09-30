a = int(input())
br = [[],[],[]]
for i in range(a):
    l = list(map(int,input().split(" ")))
    m = sorted(l)
    br[0].append(m[0])
    br[1].append(m[1])
    br[2].append(m[2])
print(max(br[0]) * max(br[1]) * max(br[2]))