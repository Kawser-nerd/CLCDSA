B = [[int(i) for i in input().split()] for _ in range(2)]
C = [[int(i) for i in input().split()] for _ in range(3)]

import copy
memo = {}

turn_num = {'o':0, 'x':1}
reverse_turn = {'o':'x', 'x':'o'}
def DP(turn, count, board):
	if count == 9:
		if ''.join(board) not in memo:
			memo[''.join(board)] = evaluation(board)
		return memo[''.join(board)]
	else:
		p_ox = [-float('inf'), -float('inf')]
		for i in range(9):
			if board[i] == '-':
				tmp_turn = reverse_turn[turn]
				tmp_count = count + 1
				tmp_board = copy.deepcopy(board)
				tmp_board[i] = turn
				if ''.join(tmp_board) in memo:
					tmp_p_ox = memo[''.join(tmp_board)]
				else:
					tmp_p_ox = DP(tmp_turn, tmp_count, tmp_board)
				p_ox = max(p_ox, tmp_p_ox, key=lambda x:x[turn_num[turn]])
		memo[''.join(board)] = p_ox
		return p_ox

def evaluation(board):
	p_o = 0
	p_x = 0
	for i in range(2):
		for j in range(3):
			if board[i*3+j] == board[(i+1)*3+j]:
				p_o += B[i][j]
			else:
				p_x += B[i][j]
	for i in range(3):
		for j in range(2):
			if board[i*3+j] == board[i*3+(j+1)]:
				p_o += C[i][j]
			else:
				p_x += C[i][j]
	return [p_o, p_x]


d = DP('o', 0, ['-' for _ in range(9)])
for i in range(2):
	print(d[i])