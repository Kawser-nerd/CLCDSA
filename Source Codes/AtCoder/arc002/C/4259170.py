N = int(input())
c = input()
import itertools 

command = ['A','B','X','Y']
LorR = [0] * 16
i = 0
for ABXY in itertools.product(command,repeat=2):
    LorR[i] = ABXY 
    i += 1

choice = [0] * 120
i = 0
for ABXY in itertools.combinations(LorR,2):
    choice[i] = ABXY 
    i += 1



count = [0] * 120
for i in range(120):

    j = 0

    while j < N:

        if j < N-1:
            
            if (c[j] == choice[i][0][0] and c[j+1] == choice[i][0][1]) or (c[j] == choice[i][1][0] and c[j+1] == choice[i][1][1]):
                
                j += 2
                count[i] += 1

            
            else:
                
                j += 1
                count[i] += 1

        else:

            count[i] += 1
            j += 1

        

print(min(count))