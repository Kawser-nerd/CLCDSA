#!/usr/bin/env python

import sys

def rotate(board):
    rotated = []
    size = len(board)
    for i in range(size):
        row = []
        for j in range(size):
            row.append('.')
        rotated.append(row)
    
    for rotated_col in range(size):
        rotated_row = 0
        original_col = size - 1
        while True:
            while original_col >= 0 and board[rotated_col][original_col] == '.':
                original_col -= 1
            if original_col < 0:
                break
            rotated[rotated_row][rotated_col] = board[rotated_col][original_col]
            
            original_col -= 1
            rotated_row += 1
    
    return rotated

def asName(player):
    if player == 'R':
        return "Red"
    elif player == 'B':
        return "Blue"
    else:
        raise IOError("Unknown player " + player)

def extractWinner(winners):
    if len(winners) == 2:
        return "Both"
    elif len(winners) == 0:
        return "Neither"
    else:
        return winners.pop()

def getWinner(board, run):
    winners = set()
    
    size = len(board)
    for row in range(size):
        for col in range(size):
            player = board[row][col]
            if player == "." or player in winners:
                continue
            
            # Horizontal
            if (row + run) <= size:
                for i in range(run):
                    if board[row + i][col] != player:
                        break
                else:
                    winners.add(asName(player))
            
            # Vertical
            if (col + run) <= size:
                for i in range(run):
                    if board[row][col + i] != player:
                        break
                else:
                    winners.add(asName(player))
            
            # Diagonal up
            if (row + run) <= size and col >= (run - 1):
                for i in range(run):
                    if board[row + i][col - i] != player:
                        break
                else:
                    winners.add(asName(player))
            
            # Diagonal down
            if (row + run) <= size and (col + run) <= size:
                for i in range(run):
                    if board[row + i][col + i] != player:
                        break
                else:
                    winners.add(asName(player))

    return extractWinner(winners)

def updateWinner(current_winner, board, run):
    new_winner = getWinner(board, run)
    winners = set()
    if current_winner != "Neither":
        winners.add(current_winner)
    if new_winner != "Neither":
        winners.add(new_winner)

    return extractWinner(winners)

def main():
    nCases = int(sys.stdin.readline())
    case = 0

    while True:
        case += 1
        if case > nCases:
            break;

        winner = "Neither"
        [N, K] = [int(x) for x in sys.stdin.readline().split()]
        board = []
        for i in range(N):
            line = sys.stdin.readline()
            row = []
            for j in range(N):
                row.append(line[j])
            board.append(row)
        
        rotated = rotate(board)
        winner = updateWinner(winner, rotated, K)
        
        print 'Case #%d: %s' % (case, winner)
    
main()
