# -*- coding:utf-8 -*-

class Prefecture():
    def __init__(self, i, P, Y):
        self.i = i
        self.P = P
        self.Y = Y
    
    def make_id(self, x):
        upper = str(self.P)
        while len(upper) < 6:
            upper = "0" + upper
        lower = str(x)
        while len(lower) < 6:
            lower = "0" + lower
        self.id = upper + lower            


def solve():
    N, M = list(map(int, input().split(" ")))
    prefectures = [None for i in range((N+1))]
    for i in range(M):
        p, y = list(map(int, input().split(" ")))
        if prefectures[p] is None:
            prefectures[p] = []
            prefectures[p].append(Prefecture(i, p, y))
        else:
            prefectures[p].append(Prefecture(i, p, y))

    # ID??
    ans = []
    for i in range(1, N+1):
        if prefectures[i] is None:
            continue

        prefectures[i].sort(key=lambda x: x.Y)
        for j in range(len(prefectures[i])):
            prefectures[i][j].make_id(j+1)
            ans.append(prefectures[i][j])
    
    # i????????
    ans.sort(key=lambda x: x.i)

    for prefecture in ans:
        print(prefecture.id)


if __name__ == "__main__":
    solve()