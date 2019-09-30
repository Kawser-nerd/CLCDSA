from math import sqrt, ceil

def main():
    N = int(input())

    up_b = ceil(sqrt(N))

    min_a = 10 ** 10
    for b in range(up_b):
        if N % (b+1) == 0:
            min_a = min(max(N/(b+1), b+1), min_a)
            min_a = int(min_a)
    
    print(len(str(min_a)))
        
main()