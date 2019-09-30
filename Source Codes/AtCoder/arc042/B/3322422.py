#!/usr/bin/env python3

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __mult__(self, scaler):
        return Vector(self.x * scaler, self.y * scaler)

    def dot(self, other):
        return self.x * other.x + self.y * other.y

    def length(self):
        return self.dot(self) ** 0.5

    def abs_cross(self, other):
        return abs(self.x * other.y - self.y * other.x)

def main():
    x, y = map(int, input().split())
    n = int(input())
    xy = []
    for i in range(n):
        xi, yi = map(int, input().split())
        xy.append((xi - x, yi - y))
    xy.append(xy[0])
    del x, y

    mi = 999999999.0
    for i in range(n):
        v1 = Vector(*xy[i])
        v2 = Vector(*xy[i + 1])
        mi = min(mi, v1.length())
        if cross_orthogonal(v1, v2):
            mi = min(mi, dist_orthogonal(v1, v2))
    print(mi)

def cross_orthogonal(v1, v2):
    v3 = v2 - v1
    return v1.dot(v3) * v2.dot(v3) < 0

def dist_orthogonal(v1, v2):
    return v1.abs_cross(v2) / (v2 - v1).length()

main()