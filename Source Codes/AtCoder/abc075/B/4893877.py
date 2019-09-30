h,w = map(int, input().split())
#get hight and weidth 
glid = [0] * ( h+ 2)

h_index = [-1, -1, -1, 0, 0, 1, 1, 1]
w_index = [-1, 0, 1, -1, 1, -1, 0, 1]

glid[0]=[0] * ( w + 2 )
glid[h + 1 ] = [0] * ( w + 2 )

for i in range(h):
	temp1 = [0]
	temp2 = list(input())
	temp1.extend(temp2)
	temp1.append(0)
	glid[ i + 1 ] = temp1

# get glids 

for j in range(h):
	for k in range(w):
		if glid[ j + 1 ][ k + 1 ] == "#":
			continue
		else:
			cnt = 0
			for n in range(8):
				if glid[ j  + 1 + h_index[ n ] ][ k + 1 + w_index[ n ]] == "#" :
					cnt += 1
			glid[ j + 1 ][ k +1 ] = str(cnt)

for h_print in range ( h ):
	for w_print in range ( w ):
		print(glid[h_print + 1][w_print + 1], end="")
	print()