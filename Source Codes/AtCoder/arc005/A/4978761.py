n=int(input())
list=input().split()
list[n-1]=list[n-1][:-1]
print(list.count("TAKAHASHIKUN")+list.count("Takahashikun")+list.count("takahashikun"))