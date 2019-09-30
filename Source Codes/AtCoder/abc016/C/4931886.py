from collections import defaultdict
class Graph(object):
    def __init__(self):
        self.graph = defaultdict(list)
    def __len__(self):
        return len(self.graph)
    def add_edge(self, src, dst):
        self.graph[src].append(dst)
        self.graph[dst].append(src)
N,M = map(int,input().split())
friends = Graph()
for m in range(M):
    a,b = map(int,input().split())
    friends.add_edge(a,b)
for i in range(N):
    nums = []
    for j in friends.graph[i+1]:
        for k in friends.graph[j]:
            if k not in friends.graph[i+1]:
                nums.append(k)
    nums = set(nums)
    if i+1 in nums:
        nums.remove(i+1)
    print(len(nums))