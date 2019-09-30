
def maximunBananas(key, target, length):
    if length < len(target):
        return 0

    d = {}
    for i in range(len(key)):
        if key[i] in d:
            d[key[i]] += 1
        else:
            d[key[i]] = 1

    for i in range(len(target)):
        if target[i] not in d:
            return 0

    advanced =len(target)
    for i in range(len(target) - 1):
        if target[:i+1] == target[len(target) - i - 1:]:
            advanced = len(target) - i - 1
    return 1 + int((length - len(target)) / advanced)

def expectedBananas(key, target, length):
    d = {}
    for i in range(len(key)):
        if key[i] in d:
            d[key[i]] += 1
        else:
            d[key[i]] = 1

    prob = 1
    for i in range(len(target)):
        if target[i] in d:
            prob *= d[target[i]] / len(key)
        else:
            return 0
    return prob * (length - len(target) + 1)

def calculate():
    k, l, s = [int(x) for x in input().split()]
    key = input()
    target = input()
    #print(maximunBananas(key, target, s))
    #print(expectedBananas(key, target, s))
    return maximunBananas(key, target, s) - expectedBananas(key, target, s)


def main():
    ncase = int(input())
    for i in range(ncase):
        print('Case #{}: {}'.format(i+1, calculate()))


if __name__ == '__main__':
    main()
