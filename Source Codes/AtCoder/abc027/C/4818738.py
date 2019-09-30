import sys
input = sys.stdin.readline

N = int(input())
if N == 1:
    print('Aoki')
else:
    tmp = 1
    index = 2
    while True:
        tmp += 2**index
        if N <= tmp:
            print('Takahashi')
            break
        else:
            tmp += 2**index
            if N <= tmp:
                print('Aoki')
                break
            else:
                index += 2