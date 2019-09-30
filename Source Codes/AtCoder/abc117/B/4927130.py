n = int(input())
l = list(map(int, input().split()))
l.sort()
if 2 * l[-1] < sum(l):
    print("Yes")
else:
    print("No")