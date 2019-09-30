
import re

def LoadInput():

   with open("input.txt") as f:
      return f.read()
   
def Output(text):

   with open("output.txt", "w") as f:
      f.write(text)

def ParseInput(text):

    text = text.split('\n')

    caseCount = int(text.pop(0))

    testCases = []

    for i in range(caseCount):

       n, k = map(int, text.pop(0).split())
       board = text[:n]
       text = text[n:]

       testCases += [ [ n, k, board ] ]
       
    return testCases

def DoTestCase(case):
    
    N, K, board = case
    result = []

    #move all rows to the right
    for line in board:
        line = ''.join([ c for c in line if c != '.' ])
        line = '.' * N + line
        line = line[-N:]
        result += [ line ]

    blue = bool(FindKJoin(result, N, K, 'B'))
    red = bool(FindKJoin(result, N, K, 'R'))

    if blue and red:
        return "Both"
    elif blue:
        return "Blue"
    elif red:
        return "Red"
    else:
        return "Neither"

def FindKJoin(board, N, K, team):

    board = ' '.join(board)

    #horizontal
    if re.search(team * K, board):
        return True

    #vertical
    if re.search(team + ('.'*N + team)*(K-1), board):
        return True

    #upleft/downright
    if re.search(team + ('.'*(N+1) + team)*(K-1), board):
        return True

    #upright/downleft
    if re.search(team + ('.'*(N-1) + team)*(K-1), board):
        return True

    return False

def main():

    testCases = ParseInput(LoadInput())

    result = []
    
    for i, case in enumerate(testCases):
        result.append("Case #{0}: {1}".format(i + 1, DoTestCase(case)))

    result = '\n'.join(result)

    Output(result)
    print "done, result:"
    print result


    

if __name__ == "__main__":

    main()
