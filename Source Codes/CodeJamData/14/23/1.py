import collections

n = int(input())

def is_possible(order, adjlist, seen, i, at):

  # first go to next thing in order.
  while i < len(order) and order[i] in adjlist[at]:
    seen.add(order[i])
    i = is_possible(order, adjlist, seen, i+1, order[i])

  # then just go everywhere if we can
  if i >= len(order):
    for j in adjlist[at]:
      if j not in seen:
        seen.add(j)
        is_possible(order, adjlist, seen, i, j)

  return i

for caseno in range(1,1+n):
  num_nodes, num_edges = [int(x) for x in input().split()]
  names = [input() for _ in range(num_nodes)]
  edgelist = [[int(x)-1 for x in input().split()] for _ in range(num_edges)]
  adjlist=collections.defaultdict(list)
  for edge in edgelist:
    adjlist[edge[1]].append(edge[0])
    adjlist[edge[0]].append(edge[1])

  names_sorted = list(zip(names, range(num_nodes)))
  names_sorted.sort()
  nodes_sorted = [x[1] for x in names_sorted]

  order = []
  for _ in range(num_nodes):
    for node in nodes_sorted:
      if node not in order:
        test_order = order + [node]
        start = test_order[0]
        seen = set()
        seen.add(start)
        i = is_possible(test_order, adjlist, seen, 1, start)
        if i >= len(order) and len(seen) == num_nodes:
          order = test_order
          break

  print("Case #"+str(caseno)+": "+''.join([names[x] for x in order]))
