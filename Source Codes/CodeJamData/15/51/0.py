from getopt          import getopt, GetoptError
from multiprocessing import Pool, Queue, Manager
from os              import getpid
from sys             import argv, stderr
from time            import strftime

class FileWrapper:
    def __init__(self, file):
        self.file = file
    
    def getInt(self):
        return int(self.file.readline())
    
    def getInts(self):
        return [int(z) for z in self.file.readline().split()]
    
    def getFloat(self):
        return float(self.file.readline())
    
    def getFloats(self):
        return [float(z) for z in self.file.readline().split()]
    
    def getWords(self):
        return self.file.readline().split()
    
    def readline(self):
        return self.file.readline().strip()
    
    def close(self):
        self.file.close

class GCJ:
    """
    Wrapper for a lot of functionality that is useful when trying to solve a 
    Google Code jam question.

    For the case of Problem A of the 2008 Qualification Round, example code
    would be:

    def parse(inFile):
        N = int(inFile.readline())
        searchEngines = [inFile.readline().strip() for z in xrange(N)]
        Q = int(inFile.readline())
        queries = [inFile.readline().strip() for z in xrange(Q)]
        return [searchEngines, queries]

    def solve([searchEngines, queries]):
        N = len(searchEngines)
        dict = {searchEngines[i]: i for i in xrange(N)}
        qs = [dict[k] for k in queries]
        used = [False] * N
        numberused = 0
        resets = 0
        for k in qs:
            if not used[k]:
               if numberused == N - 1:
                  resets += 1
                  numberused = 0
                  used = [False] * N
               used[k] = True
               numberused += 1
        return str(resets)

    if __name__ == "__main__":
        from GCJ import GCJ
        GCJ(parse, solve, "c:\\temp", "a").run()

    This would give a script with command line options -t, -s, -l, -r, -v, -m:
      -t (default)
        input file  = "c:\\temp\\a-test.in"
        output file = "c:\\temp\\a-test.out"
        error file  = "c:\\temp\\a-test.err"
        (the directory "c:\\temp" and the character "a" at the start of the
         filenames come from arguments to GCJ in the source code)
      -s <number>
        input file  = "c:\\temp\\a-small-attempt<number>.in"
        output file = "c:\\temp\\a-small-attempt<number>.out"
        error file  = "c:\\temp\\a-small-attempt<number>.err"
      -l
        input file  = "c:\\temp\\a-large.in"
        output file = "c:\\temp\\a-large.out"
        error file  = "c:\\temp\\a-large.err"
      -r (default)
        read the input file. Read the first line to get the number of cases N
        included in the input. Run parse(infile) N times to get N case objects,
        and then run solve(case object) on each of them. Output the strings
        returned from solve, prepended with "Case #<case #>: ". Put output in 
        output file, overwriting it if it exists.
      -v
        Do the same as above, but check if the contents of the output file now
        are as they would be otherwise. If it is, say "OK". Otherwise, output all
        differences, and write the output into the error file, overwriting it if
        it exists.
      -m <number>
        Set up a pool of <number> worker threads, and put all of the problems
        (along with their problem numbers) on a queue. Each thread, when finished
        with a problem, will take the next case from the queue.
"""

    def __init__(self, reader, solver, directory, question):
        self.reader = reader
        self.solver = solver
        self.question = question
        print >> stderr, "GCJ Wrapper initiated."
        print >> stderr, "Reading command line arguments"
        try:
            opts, args = getopt(argv[1:],
                                "vs:tlm:",
                                ["validate", "small", "test", "large", "multi"])
        except GetoptError, err:
            print str(err)
            exit(2)
        datatype = "test"
        self.job = "run"
        self.multi = 1
        for o,a in opts:
            if o in ("-s", "--small"):
                datatype = "small-attempt" + str(int(a))
            elif o in ("-l", "--large"):
                datatype = "large"
            elif o in ("-v", "--validate"):
                self.job = "validate"
            elif o in ("-m", "--multi"):
                self.multi = int(a)
        filepref = directory + "/" + question + "-" + datatype
        self.infile = filepref + ".in"
        self.outfile = filepref + ".out"
        self.errfile = filepref + ".err"
        if (self.job == "run"):
            print >> stderr, "Creating " + self.outfile + " from " + self.infile
        else:
            print >> stderr, "Testing that " + self.outfile + " would create " + self.infile
            print >> stderr, "Storing output in " + self.errfile + " otherwise"
    def run(self):
        data = self.read()
        if (self.multi == 1):
            answers = self.process(data)
        else:
            answers = self.multiprocess(data, self.multi)
        text = "".join(["Case #%d: %s\n" % (k + 1, answers[k]) for k in xrange(len(answers))])
        if False:
            print text
        self.output(text)
    def read(self):
        inh = FileWrapper(open(self.infile, 'r'))
        N = inh.getInt()
        data = [self.reader(inh) for k in xrange(N)]
        inh.close()
        return data
    def process(self, data):
        N = len(data)
        answers = [None] * N
        for k in xrange(N):
            print "%s:Working on Case %d" % (strftime("%X"), k + 1)
            answers[k] = self.solver(data[k])
            print "%s:Dealt with Case %d: %s" % (strftime("%X"), k + 1, answers[k])
        return answers
    def multiprocess(self, data, numprocs):
        N = len(data)
        manager = Manager()
        queue = manager.Queue()
        data = [[k + 1, data[k], self.solver, queue] for k in xrange(N)]
        pool = Pool(numprocs)
        pool.map_async(multiCase, data, 1)
        answers = [None] * N
        workerPids = []
        workingOn = []
        numTodo = N
        numDoing = 0
        numDone = 0
        for k in xrange(2 * N):
            report = queue.get()
            pid = report[0]
            if pid in workerPids:
                idx = workerPids.index(pid)
            else:
                idx = len(workerPids)
                workerPids += [pid]
                workingOn += [None]
            if report[1] == 0:
                workingOn[idx] = report[2]
                numTodo -= 1
                numDoing += 1
            else:
                workingOn[idx] = None
                answers[report[2] - 1] = report[3]
                numDoing -= 1
                numDone += 1
            print "%s:then %s now %s soon %s | %s" % (strftime("%X"), clean(numDone), clean(numDoing), 
                                                      clean(numTodo), " ".join([clean(z) for z in workingOn]))
        return answers
    def output(self, text):
        if self.job == "run":
            open(self.outfile, 'w').write(text)
        else:
            text2 = open(self.outfile, 'r').read()
            if (text.strip() == text2.strip()):
                print "OK"
            else:
                print "Not OK"
                open(self.errfile, 'w').write(text)
                print "new output written to %s" % self.errfile
                print "Differences:"
                text = text.strip().split("\n")
                text2 = text2.strip().split("\n")
                for k in xrange(min(len(text), len(text2))):
                    if text[k] != text2[k]:
                        print "Line %d: '%s' vs '%s'" % (k + 1, text[k], text2[k])
                if len(text) != len(text2):
                    print "Files have different number of lines: %d vs %d" % (len(text), len(text2))
    
    def clean(r):
        return "   " if (r == None) else ("%3d" % r)

    def multiCase(inputList):
        [caseNumber, case, solver, queue] = inputList
        queue.put([getpid(), 0, caseNumber])
        answer = solver(case)
        queue.put([getpid(), 1, caseNumber, answer])
