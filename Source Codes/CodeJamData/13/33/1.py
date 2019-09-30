#! /usr/bin/env python

class Interval:
    def __init__(self, w, e):
        self.w_ = w
        self.e_ = e

    def __str__(self):
        return "[" + str(self.w_) + " " + str(self.e_) + "]"

    def move(self, p):
        return Interval(self.w_ + p, self.e_ + p)

class Attack:
    def __init__(self, d, iv, s):
        self.d_ = int(d)
        self.s_ = int(s)
        self.iv_ = iv

    def __str__(self):
        return "day: " + str(self.d_) + " strength: " + str(self.s_) + " " + str(self.iv_)

def attack_cmp(x, y):
    if x.d_ > y.d_:
        return 1
    elif x.d_ == y.d_:
        if x.s_ > y.s_:
            return 1
        else:
            return -1
    else:
        return -1


class Tribe:
    def __init__(self, tmp):
        self.d_ = int(tmp[0])
        self.n_ = int(tmp[1])
        self.iv_ = Interval(int(tmp[2]), int(tmp[3]))
        self.s_ = int(tmp[4])
        self.dd_ = int(tmp[5])
        self.dp_ = int(tmp[6])
        self.ds_ = int(tmp[7])

    def getDay(self, n):
        return self.d_ + self.dd_ * (n - 1)

    def getPosition(self, n):
        return self.iv_.move(self.dp_ * (n - 1))

    def getStrenth(self, n):
        return self.s_ + self.ds_ * (n - 1)

    def getAttack(self, n):
        return Attack(self.getDay(n), self.getPosition(n), self.getStrenth(n))

T = int(input())
for TT in range(1, T + 1):
    N = int(input())
    tribe = []
    for i in range(0, N):
        tmp = [int(x) for x in input().split()]
        tribe.append(Tribe(tmp))
    attacks = []
    for i in range(0, N):
        for j in range(1, tribe[i].n_ + 1):
            attacks.append(tribe[i].getAttack(j))
    attacks.sort(key = lambda attack: (attack.d_, attack.s_))
    wb = 0
    eb = 0
    for i in range(0, N):
        if tribe[i].dp_ < 0:
            wb = min(tribe[i].getPosition(tribe[i].n_).w_, wb)
            eb = max(tribe[i].iv_.e_, eb)
        else:
            eb = max(tribe[i].getPosition(tribe[i].n_).e_, eb)
            wb = min(tribe[i].iv_.w_, wb)
    border = [0] * (eb - wb)
    ans = 0
    for att in attacks:
        success = False
        for bb in range(att.iv_.w_, att.iv_.e_):
            if border[bb - wb] < att.s_:
                success = True
                border[bb - wb] = att.s_
        if success:
            ans += 1
    print("Case #" + str(TT) + ": " + str(ans))
