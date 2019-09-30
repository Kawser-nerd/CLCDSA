# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""2
2 4
3 5
""","""Case #1: 1
Case #2: 2
""")]


"""
Possible patterns:
222 (repeat for as many cols as exists)

221 (repeating when cols is multiple of 3)
221

222211 (repeating when cols is multiple of 6)
211222

2221 (repeating when cols is multiple of 4)
2121
2122

333 (repeat for as many cols as exists)
333

Combos:
Rows = 2
333
333

221 (cols multiple of 3)
221

211222 (cols multiple of 6)
222211

Rows = 3
222
333
333

333
333
222

2221 (cols multiple of 4)
2121
2122

Rows = 4
222 (any number cols)
333
333
222

221 (cols multiple of 3)
221
333
333

333 (cols multiple of 3)
333
221
221

333333
333333
211222 (cols multiple of 6)
222211

211222 (cols multiple of 6)
222211
333333
333333

Rows = 5
333
333
222
333
333

3333
3333
2221 (cols multiple of 4)
2121
2122

2221 (cols multiple of 4)
2121
2122
3333
3333

221 (cols multiple of 3)
221
333
333
222

222
333 (cols multiple of 3)
333
221
221

222222
333333
333333
211222 (cols multiple of 6)
222211

211222 (cols multiple of 6)
222211
333333
333333
222222

Rows = 6
333
333
222
333
333
222

222
333
333
222
333
333

2222
3333
3333
2221 (cols multiple of 4)
2121
2122

2221 (cols multiple of 4)
2121
2122
3333
3333
2222

333 (cols multiple of 3)
333
221
221
333
333

221 (cols multiple of 3)
221
333
333
221
221

221 cols multiple of 3
221
333
333
212
212

221 cols multiple of 3
221
333
333
122
122


333333
333333
211222 (cols multiple of 6)
222211
333333
333333

211222
222211
333333
333333
211222 (cols multiple of 6)
222211

211222 (cols multiple of 6)
222211
333333
333333
221122
122221

211222 (cols multiple of 6)
222211
333333
333333
222112
112222

211222
222211
333333
333333
112222 (cols multiple of 6)
222112

211222 (cols multiple of 6)
222211
333333
333333
112222
222112

211222 (cols multiple of 6)
222211
333333
333333
112222
222112

221221
221221
333333
333333
211222 (cols multiple of 6)
222211

211222 (cols multiple of 6)
222211
333333
333333
221221
221221

212212
212212
333333
333333
211222 (cols multiple of 6)
222211

211222 (cols multiple of 6)
222211
333333
333333
212212
212212

122122
122122
333333
333333
211222 (cols multiple of 6)
222211

211222 (cols multiple of 6)
222211
333333
333333
122122
122122
"""

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        parts = input_reader.readline().strip().split()
        input_values['rows'] = int(parts[0])
        input_values['cols'] = int(parts[1])
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    rows = kwargs['rows']
    cols = kwargs['cols']
    if rows == 2:
        answer = 1
        if cols % 3 == 0:
            answer += 1
        if cols % 6 == 0:
            answer += 1
    elif rows == 3:
        answer = 2
        if cols % 4 == 0:
            answer += 1
    elif rows == 4:
        answer = 1
        if cols % 3 == 0:
            answer += 2
        if cols % 6 == 0:
            answer += 2
    elif rows == 5:
        answer = 1
        if cols % 3 == 0:
            answer += 2
        if cols % 4 == 0:
            answer += 2
        if cols % 6 == 0:
            answer += 2
    elif rows == 6:
        answer = 2
        if cols % 3 == 0:
            answer += 4
        if cols % 4 == 0:
            answer += 2
        if cols % 6 == 0:
            answer += 13
    print >>output_writer, "Case #%d: %s" % (case, answer)

def solve_inputs(input_reader, output_writer):
    """
    Loop through each problem input in input reader and solve it.

    Outputs responses to output_writer.
    """
    for input_values in parse_input(input_reader):
        solve_problem(output_writer=output_writer, **input_values)

def run_tests():
    idx = 0
    all_pass = True
    for problem_input, expected_output in TEST_CASES:
        idx += 1
        input_reader = StringIO(problem_input)
        output_writer = StringIO()
        solve_inputs(input_reader, output_writer)
        problem_output = output_writer.getvalue()
        if problem_output == expected_output:
            print "Test %d: Success" % idx
        else:
            all_pass = False
            print "Test %d: Failure" % idx
            print problem_output
        input_reader.close()
        output_writer.close()
    if all_pass:
        print "All tests were successful!"
    else:
        print "Something didn't match - try again."

def main():
    parser = OptionParser()
    parser.add_option("-f", "--file",
                      dest="filename_stem",
                      help="read input from FILE.in and write to FILE.out",
                      metavar="FILE")

    (options, args) = parser.parse_args()
    if options.filename_stem:
        print "Running in file mode."
        input_reader = open("%s.in" % options.filename_stem, "r")
        output_writer = open("%s.out" % options.filename_stem, "w")
        solve_inputs(input_reader, output_writer)
    else:
        print "Running in test mode."
        run_tests()

if __name__ == "__main__":
    main()