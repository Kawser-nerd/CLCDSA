List=list(map(int,input().split()))
sorted(List)
print("YES" if List.count(5)==2 and List.count(7)==1 else "NO")