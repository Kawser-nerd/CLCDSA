'''
Google Code Jam utility module.

Copyright by Jeroen van Wolffelaar <jeroen@wolffelaar.nl>, 2015
GCJ username 'jeroenvw'

Pick any license you want: Public domain / WTFPL / MIT / 3-clause BSD / PSFL


Makes it easy to run under various modes, like adhoc something, regular mode,
various verbosity options. Compares output to expected, shows time taken, can
enable the python profiler, can show in/out.

print statement will not end up in actual output, you must use out(), outp(),
or return the result from case().

Usage:

- Run with one argument, the single .in file in the currect directory matching
  the argument will be picked.

- Omit the mask, and the script will pick the most recently modified .in file.

- Run with the first argument being a global in the solution, and that
  function will be called with the remaining arguments passed through.

  If you specify 'case', you can thus run a single case.

'''

import sys, os, subprocess, time, ctypes, optparse, collections
from pprint import pprint

import __main__

def line():
    L = sys.stdin.readline()
    if not L:
        raise Exception("End of file")
    if VERBOSE:
        print 'INPUT:', L,
    return L.strip()
def ints():
    return map(int, line().split())

def outp(s): # p for partial (= no newline)
    outp.used = True
    OUT.write(s)
def out(s):
    outp(str(s)+'\n')

def vprint(s):
    if VERBOSE: print s

def profile(func, *a, **kw):
    if OPTS.profile:
        import cProfile, pstats
        P = cProfile.Profile()
        P.enable()

    try:
        return func(*a, **kw)
    finally:
        if OPTS.profile:
            print '='*80
            P.disable()
            P.print_stats('cumulative')
            print '='*80

def processInput():
    outwriters = nones = 0

    N = int(line())
    for i in range(N):
        if VERBOSE:
            print '='*80
            print 'Case %d' % (i+1)
            print
        else:
            print 'Processing case %d...' % (i+1)

        if haslib():
            LIB.reset()

        outp('Case #%d: ' % (i+1))
        outp.used = False
        res = __main__.case()
        if outp.used:
            outwriters += 1
            # If not-none is returned, assume it is a final line
            if res is not None:
                out(res)
        else:
            if res is None:
                nones += 1
            out(res)

        if VERBOSE:
            print "ANSWER:", res
            print

    if sys.stdin.readline():
        print >>sys.stderr, 'WARNING: not all input consumed!'

    if nones:
        print >>sys.stderr, 'WARNING: %d cases returned None' % nones
    if outwriters and outwriters != N:
        print >>sys.stderr, 'WARNING: Some, but not all, cases produced output'

def compileInfo():
    base, _, _ = os.path.basename(sys.argv[0]).partition('.')
    cpp = '%s.cpp' % base
    if os.path.exists(cpp):
        if DEBUG: target = 'libdbg.so'
        else:     target = 'lib.so'
        return cpp, target
    else:
        return None, None

def haslib():
    cpp, target = compileInfo()
    return cpp is not None

def loadlib():
    if not haslib(): return

    global LIB
    cpp, target = compileInfo()
    LIB = __main__.LIB = ctypes.CDLL('./' + target)
    if hasattr(__main__, 'initlib'):
        __main__.initlib()
    LIB.reset()

def compileIfNeeded():
    if not haslib(): return
    cpp, target = compileInfo()

    if os.path.exists(target) and os.path.getmtime(cpp) < os.path.getmtime(target):
        print >>sys.stderr, '%s is uptodate' % target
        return

    print >>sys.stderr, 'Compiling %s into %s...' % (cpp, target)
    if DEBUG:
        opts = '-g'
    else:
        opts = '-g -O3'
    subprocess.check_call('g++ -Wall %s -fPIC -std=c++0x %s -shared -o %s'
            % (opts, cpp, target), shell=True)

def main():
    parser = optparse.OptionParser()
    parser.add_option('--run', action='store_true')
    parser.add_option('--outfd')
    parser.add_option('-v', '--verbose', action='store_true')
    parser.add_option('-d', '--debug', action='store_true')
    parser.add_option('-q', '--quiet', action='store_true') # suppress stdout
    parser.add_option('-p', '--profile', action='store_true')
    for flag in __main__.FLAGS.split():
        parser.add_option('--'+flag, action='store_true')
    opts, args = parser.parse_args()

    if opts.outfd is not None:
        out = os.fdopen(int(opts.outfd), 'w')
    else:
        out = sys.stdout

    global OUT, OPTS, VERBOSE, DEBUG
    __main__.OUT     = OUT     = out
    __main__.OPTS    = OPTS    = opts
    __main__.VERBOSE = VERBOSE = opts.verbose
    __main__.DEBUG   = DEBUG   = opts.debug

    if opts.run:
        loadlib()
        return profile(processInput)

    compileIfNeeded()

    if args:
        cmd = args[0]
        if hasattr(__main__, cmd):
            loadlib()
            res = getattr(__main__, cmd)(*args[1:])
            pprint(res)
            return

    if args:
        mask, = args
        mastermain(mask)
    else:
        mastermain()

def mastermain(mask=None):
    files = [f for f in os.listdir('.') if f.endswith('.in')]
    if not files:
        raise Exception("No .in file found")

    if mask is None:
        fn = max(files, key=os.path.getmtime)
    else:
        matches = [f for f in files if mask in f]
        if not matches:
            raise Exception("No .in file matched %r" % mask)
        if len(matches) > 1:
            raise Exception("Too many .in file matched %r: [%s]"
                    % (mask, ', '.join(matches)))
        fn, = matches

    print "Processing input from %r..." % fn

    root = fn[:-2]
    infn   = root+'in'
    tmpfn  = root+'tmp'
    outfn  = root+'out'
    goodfn = root+'good'
    assert infn == fn

    with open(infn) as fdin:
        with open(tmpfn, 'wb') as fdout:
            start = time.time()
            kw = {}
            if OPTS.quiet:
                kw.update(stdout=open('/dev/null', 'w'))
            rc = subprocess.call(sys.argv +
                [ '--run', '--outfd=%d' % fdout.fileno()],
                    stdin=fdin, **kw)
            tottime = time.time()-start

    print 'Done in %.3fs' % tottime
    if rc:
        print "WITH EXITCODE %d" % rc
        return

    os.rename(tmpfn, outfn)
    if os.path.exists(goodfn):
        subprocess.call(['diff', '-sdu', goodfn, outfn])
    else:
        print '>>> %s' % outfn
        with open(outfn, 'r') as fd:
            sys.stdout.write(fd.read())
        print '<<< %s' % outfn

    print 'Done in %.3fs' % tottime
