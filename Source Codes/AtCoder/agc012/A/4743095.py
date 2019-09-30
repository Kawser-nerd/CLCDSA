import numpy as np
import math
import fractions

class KyoPro:
    @staticmethod
    def ReadNumbers():
        return list(map(int, input().split()))

    @staticmethod
    def MakeStringFromNumbers(a):
        if len(a) == 0:
            return
        s = str(a[0])

        for i in range(1, len(a)):
            s += ' ' + str(a[i])
        
        return s

def main():
    n = int(input())
    a = KyoPro.ReadNumbers()

    a.sort()
    a.reverse()

    count = 0
    ans = 0
    for i in range(3 * n):
        if(i % 2 == 1):
            ans += a[i]
            count += 1
        if(count == n):
            break
    
    print(ans)

    

main()