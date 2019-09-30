from sys import stdin

N = stdin.readline().rstrip()
c = stdin.readline().rstrip()

count = []
count.append(c.count('1'))
count.append(c.count('2'))
count.append(c.count('3'))
count.append(c.count('4'))
print(max(count),min(count))