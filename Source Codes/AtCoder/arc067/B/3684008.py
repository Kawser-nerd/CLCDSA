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
for item in alphabet_dict.items():
	for i in range(item[1]):
		result+=item[0]
if result=="":
	print("\n")
else:
	print(result)
"""
"""
(N,M) = [int(i)for i in input().split()]

if N>int(M/2):
	print(int(M/2))
else:
	hoge=int(M/2)-N
	print(N+int(hoge/2))
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