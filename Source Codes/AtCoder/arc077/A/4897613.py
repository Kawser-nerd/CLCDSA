N=int(input())
A=list(map(str, input().split(' ')))
even=A[0::2]
odd=A[1::2]
print(' '.join(even[::-1])+' '+' '.join(odd)) if N%2==1 else print(' '.join(odd[::-1])+' '+' '.join(even))