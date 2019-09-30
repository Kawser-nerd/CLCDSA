# coding: utf-8
# Your code here!
 
def main():
    n = int(input())
    a,b = map(int,input().split())
    if n <= a:
        return 'Takahashi'
    if n <= b+1:
        return 'Aoki'
    if a == b and n % (a+1) == 0:
        return 'Aoki'
    if a >= b:
        return 'Takahashi'
    return 'Aoki'
 
 
print(main())