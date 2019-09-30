N = int(input())
L,R = [None]*N,[None]*N
for i in range(N):
  L[i],R[i] = map(int,input().split())
L.append(0)
R.append(0)
L.sort(reverse=True)
R.sort()

def it():
  for l,r in zip(L,R):
    if r < l:
      yield 2*(l-r)
    else:
      return

print(sum(it()))