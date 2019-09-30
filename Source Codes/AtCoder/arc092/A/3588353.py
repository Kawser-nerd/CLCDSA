def inpl(): return [int(i) for i in input().split()]

N = int(input())
red = [inpl() for _ in range(N)]
blue = [inpl() for _ in range(N)]
red = sorted(red,key = lambda x: -x[0])
blue = sorted(blue,key = lambda x: x[1])
ans = 0

for a,b in red:
    for c,d in blue:
        if a<c and b<d:
            ans +=1
            blue.remove([c,d])
            break
print(ans)