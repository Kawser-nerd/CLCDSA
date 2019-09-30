from collections import Counter

N = int(input())

w = input().split()

w[-1] = w[-1][:-1]
w = [s.lower()  for s in w]

C = Counter(w)

print(C["takahashikun"])