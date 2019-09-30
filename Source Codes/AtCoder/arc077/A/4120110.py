N = int(input())
A = list(map(int, input().split()))

ans = []

l1 = A[0::2]
l2 = A[1::2]
if N % 2 == 0:
    l2 = l2[::-1]
    ans = l2+l1
else:
    l1 = l1[::-1]
    ans = l1+l2

print(" ".join(list(map(str, ans))))