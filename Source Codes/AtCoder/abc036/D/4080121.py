from collections import Counter


def cal(N, bridges):
    mod = 10**9 + 7
    bridge_cnt = Counter()
    bw_list = [[1,1] for _ in range(N+1)]
    con_list = [[] for _ in range(N+1)]
    for l, r in bridges:
        bridge_cnt[r] += 1
        bridge_cnt[l] += 1
        con_list[l].append(r)
        con_list[r].append(l)
    root = bridges[0][0]

    def update(cur, parent):
        # logger.debug(cur)
        for child in con_list[cur]:
            if child == parent:
                continue
            else:
                update(child, cur)
                # enter here if children all updated
            # black
            bw_list[cur][0] = (bw_list[cur][0]*bw_list[child][1]) 
            # white
            bw_list[cur][1] = (bw_list[cur][1] * (bw_list[child][0] + bw_list[child][1]))
            # debug(cur)

            # debug(bw_list)
    update(root, 0)
    

    return max([sum(bw) for bw in bw_list]) % mod


import sys
stdin = sys.stdin
 
# sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

 
n = ni()
td = [tuple(li()) for _ in range(n-1)]

print(cal(n, td))