a = int(input())
ar = list(map(int,input().split(" ")))
br = list(map(int,input().split(" ")))
cr = []
for i in range(1,a+1):
    count = sum(ar[0:i]) + sum(br[i-1:a])
    cr.append(count)
print(max(cr))