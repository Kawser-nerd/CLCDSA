from copy import deepcopy
from sys import stdin
import collections
import functools

DEBUG = False

def debug_print(*args):
    if DEBUG:
        print args

class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)
      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)

@memoized
def cheapest(groups):
    debug_print('cheapest called with groups', groups)

    if len(groups) == 0:
        debug_print('base case, returning 0 cost')
        return 0

    groups = list(groups)
    cost = 0

    for g in list(groups):
        if g[0] == g[1]:
            cost += g[0] * g[0]
            groups.remove(g)

    if len(groups) == 0:
        debug_print('out, returning cost ', cost)
        return cost

    groups.sort(key=lambda g: max(g[0], g[1]))

    group_to_fix = groups.pop()
    # heuristic, if we can add x 0,1 or 1,0 groups, or one 1,x x,1?

    debug_print('starting recursion')
    min_cost = None
    other_options = set(groups)
    debug_print('other options', other_options)
    for other_option in other_options:
        debug_print('trying option', other_option, group_to_fix)
        new_groups = deepcopy(groups)
        new_cost = cost
        combo_group = (group_to_fix[0] + other_option[0], group_to_fix[1] + other_option[1])
        new_groups.remove(other_option)
        new_groups.append(combo_group)

        new_groups.sort()
        new_groups.sort(key=lambda g: max(g[0],g[1]))
        new_cost += cheapest(tuple(new_groups))

        if min_cost is None:
            min_cost = new_cost
        else:
            min_cost = min(min_cost, new_cost)
    debug_print('returning', min_cost)
    return min_cost


def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):
        debug_print('****************************************')
        debug_print('case: ', case)
        N = int(stdin.readline().strip())

        groups = []

        for i in range(1,N+1):
            groups.append(set(['w_' + str(i)]))
            groups.append(set(['m_' + str(i)]))

        debug_print('start_groups', groups)

        total_trainings = 0

        for worker in range(1,N+1):
            accessible_machines = map(int, list(stdin.readline().strip()))
            debug_print('worker: ', worker)
            new_group = set(['w_' + str(worker)])
            for machine in range(1,N+1):
                if accessible_machines[machine-1]:
                    debug_print('accessible: ', machine)
                    total_trainings += 1
                    new_group.add('m_' + str(machine))
            debug_print('new_group: ', new_group)
            groups_to_merge = []
            for group in groups:
                group_acquired = False
                for elem in new_group:
                    if group_acquired:
                        continue
                    if elem in group:
                        groups_to_merge.append(group)
                        group_acquired = True
            debug_print('groups_to_merge', groups_to_merge)
            for group in groups_to_merge:
                groups.remove(group)
                new_group = new_group.union(group)
                debug_print(new_group)
            groups.append(new_group)
            debug_print('result_groups', groups)

        debug_print('groups, trainings:', groups, total_trainings)

        new_groups = []
        for group in groups:
            g = [0,0]
            for elem in group:
                if elem[0] == 'w':
                    g[0] += 1
                else:
                    g[1] += 1
            new_groups.append((g[0], g[1]))

        new_groups.sort()
        new_groups.sort(key=lambda g: max(g[0],g[1]))
        c = cheapest(tuple(new_groups))

        print "Case #{}: {}".format(case, c - total_trainings)

if __name__ == "__main__":
    main()
