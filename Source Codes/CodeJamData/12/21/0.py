class Audience(object):

    def __init__(self, point_list):
        self.x = float(sum(point_list))
        self.point_list = point_list

    def get_answer(self):
        return ' '.join([str(self.get_fraction(c, c) * 100) for c in self.point_list])

    def get_fraction(self, c, d):
        filt_list = filter(lambda y: y <= d, self.point_list)
        conv_filt_list = filter(lambda y: y > d, self.point_list)
        s = (sum(filt_list) + self.x) / len(filt_list)
        answ = max(0, (s - c) / self.x)
        if conv_filt_list and answ * self.x + c > min(conv_filt_list):
            return self.get_fraction(c, min(conv_filt_list))
        else:
            return answ


input_file = '/tmp/01_large.in'
output_file = '/tmp/01_large.out'

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
            n_contestants = int(input_numbers[0])
            contestant_points = [int(x) for x in input_numbers[1:]]

            assert len(contestant_points) == n_contestants

            audience = Audience(contestant_points)
            self.output_buffer.append(audience.get_answer())

    def write_output(self):
        with open(self.output, 'w') as f:
            index = 1
            for line in self.output_buffer:
                x = 'Case #{0}: {1}\n'.format(index, line)
                f.write(x)
                index += 1

reader = InputReader(input_file, output_file)
reader.run()