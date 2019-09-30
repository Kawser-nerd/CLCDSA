import sys
sys.setrecursionlimit(2 * 10 ** 5)


class TrieNode:
    def __init__(self, char):
        self.char = char
        self.nextnode = dict()
        self.is_indict = False


class Trie:
    def __init__(self, charset):
        self.charset = charset
        self.root = TrieNode('')

    def add(self, a_str):
        node = self.root
        for i, char in enumerate(a_str):
            if char not in node.nextnode:
                node.nextnode[char] = TrieNode(char)
            node = node.nextnode[char]
            if i == len(a_str) - 1:
                node.is_indict = True

    def dfs(self, node, dep):
        ret, cnt = 0, 0
        if node.is_indict:
            return 0
        for s in '01':
            if s not in node.nextnode:
                cnt += 1
            else:
                ret ^= self.dfs(node.nextnode[s], dep + 1)
        height = L - dep
        if cnt % 2:
            power2 = 0
            while height > 0 and height % 2 == 0:
                power2 += 1
                height //= 2
            ret ^= 2 ** power2
        return ret

    def debug_output(self, node, now):
        print(node.char, list(node.nextnode.items()), node.is_indict, now)
        if node.is_indict:
            print(now)
        for n in node.nextnode.values():
            self.debug_output(n, now + n.char)

N, L = map(int, input().split())
T = Trie('01')
for _ in range(N):
    T.add(input())
# T.debug_output(T.root, '')
print("Alice" if T.dfs(T.root, 0) else "Bob")