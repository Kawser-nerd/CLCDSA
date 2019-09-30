K = int(input())
ans = [K//50 + i for i in range(50)]
if K%50:
  for i in range(K%50):
    ans[i] += 51
    ans = [a-1 for a in ans]
print(50)
ans = [str(a) for a in ans]
print(" ".join(ans))