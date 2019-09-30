"""
N=int(input())

print(800*N-int(N/15)*200)
"""
"""
N=int(input())
S=input()

max_n=0
temp=0
for strng in S:
	if strng=="I":
		temp+=1
		if max_n<temp:
			max_n=temp
	else:
		temp-=1
print(max_n)
"""
"""
N=int(input())

Q=1000000007
p=1
for i in range(1,N+1):
	p*=i
	p=p%Q
print(p%Q)
"""


n=int(input())
S=[input() for i in range(n)]
alphabet_dict={chr(97+i):100 for i in range(26)}
for s in S:
	temp={chr(97+i):0 for i in range(26)}
	for i in s:
		temp[i]+=1

	for key in alphabet_dict.keys():
		if alphabet_dict[key]>temp[key]:
			alphabet_dict[key]=temp[key]
result=""
alphabet=[chr(97+i) for i in range(26)]
for item in alphabet:
	for i in range(alphabet_dict[item]):
		result+=item
if result=="":
	print("\n")
else:
	print(result)

"""
(N,M) = [int(i)for i in input().split()]

if N>int(M/2):
	print(int(M/2))
else:
	hoge=int(M/2)-N
	print(N+int(hoge/2))
"""
"""
(N,A,B) = [int(i)for i in input().split()]
X=[int(i) for i in input().split()]

hirou=0
for i in range(N-1):
	length=X[i+1]-X[i]
	if length*A <= B:
		hirou+=length*A
	else:
		hirou+=B
print(hirou)

"""

"""
(n,m) = [int(i)for i in input().split()]
x=[int(i) for i in input().split()]
y=[int(i) for i in input().split()]

def func(left_idx,right_idx,under_idx,upper_idx):
	menseki=(x[right_idx]-x[left_idx])*(y[upper_idx]-y[under_idx]) % 1000000007
	x_len=right_idx - left_idx
	y_len=upper_idx - under_idx
	ret=menseki * (x_len-2) * (y_len-2)
	
	for i in range(left_idx,right_idx):
		for j in range(under_idx,upper_idx):
			ret= (ret+func(left_idx,i,under_idx,j)+func(i,right_idx,under_idx,j)+func(left_idx,i,j,upper_idx)+func(right_idx,i,under_idx,j)) % 1000000007
	return ret
menseki=(x[n-1]-x[0])*(y[m-1]-y[0]) % 1000000007
#???? (n-2)*(m-2)
print(menseki)
result = menseki*(n-2) % 1000000007
result *= (m-2)
result %= 1000000007


print(func(0,n-1,0,m-1))
"""