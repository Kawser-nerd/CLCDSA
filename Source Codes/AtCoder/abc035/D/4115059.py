# from loguru import logger
from collections import defaultdict
from heapq import heappush, heappop
import sys
stdin = sys.stdin
def li(): return map(int, stdin.readline().split())

# def debug(*params):
#     logger.debug(params)


class Solution(object): # pylint: disable=too-few-public-methods
    def __init__(self):
        pass

    def dijkstra(self, distances, edge_dict):
        distances[0] = 0
        # cost to dest, dest_id
        sorted_q = [(0, 0)]
        # searched = set()
        # suppose all edge cost are positive
        while sorted_q:
            cost_to_cur, cur = heappop(sorted_q)
            

            for dest_cost in edge_dict[cur]:
                old_dis_to_nei = distances[dest_cost[0]]
                new_dis_to_nei = cost_to_cur + dest_cost[1]
                if old_dis_to_nei > new_dis_to_nei:
                    distances[dest_cost[0]] = new_dis_to_nei

                    heappush(sorted_q, (distances[dest_cost[0]], dest_cost[0]))
        return distances

    def treasure_hunt(self, params, treasure_points, edges):
        num_towns, num_edges, time_limit = params
        distances = []
        rev_dis = []
        inf = float('INF')
        for _ in range(num_towns):
            # distances.append([inf for _ in range(num_towns)])
            distances.append(inf)
            rev_dis.append(inf)

        edge_dict = defaultdict(list)
        rev_edge_dict =defaultdict(list)
        for e in edges:
            # key:value :: source:(dest, dis)
            # -1 adjust idx
            edge_dict[e[0]-1].append((e[1]-1, e[2]))
            rev_edge_dict[e[1]-1].append((e[0]-1, e[2]))

        distances[0] = 0
        rev_dis[0] = 0
        distances = self.dijkstra(distances, edge_dict)
        rev_dis = self.dijkstra(rev_dis, rev_edge_dict)

        treasure = [(time_limit -distances[town_id] - rev_dis[town_id]) * treasure_points[town_id] for town_id in range(num_towns)]
        # debug(distances)
        # debug(treasure)
        return max(treasure)
params = tuple(li())
treasure_points = tuple(li())
edges = [tuple(li()) for _ in range(params[1])]
s = Solution()
print(s.treasure_hunt(params, treasure_points, edges))