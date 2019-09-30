import sys
N = int(input())
if N == 1:
    print('Not Prime')
else:
    for i in range(2, int(N**1/2)+1):
        if N%i == 0:
            a = str(N)
            b = list(map(int, a.split()))
            if (int(a[-1]))%2 != 0 and a[-1] != '5' and sum(b)%3 != 0:
                print('Prime')
                sys.exit()
            else:
                print('Not Prime')
                sys.exit()
    print('Prime')