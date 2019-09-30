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
    
    N = read_int()
    naomi = read_floats()
    ken = read_floats()
    naomi.sort()
    ken.sort()
    assert len(naomi) == N
    assert len(ken) == N
    
    return naomi, ken

def ken_choice(told_naomi, ken, ken_free):
    #Ken's strategy is as follows:  if he has no block heavier than what Naomi
    #tells him, then he chooses his smallest block.  Otherwise, he chooses the smallest
    #block that is heavier than what she tells him.
    #N.B. ken should be provided as a sorted list from smallest to largest.
    N = len(ken)
    lowest = None
    for j in range(N):
        if not ken_free[j]:
            continue
        if lowest is None:
            lowest, idx = ken[j], j
        if ken[j] > told_naomi:
            return ken[j], j
    return lowest, idx

def normal_war(naomi, ken):
    #Naomi's strategy is to play blocks from largest to smallest,
    #Ken's strategy is to play the smallest block that could beat Naomi's,
    #or the smallest block if he has none that can do so.
    #Runs as N^2, fast enough even with N=1000
    
    #Appears to be validated as the best strategy, checked it with 
    #a complete exponential solution on the small import - no differences.
    N = len(naomi)
    ken_free = np.ones(N, dtype=bool)
    score = 0
    for i in range(N)[::-1]:
        chosen_naomi = naomi[i]
        chosen_ken, j = ken_choice(chosen_naomi, ken, ken_free)
        ken_free[j] = False
        
        if chosen_naomi > chosen_ken:
            score += 1
    return score


def new_deceitful_war(naomi, ken):
    score = 0
    
    N = len(naomi)
    
    for i in range(N):
        if naomi[-1] > ken[-1]:
            score += 1
            naomi = naomi[:-1]
            ken = ken[:-1]
        else:
            naomi = naomi[1:]
            ken = ken[:-1]
    return score


def deceitful_war(naomi, ken):
    #Naomi certainly can't win with blocks that are lower than all of Ken's
    #blocks.  But Naomi can lie about these blocks' weight to use up key blocks
    #of Ken's. 
    
    
    #, and will also lose against all of Ken's blocks that are larger
    #than all of her blocks.  So Naomi can lie using her lowest blocks to
    #use up Ken's highest blocks to remove these guaranteed losses.
    
    
    #Naomi's strategy is to use her no-hopers (those that are lower
    #than all of Ken's blocks) to fish out Ken's highest weight blocks.
    #Then she uses her lowest blocks to fish out any of Ken's best blocks
    #that will beat all of hers
    N = len(naomi)
    no_hopers = 0
    for i in range(N):
        if naomi[i] < ken[0]:
            no_hopers += 1
    #Some of Ken's blocks might be larger than all of hers
    def_losses = 0
    for i in range(N)[::-1]:
        if ken[i] > naomi[-1]:
            def_losses += 1
    
    #Then she goes through the rest and tries to win in order
    edge = max(no_hopers, def_losses)
    naomi = naomi[edge:]
    ken = ken[:N-edge]

    '''
    print "After removing sure losers:"
    print N, N-edge, edge
    if N - edge > 0:
        if min(naomi) < max(ken):
            print naomi
            print ken
    '''

    #print len(naomi), len(ken), edge

    score = 0
    for i in range(N - edge):
        if naomi[i] > ken[i]:
            score += 1
            
    return score

def solve_case(case):
    """Take the input data (structured in case) and perform any necessary
    calculations to obtain the desired output, formatted as the appropriate
    string.    
    """
    
    naomi, ken = case
    print naomi
    print ken
    
    new = new_deceitful_war(naomi, ken)
    
    good, bad = deceitful_war(naomi, ken), normal_war(naomi, ken)
    
    if not new == good:
        print 'Hey!', new, good
    
    output = "%i %i" % (new, bad)
    return output

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