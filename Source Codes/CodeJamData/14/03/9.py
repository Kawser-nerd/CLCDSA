#Template code developed by Brett Olsen (brett.olsen@gmail.com), 2013
#for the Google Code Jam programming contest

###############################################################################
# Imports go here
###############################################################################

#For faster numerical analysis
import numpy as np

import sys

#Needed for the memoization decorator
import collections
import functools

###############################################################################
# Global variables (for caching, etc.) go here
###############################################################################

###############################################################################
# Decorators (taken from http://wiki.python.org/moin/PythonDecoratorLibrary)
###############################################################################

class memoize(object):
   """Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   """
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)
      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)

###############################################################################
# Functions
###############################################################################

def precalculate():
    """Perform any calculations that need to be performed before the main path
    (e.g., preparing lookup tables, etc.)
    
    N.B. Make sure you make any important variables global so that other
    functions can access them.
    """
    pass

def read_input(infile):
    """This function should take an open input file, load in all of the
    relevant information for a single case of the problem, and output it
    as a single object.    
    """
    #Some utility functions to read in particular types of input
    def read_int():
        return int(infile.readline().strip())
    def read_ints():
        return np.array(infile.readline().split(), dtype=int)
    def read_bigints(): #For ints that won't fit directly in an int32 array
        line = infile.readline().split()
        return np.array(map(lambda x: int(x), line))
    def read_float():
        return float(infile.readline().strip())
    def read_floats():
        return np.array(infile.readline().split(), dtype=float)
    def read_string():
        return infile.readline().strip()
    def read_strings():
        return np.array(infile.readline().split(), dtype=object) #N.B. general dtype
    
    R, C, M = read_ints()
    
    return R, C, M

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    R, C, M = case
    
    free = R * C - M
    assert free >= 1
    
    board = np.zeros((R, C), dtype=int) - 1
    
    def write_board(board):
        d = {0:'.', 1:'c', 2:'*'}
        s = "\n"
        for row in board:
            for num in row:
                try:
                    s += d[num]
                except KeyError:
                    #s += "X"
                    raise ValueError("Board not filled in!")
            s += "\n"
        return s
    
    #Clicking in the corner is always optimal!
    board[0,0] = 1
    
    #Always possible with no mines!
    if M == 0:
        board[board == -1] = 0
        return write_board(board)
    
    #Always possible with one free square, if you click on the free square.
    if free == 1:
        #Fill all the empty squares in with mines
        board[board == -1] = 2
        return write_board(board)
        
    
    #Fill in the shortest sides while we have enough mines to do so:
    while min(R, C) <= M:
        if R < C:
            board[:,C-1] = 2
            C -= 1
            M -= R
        elif C <= R:
            board[R-1,:] = 2
            R -= 1
            M -= C
    
    def cascades(board, r, c):
        rows = [i for i in (r-1, r, r+1) if (i >= 0 and i < board.shape[0])]
        cols = [i for i in (c-1, c, c+1) if (i >= 0 and i < board.shape[1])]
        for r in rows:
            for c in cols:
                if board[r,c] == 2: #Mine next to given position
                    return False
        return True
    
    #If we have no mines left, we win as long as the initial click cascades:
    if M == 0:
        board[board == -1] = 0
        if cascades(board, 0, 0):
            return write_board(board)
        else:
            return "\nImpossible"
    
    #Now we have a rectangular free space with less than a full row or column
    #to fill.
    
    #If there's so many mines that we fill in all but one square on either
    #the row or column, it can't be done.
    if M > (R + C - 5):
        return "\nImpossible"
        
    if M > 0 and (R <= 2 or C <= 2):
        return "\nImpossible"
        
    #Otherwise, we fill in mines from the corner opposite to the click
    #print M, R + C - 5
    fill_num = min(M, R - 2)
    #print M, fill_num
    board[(R - fill_num):,C-1] = 2
    M -= fill_num
    
    fill_num = min(M, C - 3)
    #print M, fill_num
    board[R-1,(C - fill_num - 1):] = 2
    M -= fill_num
    #assert M == 0
    
    board[board == -1] = 0
    return write_board(board)

###############################################################################
# Main execution path
###############################################################################

if __name__ == "__main__":
    #Do any pre-calculations required
    precalculate()
    
    #Open up the input & output files based on the provided input file
    assert len(sys.argv) == 2 #only one argument
    assert sys.argv[1][-3:] == ".in" #input must end with .in
    infile = open("%s" % sys.argv[1], 'r')
    outfile = open("%s.out" % sys.argv[1][:-3], 'w')
    
    #Read in the number of cases (the first input line) to iterate through
    cases = int(infile.readline().strip('\n'))
    for i in range(cases):
        
        #Read in the input data for this case
        case = read_input(infile)
        
        #Solve the problem for this case
        output = solve_case(case)
        
        #Write out the output of this case
        outfile.write('Case #%i: %s\n' % (i+1, output))
        print 'Case #%i: %s\n' % (i+1, output)
    
    #Close files
    infile.close()
    outfile.close()