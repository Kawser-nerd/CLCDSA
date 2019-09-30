import argparse

def solve():
    pass

def main(f_in, f_out):

    num_cases = int(f_in.readline().strip())
    for case in range(1, num_cases+1):
        ac, aj = f_in.readline().strip().split()
        ac = int(ac)
        aj = int(aj)

        activities = []
        for i in range(ac):
            c, d = f_in.readline().strip().split()
            c = int(c)
            d = int(d)

            activities += [("C", c, d)]

        for i in range(aj):
            c, d = f_in.readline().strip().split()
            c = int(c)
            d = int(d)

            activities += [("J", c, d)]

        s_activities = sorted(activities, key=lambda a: a[1])

        buffer_time = 0
        mandatory_j_baby_time = 0
        mandatory_c_baby_time = 0
        mandatory_swaps = 0
        j_default_baby_periods = []
        c_default_baby_periods = []

        # print "s_activities", s_activities

        f_a = s_activities.pop(0)

        last_activity_person = f_a[0]
        last_activity_end = f_a[2]
        if f_a[0] == "C":
            mandatory_j_baby_time += f_a[2] - f_a[1]
        elif f_a[0] == "J":
            mandatory_c_baby_time += f_a[2] - f_a[1]

        # print "after first"
        # print "buffer: {}\tman_j: {}\tman_c: {}\tswaps: {}\tdef_j: {}\tdef_c: {}".format(
        #     buffer_time, mandatory_j_baby_time, mandatory_c_baby_time, mandatory_swaps, j_default_baby_periods, c_default_baby_periods
        # )

        for a in s_activities:
            if a[0] == "C":
                mandatory_j_baby_time += a[2] - a[1]
                time_since_last = a[1] - last_activity_end
                if last_activity_person == "C":
                    j_default_baby_periods += [time_since_last]
                else:
                    mandatory_swaps += 1
                    buffer_time += time_since_last
            elif a[0] == "J":
                mandatory_c_baby_time += a[2] - a[1]
                time_since_last = a[1] - last_activity_end
                if last_activity_person == "J":
                    c_default_baby_periods += [time_since_last]
                else:
                    mandatory_swaps += 1
                    buffer_time += time_since_last
            last_activity_person = a[0]
            last_activity_end = a[2]
            # print "after", a
            # print "buffer: {}\tman_j: {}\tman_c: {}\tswaps: {}\tdef_j: {}\tdef_c: {}".format(
            #     buffer_time, mandatory_j_baby_time, mandatory_c_baby_time,
            #     mandatory_swaps, j_default_baby_periods, c_default_baby_periods
            # )

        time_from_last_to_first = (f_a[1] + 24 * 60) - last_activity_end
        if last_activity_person == "C":
            if f_a[0] == "C":
                j_default_baby_periods += [time_from_last_to_first]
            else:
                mandatory_swaps += 1
                buffer_time += time_from_last_to_first
        else:
            if f_a[0] == "J":
                c_default_baby_periods += [time_from_last_to_first]
            else:
                mandatory_swaps += 1
                buffer_time += time_from_last_to_first

        # print "after final"
        # print "buffer: {}\tman_j: {}\tman_c: {}\tswaps: {}\tdef_j: {}\tdef_c: {}".format(
        #     buffer_time, mandatory_j_baby_time, mandatory_c_baby_time,
        #     mandatory_swaps, j_default_baby_periods, c_default_baby_periods
        # )

        swaps = mandatory_swaps

        j_default_baby_periods = sorted(j_default_baby_periods, reverse=True)
        c_default_baby_periods = sorted(c_default_baby_periods, reverse=True)
        while True:
            c_time = mandatory_c_baby_time + buffer_time + sum(c_default_baby_periods)
            j_time = mandatory_j_baby_time + buffer_time + sum(j_default_baby_periods)
            if c_time >= 720 and j_time >= 720:
                break

            if c_time < 720:
                # convert one default j time to buffer time
                buffer_time += j_default_baby_periods.pop(0)
            else:
                buffer_time += c_default_baby_periods.pop(0)
            swaps += 2

        f_out.write('Case #{}: {}\n'.format(case, swaps))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('infile')

    opts = parser.parse_args()
    infile = opts.infile
    outfile = infile.split('.')[0]+'.out'
    print "Solving! in: {} -> out: {}".format(infile, outfile)

    with open(infile, 'r') as f_in:
        with open(outfile, 'w') as f_out:
            main(f_in, f_out)
