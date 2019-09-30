dir_list = ['N','NNE','NE','ENE',
            'E','ESE','SE','SSE',
            'S','SSW','SW','WSW',
            'W','WNW','NW','NNW']

w_list  = [ 0.25, 1.55, 3.35, 5.45, 7.95, 
            10.75, 13.85, 17.15, 20.75, 24.45,
            28.45, 32.65 ]

Deg,Dis = map(int,input().split(' '))
W = 0
Diss = Dis / 60

for i in range(len(w_list)):
    if w_list[i] <= Diss:
        W += 1
    else:
        break

if W != 0:
    Dir = dir_list[int(Deg*10+1125) // 2250 % 16]
else:
    Dir = 'C'

print('{} {}'.format(Dir,W))