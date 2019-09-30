S = input()
print(["yes", "no"][not(len(S) == len(set(S)))])