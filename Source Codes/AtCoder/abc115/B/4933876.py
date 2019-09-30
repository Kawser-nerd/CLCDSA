n = int(input())
P = sorted([int(input()) for i in range(n)],reverse=True)

print(round(sum(P) - (P[0] / 2)))