H,W,h,w=map(int,input().split())
if H%h==0 and W%w==0:
	print("No")
else:
	print("Yes")
	for i in range(H):
		print(' '.join("-1000" if i%h or j%w else str(1000*(h*w-1)-1) for j in range(W)))