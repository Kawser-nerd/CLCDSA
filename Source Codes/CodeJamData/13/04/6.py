#!/usr/bin/python3.2

import sys
import math

def openable(keys, chests):
    lst = []

    for k in keys:
        lst.extend(chests.get(k, []))

    lst.sort(key=lambda c: c.id)

    return lst

def remove_key(keys, ckey):
    new_keys = dict(keys)
    new_keys[ckey] -= 1
    if new_keys[ckey] == 0:
        new_keys.pop(ckey)
    return new_keys

def add_keys(key1, key2):
    for (k, v) in key2.items():
        key1[k] = key1.get(k, 0) + key2[k]

def key_needed(chests):
    keys = []

    for (k, l) in chests.items():
        keys.extend([c.chest_key for c in l])

    return histogram(keys)

def key_possible(chests):
    keys = {}

    for (k, l) in chests.items():
        for c in l:
            add_keys(keys, c.keys)

    return keys

def visit(chests, keys):
    for key in keys.keys():
        for c in chests.get(key, []):
            if not c.visited:
                c.visited = True
                visit(chests, c.keys)


def treasure(keys, chests):
    if len(chests) == 0:
        return []

    # if not look doable return False
    for lc in chests.values():
        for c in lc:
            c.visited = False

    visit(chests, keys)

    for lc in chests.values():
        for c in lc:
            if c.visited == False:
                return None
    # open free chests if lexi order ?

    # remove_bad_keys
    
    candidates = openable(keys, chests)
    if len(candidates) == 0:
        return None

    for c in candidates:
        new_keys = remove_key(keys, c.chest_key)
        add_keys(new_keys, c.keys)

        chests[c.chest_key].remove(c)
        if chests[c.chest_key] == []:
            chests.pop(c.chest_key)

        res = treasure(new_keys, chests)
        if res != None:
            return [c.id] + res

        # roll back
        chests[c.chest_key] = chests.get(c.chest_key, []) + [c]

    return None

def histogram(lst):
    dic = {}
    for e in lst:
        dic[e] = dic.get(e, 0) + 1
    return dic

class Chest:
    def __str__(self):
        return 'chest#'+str(self.id)+ '('+ str(self.chest_key) +', '+ str(self.keys)+')'

    def __repr__(self):
        return str(self)


def pre_check(chests, keys):
    missing = key_needed(chests)
    possible = key_possible(chests)
    add_keys(possible, keys)

    for (k, v) in missing.items():
        v2 = possible.get(k, 0)
        if v2 < v:
            return False

    return True

def main():
    nb = int(f.readline().strip())
    for case_id in range(1, nb + 1):
        l = f.readline().strip()
        sizes = l.split(' ')
        nb_keys = int(sizes[0])
        nb_chests = int(sizes[1])

        l = f.readline().strip()
        keys = [int(k) for k in l.split(' ')]
        my_keys = histogram(keys)

        chests = {}
        chests_list = []
        for i in range(nb_chests):
            l = f.readline().strip()
            keys = [int(k) for k in l.split(' ')]

            chest_key = keys.pop(0)
            nb_keys = keys.pop(0)

            chest = Chest()
            chest.id = i+1
            chest.keys = histogram(keys)
            chest.nb_keys = nb_keys
            chest.chest_key = chest_key
            
            chests[chest_key] = chests.get(chest_key, []) + [chest]
            chests_list.append(chest)


        valid = None
        if pre_check(chests, my_keys):
            valid = treasure(my_keys, chests)

        if valid != None:
            open_list_s = ' '.join([str(e) for e in valid])
        else:
            open_list_s = 'IMPOSSIBLE'

        print('Case #%d: %s' % (case_id, open_list_s), file = o)
        case_id += 1
    
def open_files():
    if len(sys.argv) == 1:
        f = sys.stdin
        o = sys.stdout

    if len(sys.argv) == 2:
        f = open(sys.argv[1], 'r')
        o = sys.stdout

    if len(sys.argv) == 3:
        f = open(sys.argv[1], 'r')
        o = open(sys.argv[2], 'w')

    return (f, o)


(f, o) = open_files()
main()


