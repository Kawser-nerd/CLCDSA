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
    
    C, F, X = read_floats()
    
    case = (C, F, X)
    
    return case

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    C, F, X = case
    
    rate = 2.0
    cookies = 0.0
    time = 0.0
    
    #If it takes more cookies to buy a farm than we need to win, just wait and win:
    if C >= X:
        return X / rate
    
    while cookies < X:
        #If we don't have enough cookies to buy a farm, we have to wait until we do
        if cookies < C:
            wait_time = (C - cookies) / rate
            time += wait_time
            cookies = C
        #Now we do have enough cookies to buy a farm. Should we keep waiting or buy?
        time_if_wait = (X - C) / rate
        time_if_buy = X / (rate + F)
        if time_if_wait < time_if_buy:
            return time + time_if_wait
        else:
            rate += F
            cookies = 0.0

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