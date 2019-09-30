#!/usr/bin/env python3


class Node:
    def __init__(self, label):
        self.label = label
        self.mark = False
        self.input = 0
        self.e = []

    def __str__(self):
        return "Node({},mark={},num={},edges={}]".format(self.label,self.mark,self.num,self.e)

class G:
# It has array V of Nodes
    def __init__(self, N):

        n = N
        self.V = [ Node(i) for i in range(n) ]

    def addEdges(self,s,M):
      self.V[s].e.extend(M)
      for x in M:
        self.V[x].input = self.V[x].input + 1

    def size(self):
        return self.n;

    def __str__(self):
        return 'G[size={},nodes={}]'.format(self.n,self.V)

    def nums(self):
        """Returns list of (label, num) pairs"""
        return [(i,self.V[i].num) for i in range(self.size())]


def DFS_marking(g,v):
    """Gets graph return dict with mapping"""
    def DFS_m(g,node,marked):
        q = [node]
        while q:
            v = q.pop()
            if v not in marked:
                marked[v] = 1
                q.extend(g.V[v].e)
            else:
              return False
        return True

    marked = dict()
    return DFS_m(g,v.label,marked)


def solve(g):
  starts = filter(lambda x: x.input == 0, g.V);
  results = [DFS_marking(g,v) for v in starts]
  return all(results)


if __name__ == "__main__":
    T = int(input());
    for c in range(T):
        N = int(input())
        graph = G(N)
        for i in range(N):
          M = [int(x) - 1 for x in input().split()]
#          print(M)
          assert M[0] + 2 == len(M)
          graph.addEdges(i,M[1:])
        R = solve(graph)
        output = "Yes"
        if R:
          output = "No"
        print("Case #{}: {}".format(c+1,output))