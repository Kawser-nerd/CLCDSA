#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
from collections import defaultdict
from itertools import combinations, permutations


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N = int(fin.readline())
    worker_machine = {}
    machine_worker = defaultdict(set)
    for i in range(N):
        bitmap = list(fin.readline().strip())
        known = set()
        for j, b in enumerate(bitmap):
            if b == '1':
                known.add(j)
                machine_worker[j].add(i)
        worker_machine[i] = known
    debug(case, machine_worker)

    worker_groups = {}
    machine_groups = {}
    group = 0
    groups = []
    base_cost = 0
    for i in range(N):
        if i in worker_groups:
            continue
        queue = [i]
        group += 1
        group_workers = []
        group_machines = []
        while queue:
            next = queue.pop()
            if next in worker_groups:
                continue
            worker_groups[next] = group
            group_workers.append(next)
            machines = worker_machine[next]
            for machine in machines:
                if machine in machine_groups:
                    continue
                machine_groups[machine] = group
                group_machines.append(machine)
                for worker in machine_worker[machine]:
                    queue.append(worker)

        for worker in group_workers:
            base_cost += len(group_machines) - len(worker_machine[worker])
        groups.append((len(group_workers), len(group_machines)))
    for i in range(N):
        if i not in machine_groups:
            groups.append((0, 1))

    debug(case, groups)

    best = (100000000000, ())
    for perm in permutations(groups):
        cost = 0
        tw, tm = 0, 0
        for nw, nm in perm:
            if nw == nm:
                continue
            cost += nw * tm + nm * tw
            tw += nw
            tm += nm
            if tw == tm:
                tw, tm = 0, 0
        best = min(best, (cost, perm))
    debug(case, base_cost, best)

    print("Case #%d: %s" % (case, base_cost + best[0]))

