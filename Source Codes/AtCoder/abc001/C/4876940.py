Deg,Dis=map(int,input().split())
Direction=["N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N","C"]
Speed=[0.24,1.54,3.34,5.44,7.94,10.74,13.84,17.14,20.74,24.44,28.44,32.64,200]
for i in range(len(Direction)):
    if Deg <112.5+225*i:
        break
for j in range(len(Speed)):
    if Dis<=Speed[j]*60:
        break

if j==0:
    i=-1

print(Direction[i],j)