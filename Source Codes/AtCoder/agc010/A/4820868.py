import sys
input()
count = 0
a_list = list(map(int, input().split()))
for a in a_list:
  count += a%2

print("YES") if count%2==0 else print("NO")