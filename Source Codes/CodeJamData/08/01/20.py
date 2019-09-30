from sys import stdin as input_file
from sys import stdout as output_file

def readline(file):
    return file.readline().rstrip('\n')

num_cases = int(readline(input_file))
for case_num in xrange(num_cases):
    num_engines = int(readline(input_file))
    engines = []
    for i in xrange(num_engines):
        engine = readline(input_file)
        engines.append(engine)
    num_queries = int(readline(input_file))
    queries = []
    for i in xrange(num_queries):
        query = readline(input_file)
        queries.append(query)
    num_switches = 0
    occurrence = set()
    for query in queries:
        occurrence.add(query)
        if len(occurrence) == num_engines:
            occurrence = set()
            occurrence.add(query)
            num_switches += 1
    output_file.write('Case #%d: %d\n' % (case_num + 1, num_switches))
