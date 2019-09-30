import sys
import multiprocessing

class StreamReader:
	def __init__(_, stream):
		_.tokens = (token for token in stream.read().split())

	def cast(_, type):
		if isinstance(type, list):
			return [_.cast(subtype) for subtype in type]
		else:
			return type(_.tokens.next())

	def __call__(_, *types):
		return tuple( _.cast(type) for type in types )

def jam(reader, solver, threads=None):
	streamreader = StreamReader(sys.stdin)
	
	T, = streamreader(int)
	inputs = [reader(streamreader) for _ in xrange(T)]

	if threads:
		pool = multiprocessing.Pool(processes=threads)
		mapper = pool.map
	else:
		mapper = map

	applicator = lambda args: solver(*args)
	answers = mapper(applicator, inputs)
	
	for i, answer in enumerate(answers):
		print 'Case #%d:' % (i + 1), answer
