n = int(input())
k = int(input())
def check(i):
    return min( 2*(k-i), 2*i)
print(sum([ check(int(i)) for i in input().split() ]))