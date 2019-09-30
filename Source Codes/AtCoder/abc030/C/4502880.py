N , M = map(int,input().split())
X , Y = map(int,input().split())
L1 = list(map(int,input().split()))
L2 = list(map(int,input().split()))
t = 0
cnt = 0
import bisect
while True:
    try:
       # print(bisect.bisect_left(L1,t))
        t = L1[bisect.bisect_left(L1,t)] 
        t += X

      #  print(bisect.bisect_left(L2,t))
        t = L2[bisect.bisect_left(L2,t)] 
        t += Y
        cnt += 1
    except:
        break
print(cnt)