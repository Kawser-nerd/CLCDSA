N = int(input())
def func(s):
    if len(s)==N:
        print(s)
    else:
        func(s+'a')
        func(s+'b')
        func(s+'c')
func('')