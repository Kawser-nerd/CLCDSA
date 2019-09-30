#!/usr/bin/env python3

def winner(X, S, L):
    if S * L % X:  return 'RICHARD'
    if X <= 2:     return 'GABRIEL'
    if X >= 7:     return 'RICHARD'
    if L < X:      return 'RICHARD'
    if 2 * S <= X: return 'RICHARD'
    if (X, S, L) == (5, 3, 5):
                   return 'RICHARD'
    return 'GABRIEL'

T = int(input())
for case in range(1, T+1):
    X, R, C = map(int, input().split())
    print("Case #{}: {}".format(case, winner(X, min(R, C), max(R, C))))

