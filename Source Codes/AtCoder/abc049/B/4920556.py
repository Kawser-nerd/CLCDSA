import sys
import math

input = sys.stdin.readline

h, w = map(int, input().rstrip().split())

pic = list(input().rstrip().split() for _ in range(h))


for i in range(h):
    print(pic[i][0])
    print(pic[i][0])