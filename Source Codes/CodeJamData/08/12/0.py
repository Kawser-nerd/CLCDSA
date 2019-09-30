#!/usr/bin/env python

C = int(raw_input())
for X in range(1, C + 1):
    N = int(raw_input())
    M = int(raw_input())
    customers = []
    for tmp in range(M):
        line = map(lambda x: int(x), raw_input().split(' '))
        _line = []
        for _tmp in range(line[0]):
            _line.append((line[_tmp * 2 + 1], line[_tmp * 2 + 2]))
        customers.append(_line)
    for tmp in range(2 ** N):
        _list = [tmp & 1 == 1, tmp & 2 == 2, tmp & 4 == 4, tmp & 8 == 8, tmp & 16 == 16, tmp & 32 == 32, tmp & 64 == 64, tmp & 128 == 128, tmp & 256 == 256, tmp & 512][:N]
        HELLOWORLD = True
        for _tmp in customers:
            _customer = False
            for _HELLOWORLD in _tmp:
                if (_list[_HELLOWORLD[0] - 1] and 1 or 0) == _HELLOWORLD[1]:
                    _customer = True
                    break
            HELLOWORLD = HELLOWORLD and _customer
        if HELLOWORLD:
            break
    print 'Case #%d:' % X,
    if HELLOWORLD:
        for tmp in range(N):
            print _list[tmp] and 1 or 0,
        print
    else:
        print 'IMPOSSIBLE'
