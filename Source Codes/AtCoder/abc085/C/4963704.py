NY = input().split()
N_Y = [int(s)for s in NY]

counter_Y = 0
counter = 0
listx = []
for i in range(N_Y[0]+1):
    for j in range(N_Y[0]+1):
        k = N_Y[0] - i - j
        counter_Y = 10000 * i + 5000 * j + 1000 * k
        if counter_Y == N_Y[1] and k >= 0:
            listx = [i,j,k]
            counter += 1

if counter == 0:
    print("-1 -1 -1")
else:
    print("{} {} {}".format(listx[0],listx[1],listx[2]))