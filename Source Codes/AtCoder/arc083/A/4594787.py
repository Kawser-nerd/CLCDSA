from fractions import gcd
A,B,C,D,E,F = map(int, input().split())
ans = {"w":A*100, "s":0}
def density(water, sugar):
    return 100*sugar/(water+sugar)

G = gcd(C,D)
for a in range(31):
    for b in range(31):
        water = (a*A+b*B)*100
        if water>F:
            continue
        max_sugar = min((a*A+b*B)*E, F-water)
        sugar = int(G*(max_sugar//G))
        if sugar<min(C,D): continue
        if water+sugar==0: 
            continue
        if density(water, sugar)>density(ans["w"], ans["s"]):
            ans["w"] = water
            ans["s"] = sugar
            #print(water, sugar)
print(ans["w"]+ans["s"], ans["s"])