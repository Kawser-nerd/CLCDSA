class ImpossibleException(Exception):
    pass

def count_ones(devices):
    return sum(int(device[0]) for device in devices)

def filter(devices):
    """
    >>> filter(['00', '01', '11'])
    (['1'], ['0', '1'])
    """
    one_devices = [d[1:] for d in devices if d[0] == '1']
    zero_devices = [d[1:] for d in devices if d[0] != '1']
    return one_devices, zero_devices

def chargeable(outlet_groups, device_groups, L):
    """Given a list of OUTLET_GROUPS and DEVICE_GROUPS
    such that each group must be paired with its partner
    group, determine the minimum number of switch flips
    needed to match the groups.

    Return 1000 if impossible.
    """
    outlet_groups = [g for g in outlet_groups if len(g) > 0]
    device_groups = [g for g in device_groups if len(g) > 0]
    if L == 0:
        return 0

    #Try not flipping.
    min_flips = 1000
    try:
        new_outlet_groups, new_device_groups = [], []
        for i in range(len(outlet_groups)):
            o_group, d_group = outlet_groups[i], device_groups[i]
            sub_o, sub_d = noflip_groups(o_group, d_group)
            new_outlet_groups += sub_o
            new_device_groups += sub_d
        #print outlet_groups, device_groups
        #print new_outlet_groups, new_device_groups
        min_flips = chargeable(new_outlet_groups, new_device_groups, L - 1)
    except ImpossibleException as e:
        pass

    try:
        new_outlet_groups, new_device_groups = [], []
        for i in range(len(outlet_groups)):
            o_group, d_group = outlet_groups[i], device_groups[i]
            sub_o, sub_d = flip_groups(o_group, d_group)
            new_outlet_groups += sub_o
            new_device_groups += sub_d
        min_flips = min(min_flips, 1 + chargeable(new_outlet_groups, new_device_groups, L - 1))
    except ImpossibleException as e:
        pass

    return min_flips

def noflip_groups(outlets, devices):
    """Given that OUTLETS must be matched with DEVICES
    with no flips, return the resulting subgroups.
    >>> noflip_groups(['01', '11', '10'], ['11', '00', '10'])
    """
    N = len(outlets)
    out_ones = count_ones(outlets)
    dev_ones = count_ones(devices)
    if out_ones != dev_ones:
        raise ImpossibleException('Impossible')

    one_devices, zero_devices = filter(devices)
    one_outlets, zero_outlets = filter(outlets)
    return [zero_outlets, one_outlets], [zero_devices, one_devices]

def flip_groups(outlets, devices):
    """Given that OUTLETS must be matched with DEVICES
    with one flip, return the resulting subgroups.
    """
    N = len(outlets)
    out_ones = count_ones(outlets)
    dev_ones = count_ones(devices)
    if out_ones != N - dev_ones:
        raise ImpossibleException('Impossible')

    one_devices, zero_devices = filter(devices)
    one_outlets, zero_outlets = filter(outlets)
    return [one_outlets, zero_outlets], [zero_devices, one_devices]

def nice_chargeable(outlets, devices, L):
    ans = chargeable([outlets], [devices], L)
    if ans == 1000:
        return 'NOT POSSIBLE'
    else:
        return ans

def main():
    output = ''
    with open('test.in') as f:
        cases = int(f.readline()[:-1])
        for case in range(cases):
            line = f.readline()[:-1]
            N, L = [int(c) for c in line.split()]
            outlets = (f.readline()[:-1]).split()
            devices = (f.readline()[:-1]).split()
            ans = nice_chargeable(outlets, devices, L)

            output += 'Case #%s: %s\n' % (case + 1, ans)

    with open('test.out', 'w') as f:
        f.write(output)

#print chargeable([['01', '11', '10']], [['11', '00', '10']])
#print nice_chargeable(['01', '11', '10'], ['11', '00', '10'])
main()