base_string = "WBWBWWBWBWBW" * 5

input_str = input()

l = base_string.find(input_str)


kenban = ["Do","Do","Re","Re","Mi","Fa", "Fa","So", "So","La", "La","Si"]
ans = kenban[l]
print(ans)