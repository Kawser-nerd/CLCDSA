def is_finished(currents, p):
    return max(currents) >= p


def testcase():
    n, p = [int(x) for x in input().split(" ")]

#    print("N {n} p {p}".format(n=n, p=p))

    requirements = [int(x) for x in input().split(" ")]

    ingridients = []

    for i in range(n):
        ingridients.append(sorted([int(x) for x in input().split(" ")]))

    currents = [0] * n

    candidate = 1
    result = 0

    while not is_finished(currents, p):
        # check if the candidate is possible

        success = True
        for i in range(n):
            while currents[i] < p and ingridients[i][currents[i]] < 0.9 * (requirements[i] * candidate):
                currents[i] += 1
            success = success and (
            currents[i] < p and ingridients[i][currents[i]] <= 1.1 * (requirements[i] * candidate))

        if success:
            result += 1
            for i in range(n):
                currents[i] += 1
        else:
            candidate += 1

    return result


t = int(input())

for num in range(t):
    print("Case #{num}: {result}".format(num=num + 1, result=testcase()))