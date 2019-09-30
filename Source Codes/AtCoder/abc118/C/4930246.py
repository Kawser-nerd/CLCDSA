N = int(input())
monsters = list(map(int, input().split()))

def damage(monsters):
    minvalue = min(monsters)
    index = monsters.index(minvalue)
    for i in range(len(monsters)):
        if i != index:
            monsters[i] %= minvalue

while len(monsters) != 1:
    damage(monsters)
    while 0 in monsters:
        monsters.remove(0)
    

print(min(monsters))