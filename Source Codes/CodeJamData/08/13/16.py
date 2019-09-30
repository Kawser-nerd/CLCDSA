import sys
import psyco
psyco.full()

class EOF(Exception): 
    pass


class CodeJam(object):

    def __init__(self, file=None, debug=False):
        if not file:
            if len(sys.argv) > 1:
                file = sys.argv[1]
            else:
                raise ValueError('You MUST specify one input file')

        self._debug = debug
        self._file = open(file)
        self._outfile = open("%s.out" % file, 'w')

        self._current_case = -1
        self.pos = 0
    
    def get_lines(self, count=1):
        try:
            value = [self._file.next()[:-1] for i in xrange(count)]
            self.debug("Getting %d line(s)" % count)
        except StopIteration:
            raise EOF('End of file')

        self.pos += 1
        return value

    def get_int(self):
        try:
            value = int(self._file.next())
        except StopIteration:
            raise EOF('End of file')
        except ValueError:
            raise ValueError('This line is not a number')

        self.pos += 1

        self.debug("Getting int: %d" % value)
        return value

    def write_case(self, text, tpl='Case #%d: %s\n'):
        assert self._current_case > -1, \
            'You must iterate cases before solve those'
        text = tpl % (self._current_case + 1, text)
        self._outfile.write(text)
        self.debug("Writing %s into output file" % repr(text))

    def debug(self, text):
        if self._debug:
            print text

    def get_cases(self):
        for self._current_case in xrange(self.get_int()):
            yield self._current_case
        
    cases = property(get_cases)

    def __del__(self):
        # Close files only if there was opened.

        if hasattr(self, '_file'):
            self._outfile.close()
            self._file.close()
