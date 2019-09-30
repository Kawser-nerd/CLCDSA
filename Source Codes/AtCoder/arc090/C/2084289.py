from heapq import heappop, heappush
import sys

MOD, INF = 1000000007, float('inf')


def count_routes(visited, s, links):
    counts = [0] * n
    counts[s] = 1
    for dv, v in sorted((d, v) for v, d in enumerate(visited) if d != INF):
        for u, du in links[v].items():
            if dv + du == visited[u]:
                counts[u] += counts[v]
                counts[u] %= MOD
    return counts


def solve(s, t, links):
    q = [(0, 0, s, -1, 0), (0, 0, t, -1, 1)]
    visited_fwd, visited_bwd = [INF] * n, [INF] * n
    collision_nodes, collision_links = set(), set()
    limit = 0
    while q:
        cost, cost_a, v, a, is_bwd = heappop(q)
        if is_bwd:
            visited_self = visited_bwd
            visited_opp = visited_fwd
        else:
            visited_self = visited_fwd
            visited_opp = visited_bwd

        relax_flag = False
        cost_preceding = visited_self[v]
        if cost_preceding == INF:
            visited_self[v] = cost
            relax_flag = True
        elif cost > cost_preceding:
            continue

        cost_opp = visited_opp[v]
        if cost_opp != INF:
            limit = cost + cost_opp
            if cost == cost_opp:
                collision_nodes.add(v)
            else:
                collision_links.add((v, a) if is_bwd else (a, v))
            break

        if relax_flag:
            for u, du in links[v].items():
                nc = cost + du
                if visited_self[u] < nc:
                    continue
                heappush(q, (nc, cost, u, v, is_bwd))

    collision_time = limit / 2
    while q:
        cost, cost_a, v, a, is_bwd = heappop(q)
        if cost > limit:
            break
        visited_self = visited_bwd if is_bwd else visited_fwd
        if visited_self[v] == INF:
            visited_self[v] = cost
        if is_bwd:
            continue
        if cost_a == collision_time:
            collision_nodes.add(a)
        elif cost == collision_time:
            collision_nodes.add(v)
        else:
            collision_links.add((v, a) if is_bwd else (a, v))

    counts_fwd = count_routes(visited_fwd, s, links)
    counts_bwd = count_routes(visited_bwd, t, links)
    shortest_count = 0
    collision_count = 0

    for v in collision_nodes:
        if visited_fwd[v] == visited_bwd[v]:
            r = counts_fwd[v] * counts_bwd[v]
            shortest_count += r
            shortest_count %= MOD
            collision_count += r * r
            collision_count %= MOD

    for u, v in collision_links:
        if visited_fwd[u] + visited_bwd[v] + links[u][v] == limit:
            r = counts_fwd[u] * counts_bwd[v]
            shortest_count += r
            shortest_count %= MOD
            collision_count += r * r
            collision_count %= MOD

    return (shortest_count ** 2 - collision_count) % MOD


n, m = map(int, input().split())
s, t = map(int, input().split())
s -= 1
t -= 1
links = [{} for _ in range(n)]
for uvd in sys.stdin.readlines():
    u, v, d = map(int, uvd.split())
    # for _ in range(m):
    #     u, v, d = map(int, input().split())
    u -= 1
    v -= 1
    links[u][v] = d
    links[v][u] = d
print(solve(s, t, links))