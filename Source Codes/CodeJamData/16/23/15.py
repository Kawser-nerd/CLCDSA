
_INFINITY_CAPACITY = float('Infinity')
_SUPERSOURCE = '_SUPERSOURCE'
_SUPERSINK = '_SUPERSINK'


# this algorithm is a one time run on each instance.
# after one execution a new instance of the graph should be created
# in order to run max_flow()

class Edge(object):
    def __init__(self, u, v, w):
        self.source = u
        self.sink = v
        self.capacity = w
        assert w >= 0

    def __repr__(self):
        return "%s->%s:%s" % (self.source, self.sink, self.capacity)


class FlowNetwork(object):
    def __init__(self):
        self.adj = {}
        self.flow = {}

    def add_vertex(self, vertex):
        self.adj[vertex] = []

    def get_edges(self, v):
        return self.adj[v]

    def add_edge(self, u, v, w=0):
        if u == v:
            raise ValueError("u == v")
        edge = Edge(u, v, w)
        redge = Edge(v, u, 0)
        edge.redge = redge
        redge.redge = edge
        self.adj[u].append(edge)
        self.adj[v].append(redge)
        self.flow[edge] = 0
        self.flow[redge] = 0

#    def find_path_recursive_dfs(self, source, sink, path=[]):
#        if source == sink:
#            return path
#        else:
#            for edge in self.get_edges(source):
#                residual = edge.capacity - self.flow[edge]
#                if residual > 0 and edge not in path:
#                    result = self.find_path_recursive_dfs( edge.sink, sink, path + [edge])
#                    if result != None:
#                        return result

    def find_path_bfs(self, source, sink):
        if source == sink:
            return []
        parent = {vertex:None for vertex in self.adj}
        parent[source] = source
        Q = [source]
        foundPath = False
        while Q and not foundPath:
            u = Q.pop(0)
            for edge in self.get_edges(u):
                residual = edge.capacity - self.flow[edge]
                v = edge.sink
                # If there is available capacity, and v is not seen before in search
                if residual > 0 and parent[v] == None:
                    parent[v] = edge
                    Q.append(v)
                    if v == sink:
                        foundPath = True
                        break

        if foundPath:
            path = []
            u = sink
            while u != source:
                edge = parent[u]
                path.append(edge)
                u = edge.source
            path.reverse()
            return path
        else:
            return None

    def find_path(self, source, sink):
        # choose the bfs method, so it runs in Edmonds-Karp time.
        # you can choose the 'simpler' find_path_recursive_dfs,
        # but it does not guarantee good running times
        return self.find_path_bfs(source, sink)

    def max_flow(self, source, sink):

        # handle multiple sources
        if type(source) == list:
            assert _SUPERSOURCE not in self.adj
            self.add_vertex(_SUPERSOURCE)
            for v in source:
                self.add_edge(_SUPERSOURCE, v, _INFINITY_CAPACITY)
            source = _SUPERSOURCE

        # handle multiple sinks
        if type(sink) == list:
            assert _SUPERSINK not in self.adj
            self.add_vertex(_SUPERSINK)
            for v in sink:
                self.add_edge(v, _SUPERSINK, _INFINITY_CAPACITY)
            sink = _SUPERSINK

        path = self.find_path(source, sink)
        while path != None:
            residuals = [edge.capacity - self.flow[edge] for edge in path]
            flow = min(residuals)
            for edge in path:
                self.flow[edge] += flow
                self.flow[edge.redge] -= flow
            path = self.find_path(source, sink)
        return sum(self.flow[edge] for edge in self.get_edges(source))



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

from collections import Counter

source_name = 'source_igfvfjsdv;clksaivhwes;fdhesfdhlahdwefgl'
target_name = 'target_igfvfjsdv;clksaivhwes;fdhesfdhlahdwefgl'
def solve_one_case(io_wrapper):
    # fill details here
    # reset_memoization()
    N = int(io_wrapper.readline())
    subject_list = []
    for i in range(N):
        subject = io_wrapper.readline().split()
        subject_list.append(subject)
    first_list = [x[0] for x in subject_list]
    second_list = [x[1] for x in subject_list]
    first_counters = Counter(first_list)
    second_counters = Counter(second_list)

    g = FlowNetwork()
    g.add_vertex(source_name)
    g.add_vertex(target_name)

    for v in first_counters:
        g.add_vertex(v + '_1')

    for v in second_counters:
        g.add_vertex(v + '_2')

    for f in first_counters:
        g.add_edge(source_name, f + '_1', first_counters[f]-1)

    for s in second_counters:
        g.add_edge(s + '_2', target_name, second_counters[s] - 1)
    for subject in subject_list:
        f, s = subject
        g.add_edge(f + '_1', s + '_2', 1)

    most_fakes = g.max_flow(source_name, target_name)

    io_wrapper.write('Case #' + str(io_wrapper.get_test_case()) + ': ' + str(most_fakes) + '\n')


main_run()
