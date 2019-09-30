if __name__ == '__main__':
    hidden_key = input()
    flag_string = input()

    key_length = len(hidden_key)
    flag_length = len(flag_string)

    if key_length < flag_length:
        print('UNRESTORABLE')
        exit()

    key_list = list(hidden_key.replace('?', 'a'))

    for i in reversed(range(key_length - flag_length + 1)):
        part_key = hidden_key[i:i + flag_length]
        is_match = True

        for j in range(flag_length):
            if part_key[j] != '?' and part_key[j] != flag_string[j]:
                is_match = False
                break
            
        if is_match:
            for k in range(flag_length):
                key_list[i + k] = flag_string[k]
            print(''.join(key_list))
            break

    if not is_match:
        print('UNRESTORABLE')