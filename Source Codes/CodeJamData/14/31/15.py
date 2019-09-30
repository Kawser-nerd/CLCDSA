import functools
import multiprocessing
import fractions


def pow2(x):
  return x != 0 and ((x & (x-1)) == 0)


def solve(cs, f):
  if not pow2(f.denominator):
    return cs, 'impossible'
  ret = 1
  while f < fractions.Fraction(1, 2):
    ret += 1
    f *= 2
  return cs, ret


def reducer(l, result):
  l.append(result)


if __name__ == '__main__':
  T = int(input())
  l = []
  with multiprocessing.Pool(processes=8) as pool:
    for cs in range(T):
      # x, y = [int(x) for x in input().split('/')]
      f = fractions.Fraction(input())
      solve(cs, f)
      pool.apply_async(solve, args=(cs+1, f,), callback=functools.partial(reducer, l))
    pool.close()
    pool.join()
  for cs, result in sorted(l, key=lambda x: x[0]):
    print('Case #{}: {}'.format(cs, result))
