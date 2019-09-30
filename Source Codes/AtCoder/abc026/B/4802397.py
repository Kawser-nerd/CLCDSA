import math

n = int(input())
r = sorted([int(input())**2 for i in range(n)], reverse=True)

red = r[::2]
white = r[1::2]

print( (sum(red)-sum(white))*math.pi )