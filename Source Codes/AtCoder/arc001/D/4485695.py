def c_puzzle(Board):
    """
    8???????????????????3??????????
    ???5????????????????????????????????
    """
    board_size = 8

    def is_inside(row, col, board_width=board_size, board_height=board_size):
        return 0 <= row < board_height and 0 <= col < board_width

    def can_place_queen(row, col, board):
        if row >= board_size:
            return True

        # (row, col) ???????????
        previous_state = board[row][col]
        board[row][col] = 'Q'

        # (row, col)????????????????????????????????
        is_rejected = False
        for k in range(board_size):
            is_rejected |= (row, k) != (row, col) and board[row][k] == 'Q'
            is_rejected |= (k, col) != (row, col) and board[k][col] == 'Q'
            is_rejected |= ((row - k, col - k) != (row, col)
                            and is_inside(row - k, col - k, board_size, board_size)
                            and board[row - k][col - k] == 'Q')
            is_rejected |= ((row + k, col + k) != (row, col)
                            and is_inside(row + k, col + k, board_size, board_size)
                            and board[row + k][col + k] == 'Q')
            is_rejected |= ((row + k, col - k) != (row, col)
                            and is_inside(row + k, col - k, board_size, board_size)
                            and board[row + k][col - k] == 'Q')
            is_rejected |= ((row - k, col + k) != (row, col)
                            and is_inside(row - k, col + k, board_size, board_size)
                            and board[row - k][col + k] == 'Q')
        if is_rejected:
            board[row][col] = previous_state
            return False

        # ??????
        for k in range(board_size):
            if can_place_queen(row + 1, k, board):
                return True
        # row?????????????????????????
        board[row][col] = previous_state
        return False

    for col in range(board_size):
        if can_place_queen(0, col, Board):
            return '\n'.join(''.join(line) for line in Board)
    return 'No Answer'

Board = [list(input()) for _ in range(8)]
print(c_puzzle(Board))