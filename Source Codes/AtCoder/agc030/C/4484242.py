def run(K):
    n_max = 500
    '''
    K <= 500?????n = K???1????1???????
        111
        222
        333
    K?4????????n = K/2??????????
        1234
        5678
        3412
        7856
    ???n+i+1??i??????????????
        1234
        5178
        3412
        7851
    K = 1000????n = 500????????????501?999???????
    '''
    n = 0
    trouts = []
    if K <= n_max:
        n = K
        for i in range(K):
            trouts.append([i+1]*K)
    else:
        n = n_max
        change = n_max*2 - K
        c1 = [i for i in range(1, n_max+1)]
        # c - 1 + n_max - c + 1 (c>0)
        # 0 + n_max (c==0)
        c2 = [i for i in range(2, change+1)] + [i for i in range(n_max+1, n_max*2+1-change)]
        if change > 0:
            c2 += [1]
        for i in range(n_max):
            shift = (i//2) * 2
            if i % 2 == 0:
                trouts.append(c1[shift:] + c1[:shift])
            else:
                trouts.append(c2[shift:] + c2[:shift])
    return (n, trouts)


def main():
    K = int(input())
    n, trouts = run(K)
    print(n)
    for i in range(len(trouts)):
        print(' '.join(map(str, trouts[i])))


if __name__ == '__main__':
    main()