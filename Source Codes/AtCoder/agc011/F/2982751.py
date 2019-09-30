import sys

def merge_delay_pattern(k, half1, half2):
    len1 = len(half1)
    len2 = len(half2)

    start, delay1_next = half1[0]
    start2 = half2[0][0]
    time1 = start - start2
    mid_start = start + time1 + delay1_next
    offset2_num_period = (mid_start - start2) // k
    offset2_phase = mid_start - offset2_num_period * k
    for head2 in range(len2):
        if half2[head2][0] >= offset2_phase:
            head2 -= 1
            break
    head2 += offset2_num_period * len2
    head1 = 0

    ret = []
    prev = ()
    half1.append((start + k, None))

    pos1_next = start
    pos2_next, delay2_next = half2[head2 % len2]
    pos2_next += (head2 // len2) * k
    mid = pos2_next
    while True:
        if mid <= pos2_next:
            if head1 == len1: break
            head1 += 1
            pos1, delay1 = pos1_next, delay1_next
            pos1_next, delay1_next = half1[head1]
        if pos2_next <= mid:
            head2 += 1
            pos2, delay2 = pos2_next, delay2_next
            pos2_next, delay2_next = half2[head2 % len2]
            pos2_next += (head2 // len2) * k
        if delay1 == 0:
            mid = pos1_next + time1
            if delay2 == 0:
                if prev is not None:
                    ret.append((start, 0))
                    prev = None
            else:
                delay = pos2 + delay2 - time1 - start
                if prev != start + delay:
                    ret.append((start, delay))
                    prev = start + delay
            if pos2_next <= mid:
                start = pos2_next - time1
            else:
                start = pos1_next
        else:
            mid = pos1 + time1 + delay1
            if mid <= pos2_next:
                if delay2 == 0:
                    delay = delay1
                else:
                    delay = pos2 + delay2 - time1 - start
                if prev != start + delay:
                    ret.append((start, delay))
                    prev = start + delay
                start = pos1_next
    return ret

def get_delay_pattern(k, data, first, last):
    if last - first == 1: return data[first]
    middle = (first + last) // 2
    half1 = get_delay_pattern(k, data, first, middle)
    half2 = get_delay_pattern(k, data, middle, last)
    return merge_delay_pattern(k, half1, half2)

def solve():
    data = []
    int_list = [int(s) for s in sys.stdin.read().split()]

    n = int_list[0]
    k = int_list[1]

    position = 0
    for i in range(2, (n + 1) * 2, 2):
        a = int_list[i]
        b = int_list[i + 1]
        if b == 1:
            a2 = a * 2
            if k < a2: return -1
            data.append([(-position, 0), (-position + k - a2, a2)])
        position += a

    if not data: return position * 2
    delay_pattern = get_delay_pattern(k, data, 0, len(data))
    pat_adj_pairs = zip(delay_pattern, delay_pattern[1:] + [(delay_pattern[0][0] + k, None)])
    delay_list = (pos + delay - next_pos for (pos, delay), (next_pos, _) in pat_adj_pairs if delay)
    return position * 2 + min(delay_list, default=0)


print(solve())