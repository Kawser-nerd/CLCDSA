O, E = [input() for _ in range(2)]
rest_str = ''

for i in range(len(O)):
    try:
        rest_str += O[i]+E[i]
    except IndexError:
        rest_str += O[i]

print(rest_str)