N,M=map(int,input().split())
Tree=[i for i in range(N)]
size=[1]*N

def find(x):
  if x==Tree[x]:
      return x
  else:
      Tree[x]=find(Tree[x])
      return Tree[x]

def unite(x,y):
  s1=find(x)
  s2=find(y)
  if s1!=s2:
    Tree[s2]=s1
    size[s1]+=size[s2]
      
Edge=[]
for i in range(M):
  a,b,y=map(int,input().split())
  Edge.append((a-1,b-1,y))
Q=int(input())
people=[]
for q in range(Q):
  v,w=map(int,input().split())
  people.append((-1,v-1,w))

ans={}
for q in sorted(people+Edge,key=lambda x:-x[2]):
  if q[0]==-1:
    ans[q]=size[find(q[1])]
  else:
    unite(q[0],q[1])
    
for q in people:
  print(ans[q])