import collections
from pprint import pprint

def main():
    for testcase in range(1, int(input()) + 1):
        print(f"Case #{testcase}: {solve()}")

def solve():
    hd_orig, ad_orig, hk_orig, ak_orig, buff, debuff = map(int, input().strip().split())
    start_pos = (hd_orig, ad_orig, hk_orig, ak_orig, 'debuffing', 0)
    deq = collections.deque([start_pos])
    while deq:
        hd, ad, hk, ak, state, turn = deq.popleft()
        assert hd <= hd_orig
        if turn >= 350:
            return "IMPOSSIBLE"
        if state == 'debuffing':
            deq.appendleft((hd, ad, hk, ak, 'buffing', turn))
            if ak - debuff >= hd:
                # About to die, lets cure
                deq.append((hd_orig-ak, ad, hk, ak, 'debuffing', turn+1))
            elif ak > 0 and debuff:
                ak_new = max([0, ak-debuff])
                deq.append((hd-ak_new, ad, hk, ak_new, 'debuffing', turn+1))
        elif state == 'buffing':
            deq.appendleft((hd, ad, hk, ak, 'attacking', turn))
            if ak >= hd:
                # About to die, lets cure
                deq.append((hd_orig-ak, ad, hk, ak, 'buffing', turn+1))
            elif ad < hk and buff:
                deq.append((hd-ak, ad+buff, hk, ak, 'buffing', turn+1))
        else:
            assert state == 'attacking'
            if hk <= ad:
                # Kill him now
                return turn + 1
            if ak >= hd:
                # About to die, lets cure
                deq.append((hd_orig-ak, ad, hk, ak, 'attacking', turn+1))
            elif ad:
                deq.append((hd-ak, ad, hk-ad, ak, 'attacking', turn+1))

    return "IMPOSSIBLE"


main()
