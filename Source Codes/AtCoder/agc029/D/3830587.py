x,y,num = map(int, input().split())
gaiz = [x]*x
kaisu = x
for _ in range(num):
    xg,yg = map(int,input().split())
    if xg >= yg:
        sa = xg-yg
        if yg < gaiz[sa]:
            gaiz[sa]=(yg)
 
if len(gaiz) ==0:
    print(kaisu)
else:
    for num,(maegai,gai) in enumerate(zip(gaiz[:-1],gaiz[1:])):
        if maegai>gai and num+gai < kaisu:
            kaisu = num+gai
    print(kaisu)