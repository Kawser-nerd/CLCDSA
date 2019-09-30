#C

def xxx(a):
    if a*10 - int(a*10) >= 0.5:
        return (int(a*10)+1)/10
    else:
        return int(a*10)/10

Deg, Dis = (int(x) for x in input().split())

v = xxx(Dis/60)
vlist = [0.2,1.5,3.3,5.4,7.9,10.7,13.8,17.1,20.7,24.4,28.4,32.6]
dlist = ["NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"]

for i in range(len(vlist)):
    if v <= vlist[i]:
        w = i
        break
else:
    w = 12
    
if w == 0:
    Dir = "C"
else:
    Deg = Deg/10
    for i in range(len(dlist)):
        if 11.25+22.5*i <= Deg < 33.75+22.5*i:
            Dir = dlist[i]
            break
    else:
        Dir = "N"

print(Dir,w)