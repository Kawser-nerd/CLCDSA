import sys
from operator import itemgetter
N = int(input())
nim = 0

for _ in [0]*N:
    X, Y, Z = map(int, input().split())
    M = int(input())
    bomb = [tuple(map(int, sys.stdin.readline().split())) for _ in [0]*M]

    for i, max_n in enumerate((X, Y, Z)):
        bomb.sort(key=itemgetter(i))
        nim ^= bomb[0][i]
        nim ^= max_n-bomb[-1][i]-1

print("WIN" if nim else "LOSE")