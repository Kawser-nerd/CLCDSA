#!/usr/bin/env python

def ldiff(d1, d2):
    d1c = list(d1)
    for e in d2:
        if e in d1c:
            d1c.remove(e)
    return d1c

def solve(chests, keys, open_chests=None):
    if open_chests is None: open_chests = []
    unopened_chests = [(i, c) for i, c in enumerate(chests) if i not in open_chests]
    if len(unopened_chests) == 0: return ''

    possible_keys = sum([c['keys'] for _, c in unopened_chests], list(keys))
    needed_keys = [c['key'] for _, c in unopened_chests]
    if ldiff(needed_keys, possible_keys):
        return 'IMPOSSIBLE'

    possible_keys = set(keys)
    while True:
        possible_keys_new = set(sum([c['keys'] for _, c in unopened_chests if c['key'] in possible_keys], list(possible_keys)))
        if possible_keys_new == possible_keys:
            break
        possible_keys = possible_keys_new
    if set([c['key'] for _, c in unopened_chests]) - possible_keys:
        return 'IMPOSSIBLE'

    for i, chest in unopened_chests:
        if chest['key'] not in keys: continue
        new_keys = list(keys)
        new_keys.remove(chest['key'])
        new_keys = new_keys + chest['keys']
        sol = solve(chests, new_keys, open_chests + [i])
        if sol != 'IMPOSSIBLE':
            return ('%d %s' % (i+1, sol)).strip()
    return 'IMPOSSIBLE'

cases_count = int(raw_input())
for t in range(cases_count):
    chests = []
    _, n = [int(i) for i in raw_input().split(' ')]
    keys = [int(i) for i in raw_input().split(' ')]
    for _ in range(n):
        chest_keys = [int(i) for i in raw_input().split(' ')]
        chests.append({'key': chest_keys.pop(0), 'keys': chest_keys[1:]})
    print "Case #%d: %s" % (t+1, solve(chests, keys))
