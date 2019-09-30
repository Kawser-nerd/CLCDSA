import itertools
import collections
import bisect

# Union find
class UnionFind():
    def __init__(self,size):
        self.table = [-1 for _  in range(size)]  # ????????????????????? ?????????????????
        self.size = [1 for _  in range(size)]

    #?????????
    def find(self,x):
        while self.table[x] >= 0:
            #?????,self.table[??index]???????x = ??index????????
            x = self.table[x]
        return x

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

    #??
    def union(self,x,y):
        s1 = self.find(x)#??index,table[s1]???????
        s2 = self.find(y)
        if s1 != s2:#???????
            if self.table[s1] != self.table[s2]:#????????????
                if self.table[s1] < self.table[s2]:
                    self.table[s2] = s1
                    self.size[s1] += self.size[s2]
                else:
                    self.table[s1] = s2
                    self.size[s2] += self.size[s1]
            else:
                #???????????,??????????????
                #???,????1???????????
                self.table[s1] += -1
                self.table[s2] = s1
                self.size[s1] += self.size[s2]
        return

    def group_size(self, x):
        return self.size[self.find(x)]


def main():
    N, M = map(int, input().split())
    st = []
    en = []
    for _ in range(M):
        i, j = map(int, input().split())
        st.append(i-1)
        en.append(j-1)

    # print(st)
    # print(en)
    ans = 0
    for i in range(M):
        uf = UnionFind(N)
        for j in range(len(st)):
            if i == j:
                continue
            uf.union(st[j], en[j])
        group = uf.find(0)
        if not all([uf.find(i) == group for i in range(N)]):
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()