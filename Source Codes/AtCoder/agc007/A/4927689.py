import re

pattern = re.compile('^(?:\.*)(#+)(?:\.*)$')

H, W = map(int, input().split())
board = [input() for i in range(H)]

c = 0
for row in board:
    result = pattern.match(row)
    if result == None or result.start(1) != c:
        print("Impossible")
        exit()
    else:
        c = result.end(1) - 1

print("Possible")