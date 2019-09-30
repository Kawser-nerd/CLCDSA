# MISC
read_int = lambda:int(raw_input().strip())
read_ints = lambda:[int(x) for x in raw_input().split()]
count_to = lambda n:xrange(1,n+1)

# GENERAL GRID TOOLS
def read_grid(rows, columns, parse_cell=None):
    if parse_cell is None:
        parse_cell = lambda x:x
    grid = {}
    for r in count_to(rows):
        rowstring = raw_input()
        for c in count_to(columns):
            grid[r,c] = parse_cell(rowstring[c-1])
    return grid

def print_grid(rows, columns, grid, f=None):
    if f is None:
        f = lambda x:x
    for r in count_to(rows):
        print "".join(f(grid[r,c]) for c in count_to(columns))

def create_grid(rows, columns, f):
    return dict(
        ((r,c), f(r,c))
        for r in count_to(rows)
        for c in count_to(columns))

# GENERAL SOLVE LOOP
def solve_all(solve):
    num_cases = read_int()
    for i in count_to(num_cases):
         print "Case #{0}:".format(i),
         solve()

# SOLUTION
def read_board():
    h, w = read_ints()
    board = [int(raw_input().strip(), 16) for i in count_to(h)]
    return w,h,board

def tidy_board(w, h, board):
    board_filter = (1 << w) - 1
    patterna = 0xaaaaaaaaaaaaaaaa & board_filter
    patternb = patterna >> 1
    board2 = []
    for i in xrange(0, h, 2):
        board2.append(board[i] ^ patterna)
        if i+1<h:
            board2.append(board[i+1] ^ patternb)
    return board2

def filter_row(row, w, amount):
    return reduce(lambda x,y:x&y, (row<<i for i in xrange(amount)))

def filter_board_h(w, h, board, amount):
    return [filter_row(row, w, amount) for row in board]

def filter_board_v(w, h, board, amount):
    return [
        reduce(lambda x,y:x&y, (board[i+j] for j in xrange(amount)))
        for i in xrange(h-amount+1)]+([0]*(amount-1))

def filter_board(w,h,board,amount):
    return filter_board_h(w,h,filter_board_v(w,h,board,amount),amount)

def intersect_board(w,h,b1,b2):
    return [a&b for (a,b) in zip(b1,b2)]

def union_board(w,h,b1,b2):
    return [a|b for (a,b) in zip(b1,b2)]

def excise(w,h,cutter,target):
    for i in xrange(h):
        target[i]=target[i]&~cutter[i]

def log2(x):
    c=1
    while x>0:
        x>>=1
        c+=1
    return c

def find_first(w,h,board):
    for i,row in enumerate(board):
        if row:
            return log2(row), i
    return None

def make_mask(w,h,mask_size,mask_x,mask_row):
    board = [0]*h
    bits = ((1<<mask_size)-1)<<(mask_x-mask_size-1)
    for i in xrange(mask_row, mask_row+mask_size):
        board[i] = bits
    return board

def invert_board(w,h,board):  
    board_filter = (1 << w) - 1
    return [row ^ board_filter for row in board]

def print_board(w,h,board):
    for line in board:
        print bin(line)[2:].zfill(w)

def has_any(board):
    return any(bool(b) for b in board)

#def flip_board(w,h,board):
#    bit = 1<<(w-1)
#    board2=[]
#    for i in xrange(w):
#        for j in xrange(h
#
#        bit>>=1

def shl_board(board,i):
    return [b<<i for b in board]

def solve_case():
    w,h,board = read_board()
    board = tidy_board(w,h,board)
    iboard = invert_board(w,h,board)
    results = {}
    #checksum = 0
    bboard = list(board)
    done = [0]*h
    for target_size in xrange(min(w,h),0,-1):
        #print target_size
        valid_boxes_a = filter_board(w,h,board,target_size)
        valid_boxes_b = filter_board(w,h,iboard,target_size)
        all_boxes = union_board(w,h,valid_boxes_a,valid_boxes_b)
        progress = False
        while True:
            next = find_first(w,h,all_boxes)
            if next is None:
                break
            x,r = next
            box = make_mask(w,h,target_size,x,r)
            if has_any(intersect_board(w,h,box,done)):
                print target_size
                print_board(w,h,done)
                print
                print_board(w,h,box)
                assert 0
            done = union_board(w,h,box,done)
            excise(w,h,box,all_boxes)
            excise(w,h,shl_board(box,target_size-1),all_boxes)
            excise(w,h,box,board)
            excise(w,h,box,iboard)
            if target_size not in results:
                results[target_size]=0
            results[target_size]+=1
            progress=True
        #if progress:
        #    print target_size
        #    print_board(w,h,board)
        #    print
        #    print_board(w,h,iboard)
    checksum = 0
    if sum(k*k*v for (k,v) in results.items())!=w*h:
        print sum(k*k*v for (k,v) in results.items()), w*h
        print_board(w,h, board)
        print_board(w,h, iboard)
        assert False
    print len(results)
    for k,v in sorted(results.items(), key=lambda item:item[0], reverse=True):
        print k,v
    
    #print_board(w,h, board)
    #print
    #print_board(w,h, invert_board(w,h,board))
    #print
    #board2 = filter_board_h(w,h,board,6)
    #board3 = filter_board_v(w,h,board2,6)
    #x,r = find_first(w,h,board3)
    #print_board(w,h,make_mask(w,h,6,x,r))
    #print
    #print_board(w,h,board2)
    #print
    #print_board(w,h,board3)



solve_all(solve_case)
