# -*- coding:utf-8 -*-
first,last = input().split()
n = int(input())
# words ? start goal ????? n+2?
words = [input() for _ in range(n)]
words.insert(0,first)
words.append(last)


def debug_print(t):
    for i,row in enumerate(t):
        print("%s:%s"%(i,row))

def is_candidate(w1,w2):
    count = 0
    r = False
    for s1,s2 in zip(w1,w2):
        if s1 == s2:
            count += 1
    if len(w1) - count == 1:
        r = True
    return r

class Path:
    def __init__(self,word,prev = None):
        self.prev = prev
        self.word = word
    def print_path(self):
        if self.prev:
            self.prev.print_path()
        print((self.word))
    def count_prev(self,n=0):
        if not self.prev:
            return -1
        return self.prev.count_prev(n+1)+1

def bfs(s,g):
    ans = []
    queue = [Path(s)]
    memo = [0 for _ in range(n+2)]
    if s == g:
        print(0)
        print(s)
        print(g)
        return 0
    while queue:
        cur = queue.pop(0)
        for i,word in enumerate(words):
            if memo[i] == 0 and not word == s:
                if is_candidate(word,cur.word):
                    if word == g:
                        cur = Path(word,cur)
                        print(max(cur.count_prev(),0))
                        cur.print_path()
                        return 0
                    memo[i] += 1
                    queue.append(Path(word,cur))
    print(-1)
bfs(first,last)