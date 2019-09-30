def calculate():
    c, d, v = [int(x) for x in input().split()]
    coins = [int(x) for x in input().split()]

    currentMax = 0;
    extraCoin = 0;

    for i in range(len(coins)):
        if currentMax > v:
            return extraCoin
        while currentMax < coins[i] - 1:
            extraCoin += 1
            currentMax += (currentMax + 1) * c
        currentMax += coins[i] * c

    while currentMax < v:
        extraCoin += 1
        currentMax += (currentMax + 1) * c

    return extraCoin





def main():
    ncase = int(input())
    for i in range(ncase):
        print('Case #{}: {}'.format(i+1, calculate()))


if __name__ == '__main__':
    main()
