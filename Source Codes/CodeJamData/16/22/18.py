from collections import OrderedDict
from functools import wraps, update_wrapper
import time
import os

###############################
#      useful decorators
###############################

__memoization_registry = []
_CALL_FUNC_COUNTERS = {}


# a decorator for memoizing function outputs
def memoize_it(inner_func):
    global __memoization_registry
    cache = {}
    __memoization_registry.append(cache)

    @wraps(inner_func)
    def wrapper(*args, **kwargs):
        if args not in cache:
            cache[args] = inner_func(*args, **kwargs)
        return cache[args]
    return wrapper


# clear all previous memoization. For use in the beginning of a new test-case
def reset_memoization():
    global __memoization_registry
    try:
        for cache_d in __memoization_registry:
            cache_d.clear()
    except NameError:
        pass


# a decorator to add time benchmarking for a function
def time_it(inner_func):
    @wraps(inner_func)
    def wrapper(*args, **kwargs):
        print('--> Start function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        start_time = time.time()
        res = inner_func(*args, **kwargs)
        end_time = time.time()
        print('--> End   function \'' + inner_func.__qualname__ + '\' : ', time.ctime())
        print('--> Elapsed time \'' + inner_func.__qualname__ + '\' : ', end_time-start_time)
        print()
        return res
    return wrapper


# a decorator for logging the function's inputs and outputs
def log_it(arguments=True, output=True):
    def decorating_function(user_function):
        def wrapper(*args, **kwargs):
            if arguments:
                print(time.ctime(), ': function \'' + user_function.__qualname__ + '\' arguments args=', args, 'kwargs=', kwargs)
            result = user_function(*args, **kwargs)
            if output:
                print(time.ctime(), ': function \'' + user_function.__qualname__ + '\' outputs ', result)
            return result
        return update_wrapper(wrapper, user_function)
    return decorating_function


# a decorator for counting the number of calls to the wrapped function
def count_it(inner_func):
    global _CALL_FUNC_COUNTERS
    assert type(_CALL_FUNC_COUNTERS) == dict
    assert inner_func.__qualname__ not in _CALL_FUNC_COUNTERS
    _CALL_FUNC_COUNTERS[inner_func.__qualname__] = 0

    @wraps(inner_func)
    def wrapper(*args, **kwargs):
        global _CALL_FUNC_COUNTERS
        _CALL_FUNC_COUNTERS[inner_func.__qualname__] += 1
        return inner_func(*args, **kwargs)
    return wrapper


# a decorator for pre-processing the function and automatically save the result
def pre_process_it(inner_func):
    import inspect
    import pickle
    a = inspect.getargspec(inner_func)
    if a.args or a.keywords or a.varargs or a.defaults:
        raise ValueError('A pre process function must not have arguments')

    @time_it
    @wraps(inner_func)
    def wrapper(*args, **kwargs):
        filename = 'pre-process_' + inner_func.__qualname__ + '.pickle'
        if filename not in os.listdir():
            print('--> Pre process started for function \'' + inner_func.__qualname__ + '\' ....')
            pre_process_data = inner_func()
            print('--> Pre process ended for function \'' + inner_func.__qualname__ + '\'')
            print('--> Pickling started for function \'' + inner_func.__qualname__ + '\' ....')
            with open(filename, 'wb') as f_pp:
                pickle.dump(pre_process_data, f_pp, pickle.HIGHEST_PROTOCOL)
            print('--> Pickling ended for function \'' + inner_func.__qualname__ + '\'')
        print('--> Unpickling pre-processed data of function \'' + inner_func.__qualname__ + '\' ...')
        with open(filename, 'rb') as f_pp:
            data = pickle.load(f_pp)
        print('--> Unpickling ended')
        print()
        return data

    return wrapper


###########################################
# automatic runner
###########################################

# a class to wrap automatically the IO files in one class
class GCJIOWrapper:

    def __init__(self, input_filename, parsed_filename, output_filename):
        self.__input_filename = input_filename
        self.__parsed_filename = parsed_filename
        self.__output_filename = output_filename
        self.__index_test_case = 0
        self.__input_file = None
        self.__parsed_file = None
        self.__output_file = None

    def __enter__(self):
        # open the IO files
        self.__input_file = open(self.__input_filename, 'r')
        self.__parsed_file = open(self.__parsed_filename, 'w')
        self.__output_file = open(self.__output_filename, 'w')

    def __exit__(self, type_e, value, tb):
        # close the IO files
        self.__input_file.close()
        self.__parsed_file.close()
        self.__output_file.close()

    def readline(self):
        # read one line from the input. write it as is to the parsed file
        l = self.__input_file.readline()
        self.__parsed_file.write(l)
        return l

    def new_test_case(self):
        # mark a new test case to the parsed file
        self.__index_test_case += 1
        self.__parsed_file.write('\n## _BigOnion Test case: ' + str(self.__index_test_case) + ' ##\n')

    def write(self, s):
        # write to the output file
        self.__output_file.write(s)

    def get_test_case(self):
        # return the index of the current test case
        return self.__index_test_case


# This is the automatic runner
@time_it
def main_run():

    # find the most current input file (.in) which is in the working directory
    print('Directory : ', os.getcwd())
    file_names = [x for x in os.listdir()]
    l1 = [(os.stat(x).st_mtime, x) for x in file_names if x.endswith('.in')]
    if not l1:
        raise ValueError('No input file found')
    chosen_prefix = sorted(l1)[-1][1][:-3]
    input_filename = chosen_prefix + '.in'
    print('Chosen Input : ', input_filename)

    # filename of the file into which to parse the input file
    parsed_filename = chosen_prefix + '.parsed.txt'

    # filename of the output file. It has the same prefix,
    # and it doesn't tread over the previous output file from previous attempts
    l2 = [x.split('.')[0] for x in file_names if x.endswith('.out') and x.startswith(chosen_prefix)]
    l2 = [int(x.split('-run')[-1]) for x in l2]
    output_file_index = ('000' + str(max([0] + l2) + 1))[-3:]
    output_filename = chosen_prefix + '-run' + output_file_index + '.out'
    print('Chosen Output : ', output_filename)
    print()

    # with open(input_filename) as f_in, open(output_filename, 'w') as f_out:
    #     solve(f_in,f_out)
    io_wrapper = GCJIOWrapper(input_filename, parsed_filename, output_filename)
    with io_wrapper:
        solve_all_cases(io_wrapper)

    # print the chosen files once again for easy checking of correctness
    print()
    print('Conclusion :')
    print('Directory : ', os.getcwd())
    print('Chosen Input : ', input_filename)
    print('Chosen Output : ', output_filename)


# the automatic solver. Handles the test case mechanism
@time_it
def solve_all_cases(io_wrapper):
    T = int(io_wrapper.readline())
    for test_case in range(1, T+1):
        io_wrapper.new_test_case()
        assert io_wrapper.get_test_case() == test_case
        solve_one_case(io_wrapper)


###########################################
# write code here
###########################################

UNDECIDED = 0
C_WINNING = 1
J_WINNING = 2

def solve_one_case(io_wrapper):
    # fill details here
    # reset_memoization()
    C, J = io_wrapper.readline().split()
    assert len(C) == len(J)

    c_res, j_res = get_best (C, J, UNDECIDED)

    io_wrapper.write ('Case #' + str(io_wrapper.get_test_case()) + ': ' + c_res +' '+ j_res + '\n')




@memoize_it
def get_best (C, J, winning):
    if len(C) == len(J) == 0:
        return '',''

    if winning == C_WINNING:
        c_res = C.replace('?','0')
        j_res = J.replace('?', '9')
        return c_res, j_res
    elif winning == J_WINNING:
        c_res = C.replace('?', '9')
        j_res = J.replace('?', '0')
        return c_res, j_res
    else:
        assert winning == UNDECIDED
        if C[0] != '?' and J[0] != '?':
            if C[0] > J[0]:
                c_tmp, j_tmp = get_best(C[1:], J[1:], C_WINNING)
            elif C[0] < J[0]:
                c_tmp, j_tmp = get_best(C[1:], J[1:], J_WINNING)
            else:
                c_tmp, j_tmp = get_best (C[1:], J[1:], UNDECIDED)
            return C[0] + c_tmp, J[0] + j_tmp

        elif C[0] == J[0] == '?':
            c1,j1 = get_best (C[1:], J[1:], UNDECIDED)
            c1 = '0' + c1
            j1 = '0' + j1
            diff1 = get_diff(c1,j1)

            c2,j2 = get_best (C[1:], J[1:], C_WINNING)
            c2 = '1' + c2
            j2 = '0' + j2
            diff2 = get_diff(c2,j2)

            c3, j3 = get_best(C[1:], J[1:], J_WINNING)
            c3 = '0' + c3
            j3 = '1' + j3
            diff3 = get_diff(c3,j3)

            best_diff = min(diff1, diff2, diff3)
            l = []
            if diff1 == best_diff:
                l.append((c1,j1))
            if diff2 == best_diff:
                l.append((c2, j2))
            if diff3 == best_diff:
                l.append((c3,j3))

            return min(l)

        elif C[0] == '?' and J[0] != '?':
            d = int(J[0])
            c1 = j1 = None
            if d > 0:
                c1, j1 = get_best (C[1:], J[1:], J_WINNING)
                c1 = str(d-1) + c1
                j1 = str(d) + j1
                diff1 = get_diff(c1,j1)
            else:
                diff1 = 2**100

            c2,j2 = get_best (C[1:], J[1:], UNDECIDED)
            c2 = str(d) + c2
            j2 = str(d) + j2
            diff2 = get_diff(c2,j2)

            c3 = j3 = None
            if d < 9:
                c3, j3 = get_best(C[1:], J[1:], C_WINNING)
                c3 = str(d + 1) + c3
                j3 = str(d) + j3
                diff3 = get_diff(c3, j3)
            else:
                diff3 = 2**100

            best_diff = min(diff1, diff2, diff3)
            l = []
            if diff1 == best_diff:
                l.append((c1, j1))
            if diff2 == best_diff:
                l.append((c2, j2))
            if diff3 == best_diff:
                l.append((c3, j3))

            return min(l)

        else:
            assert C[0] != '?' and J[0] == '?'
            d = int(C[0])
            c1 = j1 = None
            if d > 0:
                c1, j1 = get_best(C[1:], J[1:], C_WINNING)
                c1 = str(d) + c1
                j1 = str(d - 1) + j1
                diff1 = get_diff(c1, j1)
            else:
                diff1 = 2 ** 100

            c2, j2 = get_best(C[1:], J[1:], UNDECIDED)
            c2 = str(d) + c2
            j2 = str(d) + j2
            diff2 = get_diff(c2, j2)

            c3 = j3 = None
            if d < 9:
                c3, j3 = get_best(C[1:], J[1:], J_WINNING)
                c3 = str(d) + c3
                j3 = str(d + 1) + j3
                diff3 = get_diff(c3, j3)
            else:
                diff3 = 2 ** 100

            best_diff = min(diff1, diff2, diff3)
            l = []
            if diff1 == best_diff:
                l.append((c1, j1))
            if diff2 == best_diff:
                l.append((c2, j2))
            if diff3 == best_diff:
                l.append((c3, j3))

            return min(l)


def get_diff (c,j):
    return abs(int(c)-int(j))

main_run()
