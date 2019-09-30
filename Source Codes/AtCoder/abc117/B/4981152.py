n = int(input())
l = list(map(int,input().split()))

longest = max(l)
total = sum(l) - longest

if longest < total:
    print("Yes")
else:
    print("No")