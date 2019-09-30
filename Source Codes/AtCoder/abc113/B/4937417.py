N = int(input())
T, A= map(int, input().split())
H = list(map(int, input().split()))
dH =[]
for i in H:
    dH.append(abs(A - (T - 0.006 * i)))
print(dH.index(min(dH)) + 1)