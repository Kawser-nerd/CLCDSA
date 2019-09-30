#coding: utf-8
N, X = map(int, input().split())
m = [int(input()) for i in range(N)]
print((X - sum(m)) // min(m) + N)