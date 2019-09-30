N,L=map(int,input().split())
List=[]
for i in range(N):
  List.append(input())
List.sort()
List="".join(List)
print(List)