def get_input():
    N,K = map(int,input().split())
    A = map(int,input().split())
    return N,K,A

def solve(N,K,A):
    sum_per_digit_list = sum_digit(A)
    K_b = to_2digit(K+1)
    cand = []
    for i in range(40):
        if K_b[i] ==1:
            cand.append(calc_opt(i,K_b,sum_per_digit_list,N))
    return max(cand)

def calc_opt(i,K_b,sum_per_digit_list,N):
    opt = 0
    for j in range(40):
        if j < i :
            opt+= max(N-sum_per_digit_list[j], sum_per_digit_list[j]) * 2**j
        elif j==i:
            opt+= sum_per_digit_list[j] * 2**j

        else:
            if K_b[j] == 1:
                opt+= (N - sum_per_digit_list[j]) * 2**j
            else:
                opt+= sum_per_digit_list[j] * 2**j
    return opt



def sum_digit(A):
    sum_per_digit_list = []
    numbers = list(A)
    for i in range(40):
        sum_per_digit_list.append(sum([number %2 for number in numbers]))
        numbers = [number //2 for number in numbers]
    return sum_per_digit_list
    
def to_2digit(number):
    digits = []
    for i in range(40):
        digits.append(number %2)
        number = number //2 
    return digits


if __name__ == "__main__":
    N,K,A = get_input()
    print(solve(N,K,A))