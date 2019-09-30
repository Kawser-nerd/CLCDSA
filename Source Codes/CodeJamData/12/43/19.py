outfile = "output.txt"

def popinput(input):
    return int(input.readline().split()[0])


def solve(file):
    input = open(file, 'r')
    output = open(outfile, 'w')
    cases = popinput(input)
    for i in range(cases):
        output.write("Case #%(number)d: %(answer)s\n" % {"number":i + 1, "answer":solvecase(input)})
        print('Case solved:', i)

  

def solvecase(input):
    n = popinput(input)
    highest = list(map(int, input.readline().split()))
    height = {}
    height[n] = 1000000000
    height[n - 1] = 999900000
    for i in range(1, n):
        for j in range(i + 1, highest[i - 1]):
            if highest[j - 1] > highest[i - 1]:
                return 'Impossible'
    for i in range(2, n):
        j = n - i
        a = highest[j - 1]
        if a == n:
            height[j] = height[a] - 100000 * i + 2*(i - 1) + 1
        else:
            print(a)
            b = highest[a - 1]
            c = height[a] - (height[b] - height[a]) * (a - j) / (b - a)
            height[j] = c - 4
    height = list(map(int, height.values()))
    return str.replace(str(height).strip('[]'),',','')
