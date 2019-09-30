n=int(input())
List=list(map(int,input().split()))
print(sorted(List)[-1]-sorted(List)[0])