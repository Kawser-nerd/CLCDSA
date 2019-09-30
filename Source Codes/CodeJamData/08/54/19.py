import sys

def calc(H, W, R):
    board=[[0 for x in range(W)] for y in range(H)]
    for r,c in R:

        board[r-1][c-1]=None

    board[0][0]=1
    for i in range(H):
        for j in range(W):
            if board[i][j]!=None:
                x,y=i-1,j-2
                if x>=0 and y>=0 and board[x][y]!=None:
                    board[i][j]+=board[x][y]
                x,y=i-2,j-1
                if x>=0 and y>=0 and board[x][y]!=None:
                    board[i][j]+=board[x][y]
    return board[H-1][W-1] % 10007

def go(name):
    f=file(name)

    line=f.readline().strip()
    total=int(line)
    for i in range(total):

        H,W,R=[int(x) for x in f.readline().strip().split()]

        rocks=[]
        for j in range(R):
            rocks.append([int(x) for x in f.readline().strip().split()])
        r=calc(H,W,rocks)
        print "Case #%d: %d" %(i+1, r)
    f.close()

            
try:
    fn=sys.argv[1]
except:
    print "Usage:\n", "python", sys.argv[0]+" input_file_name"
    sys.exit(1)

go(fn)
