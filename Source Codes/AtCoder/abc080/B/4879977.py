N=input()
print('Yes' if int(N)%sum(int(i) for i in N)==0 else 'No')