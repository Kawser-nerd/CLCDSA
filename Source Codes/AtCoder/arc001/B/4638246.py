a,b=[int(i) for i in input().split()]
diff=abs(a-b)
ans=diff//10
diff-=10*ans
koho=[abs(diff-10)+1,abs(diff-5)+1,diff]
ans+=min(koho)
print(ans)