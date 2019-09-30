def solve(N, p, q, r, s):
    """ solve the problem """

    #print(N, p, q, r, s)

    items = [(i * p + q) % r + s for i in range(N)]
    #print('items: ', items)
    _sum = sum(items)
    part = _sum / 3

    #print(part)
    part1 = 0
    part2 = 0
    part3 = 0
    i = 0
    j = N-1
    while part1 + items[i] < part:
        part1 += items[i]
        i += 1

    while part3 + items[j] < part:
        part3 += items[j]
        j -= 1


    #print(part1, part3)
    if i == j:
        #print(_sum, part1, part3, i, j)
        return (part1 + part3) /_sum
    else:
        ans = 0.0

        _part1 = part1
        _part3 = part3
        _part2 = _sum - _part1 - _part3
        ans = max( ans, (_sum - max(_part1, _part2, _part3)) / _sum)

        _part1 = part1 + items[i]
        _part3 = part3
        _part2 = _sum - _part1 - _part3
        ans = max( ans, (_sum - max(_part1, _part2, _part3)) / _sum)

        _part1 = part1 + items[i]
        _part3 = part3 + items[j]
        _part2 = _sum - _part1 - _part3
        ans = max( ans, (_sum - max(_part1, _part2, _part3)) / _sum)

        _part1 = part1
        _part3 = part3 + items[j]
        _part2 = _sum - _part1 - _part3
        ans = max( ans, (_sum - max(_part1, _part2, _part3)) / _sum)
        
        _part1 = part1
        _part3 = part3
        _i = i
        _j = j
        #print(ans)
        while _i <= _j:
            #print('hi');
            _part1 += items[_i]
            _part2 = _sum - _part1 - _part3
            #if ans < (_sum - max(_part1, _part2, _part3)) / _sum: print('g')
            ans = max( ans, (_sum - max(_part1, _part2, _part3)) / _sum)
            
            if _part1 == max(_part1, _part2, _part3):
                break
            _i += 1

        _part1 = part1
        _part3 = part3
        _i = i
        _j = j
        while _i <= _j:
            #print('hi2');
            _part3 += items[_j]
            _part2 = _sum - _part1 - _part3
            #if ans < (_sum - max(_part1, _part2, _part3)) / _sum: print('g')
            ans = max( ans, (_sum - max(_part1, _part2, _part3)) / _sum)
            if _part3 == max(_part1, _part2, _part3):
                break
            _j -= 1
        #print(ans)
            
    return  ans


def parse():
    """ parse input """

    N, p, q, r, s = map(int, input().split(' '))

    return N, p, q, r, s


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %.11f' % (t, result))


if __name__ == '__main__':

    main()
