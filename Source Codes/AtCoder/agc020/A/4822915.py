import sys
input = sys.stdin.readline

N, A, B = map(int, input().split())
print("Alice" if (B-A+1)%2 == 1 else "Borys")