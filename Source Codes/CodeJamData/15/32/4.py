from functools import wraps, update_wrapper
import time
import os

###############################
##      useful decorators
###############################

# a decorator for memoizing function outputs
def memoize_it(inner_func):
    global __memoization_registry
    try:
        __memoization_registry
    except NameError:
        __memoization_registry = []
    cache = {}
    __memoization_registry.append(cache)
    @wraps(inner_func)
    def wrapper(*args, **kwds):
        if args not in cache:
            cache[args] = inner_func(*args, **kwds)
        return cache[args]
    return wrapper

# clear all previous memoization. For use in the beginning of a new test-case
def reset_memoization ():
    global __memoization_registry
    try:
        for cache_d in __memoization_registry:
            cache_d.clear()
    except NameError:
        pass
        
# a decorator to add time benchmarking for a function
def time_it(inner_func):
    @wraps(inner_func)
    def wrapper(*args, **kwds):
        print ('--> Start function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        starttime = time.time()
        res = inner_func(*args, **kwds)
        endtime = time.time()
        print ('--> End   function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        print ('--> Elapsed time \'' + inner_func.__qualname__ + '\' : ', endtime-starttime)
        print()
        return res
    return wrapper


# a decorator for logging the function's inputs and outputs
def log_it (arguments=True, output=True):
    def decorating_function(user_function):
        def wrapper(*args, **kwds):
            if arguments:
                print (time.ctime(), ': function \'' + user_function.__qualname__ + '\' arguments args=', args, 'kwds=', kwds)
            result = user_function(*args, **kwds)
            if output:
                print (time.ctime(), ': function \'' + user_function.__qualname__ + '\' outputs ', result)
            return result
        return update_wrapper(wrapper, user_function)
    return decorating_function

        
# a decorator for counting the number of calls to the wrapped function
def count_it (inner_func):
    global _CALL_FUNC_COUNTERS
    if '_CALL_FUNC_COUNTERS' not in globals():
        _CALL_FUNC_COUNTERS = {}
    assert type(_CALL_FUNC_COUNTERS) == dict
    assert inner_func.__qualname__ not in _CALL_FUNC_COUNTERS
    _CALL_FUNC_COUNTERS[inner_func.__qualname__] = 0
    @wraps(inner_func)
    def wrapper(*args, **kwds):
        global _CALL_FUNC_COUNTERS
        _CALL_FUNC_COUNTERS[inner_func.__qualname__] += 1
        return inner_func(*args, **kwds)
    return wrapper

# a decorator for pre-processing the function and automatically save the result
def pre_process_it (inner_func): 
    import inspect
    import pickle
    a = inspect.getargspec(inner_func)
    if a.args or a.keywords or a.varargs or a.defaults:
        raise ValueError ('A pre process function must not have arguments')        
    
    @time_it
    @wraps(inner_func)
    def wrapper (*args, **kwds):
        filename = 'preprocess_' + inner_func.__qualname__ + '.pickle'
        if not filename in os.listdir():
            print ('--> Pre process started for function \'' + inner_func.__qualname__ + '\' ....')
            preProcessData = inner_func()
            print ('--> Pre process ended for function \'' + inner_func.__qualname__ + '\'')
            print ('--> Pickling started for function \'' + inner_func.__qualname__ + '\' ....')
            with open(filename, 'wb') as f_pp:
                pickle.dump(preProcessData, f_pp, pickle.HIGHEST_PROTOCOL)
            print ('--> Pickling ended for function \'' + inner_func.__qualname__ + '\'')
        print ('--> Unpickling pre-processed data of function \'' + inner_func.__qualname__ + '\' ...')
        with open(filename, 'rb') as f_pp:
            data = pickle.load(f_pp)
        print ('--> Unpickling ended')
        print()
        return data

    return wrapper
 

###########################################
# automatic runner
###########################################

# a class to wrap automatically the IO files in one class
class GCJIOWrapper:
    
    def __init__ (self, inputfilename, parsedfilename, outputfilename):
        self.__inputfilename = inputfilename
        self.__parsedfilename = parsedfilename
        self.__outputfilename = outputfilename
        self.__indextestcase = 0
    
    def __enter__ (self):
        # open the IO files
        self.__inputfile = open (self.__inputfilename, 'r')
        self.__parsedfile = open (self.__parsedfilename, 'w')
        self.__outputfile = open (self.__outputfilename, 'w')
    
    def __exit__ (self, typeE, value, tb):
        # close the IO files
        self.__inputfile.close()
        self.__parsedfile.close()
        self.__outputfile.close()
    
    def readline (self):
        # read one line from the input. write it as is to the parsed file
        l = self.__inputfile.readline()
        self.__parsedfile.write(l)
        return l
    
    def newTestcase (self):
        # mark a new testcase to the parsed file
        self.__indextestcase += 1
        self.__parsedfile.write('\n## _BigOnion Testcase: ' + str(self.__indextestcase) + ' ##\n')
    
    def write (self, s):
        # write to the output file
        self.__outputfile.write(s)
    
    def getTestcase (self):
        # return the index of the current testcase
        return self.__indextestcase
        

# This is the automatic runner    
@time_it
def main_run():
        
    # find the most current input file (.in) which is in the working directory 
    print ('Directory : ', os.getcwd())
    filenames = [x for x in os.listdir ()]
    l1 = [(os.stat(x).st_mtime, x) for x in filenames if x.endswith('.in')]
    if not l1:
        raise ValueError('No input file found')
    chosen_prefix =  sorted(l1)[-1][1][:-3]
    input_filename = chosen_prefix+'.in'
    print ('Chosen Input : ',input_filename)
    
    # filename of the file into which to parse the input file
    parsed_filename = chosen_prefix+'.parsed.txt'

    # filename of the output file. It has the same prefix, 
    # and it doesn't tread over the previous output file from previous attempts
    l2 = [x.split('.')[0] for x in filenames if x.endswith('.out') and x.startswith(chosen_prefix)]
    l2 = [int(x.split('-run')[-1]) for x in l2]
    output_file_index = ('000' + str(max([0] + l2) + 1))[-3:]
    output_filename = chosen_prefix + '-run' + output_file_index + '.out'
    print ('Chosen Output : ',output_filename)
    print()
    
    #with open(input_filename) as f_in, open(output_filename, 'w') as f_out:
    #    solve(f_in,f_out)
    ioWrapper = GCJIOWrapper(input_filename, parsed_filename, output_filename)
    with ioWrapper:
        solveAllCases(ioWrapper)

    # print the chosen files once again for easy checking of correctness
    print ()
    print ('Conclusion :')
    print ('Directory : ', os.getcwd())
    print ('Chosen Input : ',input_filename)
    print ('Chosen Output : ',output_filename)


# the automatic solver. Handles the testcase mechanism
@time_it
def solveAllCases (ioWrapper):
    T = int(ioWrapper.readline())
    for testcase in range(1, T+1):
        ioWrapper.newTestcase()
        assert ioWrapper.getTestcase() == testcase
        solveOneCase (ioWrapper)



###########################################
# write code here
###########################################

from fractions import Fraction

def solveOneCase (ioWrapper):
    # fill details here
    #reset_memoization()
    K, L, S = [int(x) for x in ioWrapper.readline().split()]
    keyboard = ioWrapper.readline().replace('\n','')
    assert len(keyboard) == K
    target_str = ioWrapper.readline().replace('\n','')
    assert len(target_str) == L
    
    prob = 1
    for c in target_str:
        prob = prob * Fraction(keyboard.count(c), K)
    if prob == 0 or prob == 1 or S < L:
        ioWrapper.write('Case #' + str(ioWrapper.getTestcase()) + ': 0.0\n')
        return
    
    exp = prob * (S-(L-1))
    
    start_again = L
    for i in range(1,L):
        if target_str.startswith(target_str[-i:]):
            start_again = L-i

    cnt_max = 0
    i = 0
    while i + L <= S:
        cnt_max += 1
        i += start_again
    
    
    ioWrapper.write('Case #' + str(ioWrapper.getTestcase()) + ': ' + str(float(cnt_max - exp)) + '\n')





main_run()
