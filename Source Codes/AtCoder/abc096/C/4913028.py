h,w = map(int, input().split())
#get hight and weidth 
glid = [0] * ( h+ 2)

h_index = [-1, 0, 0,  1]
w_index = [ 0, -1, 1, 0]



glid[0]=["."] * ( w + 2 )
glid[h + 1 ] = ["."] * ( w + 2 )

for i in range(h):
	temp1 = ["."]
	temp2 = list(input())
	temp1.extend(temp2)
	temp1.append(".")
	glid[ i + 1 ] = temp1

# get glids 

cnt = 0

for j in range(h):
	for k in range(w):
		if glid[ j + 1 ][ k + 1 ] == "#" and glid[ j ][ k + 1 ] == "." and glid[ j + 2 ][ k + 1 ] == "." and glid[ j + 1][ k  ] == "." and glid[ j + 1][ k +2 ] == "." :
			cnt += 1

if cnt > 0 :
	print("No")
else:
	print("Yes")