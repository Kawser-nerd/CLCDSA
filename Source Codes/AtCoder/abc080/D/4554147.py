from collections import defaultdict


def main():
    N, C = list(map(int, input().split(' ')))
    s = []
    t = []
    c = []
    channels = defaultdict(lambda: set())
    for i in range(N):
        si, ti, ci = list(map(int, input().split(' ')))
        for t in range(si-1, ti):
            channels[t].add(ci)
    n_recorders = 0
    for t in channels:
        n_recorders = max(n_recorders, len(channels[t]))
    print(n_recorders)



main()