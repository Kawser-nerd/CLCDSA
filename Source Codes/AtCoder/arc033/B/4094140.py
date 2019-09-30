#!/usr/bin/env python3
NA, NB = map(int, input().split())
A = set(map(int, input().split()))
B = set(map(int, input().split()))
print(len(A & B) / len(A | B))