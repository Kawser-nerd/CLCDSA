n = int(input())
h = [int(i) for i in input().split()]

h_unique = list(set(h))
#print(h_unique)

check = [1] + [0]*(n) + [1]
h = [-1] + h + [-1]
ans = 0
split = 0
for i in range(max(h)):
  if i in h_unique:
    for j in range(len(h)):
      if h[j] == i:
        check[j] = 1
        if check[j-1] == 0 and check[j+1] == 0:
          split += 1
        elif check[j-1] == 1 and check[j+1] == 1:
          split -= 1
  ans += split+1
  #print(split)
print(ans)