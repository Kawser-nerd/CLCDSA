winners = []
for i in range(4):
	winners.append( [ (i,0),(i,1),(i,2),(i,3) ] )
	winners.append( [ (0,i),(1,i),(2,i),(3,i) ] )
winners.append( [ (0,0),(1,1),(2,2),(3,3) ] )
winners.append( [ (3,0),(2,1),(1,2),(0,3) ] )

def is_winning(board, player, winner):
	for spot in winner:
		if board[spot[0]][spot[1]] not in [player,"T"]:
			return False
	return True

def get_status(board):
	for winner in winners:
		for player in ["X","O"]:
			if is_winning(board, player, winner):
				return "%s won" % player
	if any(["." in line for line in board]):
		return "Game has not completed"
	return "Draw"

cases = input()
for i in range(cases):
	board = []
	while 1:
		line = raw_input()
		if line.strip() == "":
			break
		board.append( line)
	
	status = get_status(board)
	print "Case #%d: %s" % (i+1, status)