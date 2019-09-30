from numpy import*;N,K=map(int,input().split());m,L,o=zeros((3*K,3*K)),2*K,0
for _ in[0]*N:x,y,c=input().split();t=c=='W';m[int(x)%L,int(y)%L]+=2*t-1;o+=t
for _ in[0,0]:m[L:]=m[:K];m=cumsum(m,0);m[:L]-=m[K:];m=m.T
m=m[:L,:L];print(o-int((m+roll(roll(m,K,0),K,1)).min()))