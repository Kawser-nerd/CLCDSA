mod = 10**9+7


H, W, A, B = map(int, input().split())


class Fact():
    def __init__(self, H, W):
        self.mod = 10**9+7
        self.facts = [1]*(H+W-1)
        for i in range(1, H+W-1):
            self.facts[i] = self.facts[i-1]*i % mod

        self.i = [pow(self.facts[-1], mod-2, mod)]
        for i in range(1, H+W-1)[::-1]:
            self.i.append(self.i[-1]*i % mod)
        self.i.reverse()

    def comb(self, n, r):
        ret = self.facts[n] * self.i[n-r]*self.i[r]
        return ret

    def print_fact(self):
        print(self.facts)


f = Fact(H, W)

all_path = f.comb(H+W-2, H-1)

remove_path = 0
for i in range(B):
    tmp = f.comb(H-A+i-1, i)
    tmp *= f.comb(W-i-1+A-1, A-1)
    remove_path += tmp

remove_path %= mod

print((all_path - remove_path) % mod)