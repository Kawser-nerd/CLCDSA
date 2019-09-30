s = input()
k = int(input())
sub = set()
for i in range(len(s)):
  for j in range(1,k+1):
    sub.add(s[i:i+j])
print(sorted(list(sub))[k-1])