N = int(input())
edge = []
a = 1
for b in range(1,N+1):
    print('? {} {}'.format(a,b))
    d = int(input())
    edge.append([d,b])
edge.sort()
a = edge[-1][1]
ans = edge[-1][0]
for b in range(1,N+1):
    print('? {} {}'.format(a,b))
    ans = max(ans,int(input()))
print('! {}'.format(ans))