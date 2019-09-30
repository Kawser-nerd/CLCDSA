A,B,C,D,E,F = map(int, input().split())
ans = {"w":A*100, "s":0}
def density(water, sugar):
    return 100*sugar/(water+sugar)

for a in range(31):
    for b in range(31):
        water = (a*A+b*B)*100
        if water>F:
            continue
        max_sugar = min((a*A+b*B)*E, F-water)
        for c in range(max_sugar//C+1):
            sugar = c*C
            sugar += ((max_sugar-sugar)//D)*D
            if water+sugar==0: 
                continue
            if density(water, sugar)>density(ans["w"], ans["s"]):
                ans["w"] = water
                ans["s"] = sugar
print(ans["w"]+ans["s"], ans["s"])