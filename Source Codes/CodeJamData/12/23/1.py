import itertools

class DistinctSubsets(object):

    def __init__(self, distinct_numbers):
        self.distinct_numbers = distinct_numbers
        self.sum_dict = dict()

    def get_answer(self):
        for i in range(len(self.distinct_numbers)):
            for subset in itertools.combinations(self.distinct_numbers, i):
                subset_sum = hash(sum(subset))
                if subset_sum in self.sum_dict:
                    return '\n{0}\n{1}'.format(' '.join([str(s) for s in subset]), self.sum_dict.get(subset_sum))
                else:
                    self.sum_dict[subset_sum] = ' '.join([str(s) for s in subset])
        return 'Impossible'


input_file = '/tmp/03_large.in'
output_file = '/tmp/03_large.out'

class InputReader(object):

    def __init__(self, input_file, output_file):
        self.input = input_file
        self.input_buffer = []

        self.output = output_file
        self.output_buffer = []

    def run(self):
        self.initialize()
        self.generate_answer()
        self.write_output()

    def initialize(self):
        with open(self.input, 'r') as f:
            for line in f:
                self.input_buffer.append(line)

    def generate_answer(self):
        self.case_count = int(self.input_buffer[0])
        for line in self.input_buffer[1:]:
            input_numbers = line.split(' ')
            numbers = int(input_numbers[0])
            distinct_numbers = [int(x) for x in input_numbers[1:]]

            assert len(distinct_numbers) == numbers
            assert len(set(distinct_numbers)) == numbers

            subsets = DistinctSubsets(distinct_numbers)
            self.output_buffer.append(subsets.get_answer())

    def write_output(self):
        with open(self.output, 'w') as f:
            index = 1
            for line in self.output_buffer:
                x = 'Case #{0}:{1}\n'.format(index, line)
                f.write(x)
                index += 1

reader = InputReader(input_file, output_file)
reader.run()