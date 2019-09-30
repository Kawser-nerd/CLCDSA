import sys

T = int(raw_input())

for i in xrange(T):
        sys.stdout.write('Case #%d: ' % (i+1))
        N, M = [int(x) for x in raw_input().split()]
        codes = [''] + [raw_input().strip() for _ in xrange(N)]
        edges = {}
        for _ in xrange(M):
                u, v = [int(x) for x in raw_input().split()]
                if not u in edges:
                        edges[u] = set()
                if not v in edges:
                        edges[v] = set()
                edges[u].add(v)
                edges[v].add(u)
        
        best = None
        used_e = {}
        used_v = {}
        def make_e(u, v):
                if u < v:
                        return (u,v)
                else:
                        return (v,u)
        def dfs(dep, u, status):
                global best
                if best and status > best:
                        return
                #print dep, u, status, used_v, used_e
                if len(used_v) == N:
                        flag = True
                        for e in used_e:
                                if used_e[e] == 1:
                                        flag = False
                                        break
                        if flag and (not best or status<best):
                                best = status
                if u in edges:
                        for v in edges[u]:
                                e = make_e(u,v)
                                if e in used_e and used_e[e] == 1:
                                        used_e[e] = 2
                                        dfs(dep+1, v, status)
                                        used_e[e] = 1
                                if not v in used_v:
                                        if e in used_e:
                                                print e
                                                assert False
                                        used_e[e] = 1
                                        used_v[v] = 1
                                        dfs(dep+1, v, status+codes[v])
                                        del used_e[e]
                                        del used_v[v]
        for i in xrange(N):
                used_v[i+1] = 1
                dfs(0, i+1, codes[i+1])
                del used_v[i+1]
        print best
        sys.stdout.flush()
