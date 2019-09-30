#!/usr/bin/env python3

def process_test(test_id):
    d, n = list(map(int, input().split()))
    horses = list(map(int, input().split()) for i in range(n))
    dest_time = max((d - k) / s for k, s in horses)
    ans = d / dest_time
    print('Case #{:d}: {:.8f}'.format(test_id, ans))

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        process_test(i + 1)
