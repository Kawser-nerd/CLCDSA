N = int(input())
def to_bin(n):
    if n == 0: return '0'
    base = 1
    bin = []
    while(n!=0):
        if n%2 == 0:
            bin.append('0')
        else:
            bin.append('1')
            n=n-1
        n = n//-2

    return bin[::-1]
l = to_bin(N)
print(''.join(l))