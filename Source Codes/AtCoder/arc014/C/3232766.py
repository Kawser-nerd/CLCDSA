n = int(input())
a = list(input())
st = []
for i in range(n):
    if st == []:
        st.append(a[i])
    elif a[i] == st[-1]:
        del st[-1]
    elif st[0] == a[i]:
        del st[0]
    elif i != n - 1:
        if a[i+1] == st[-1]:
            st.insert(0, a[i])
        else:
            st.append(a[i])
    else:
        st.insert(1, a[i])
print(len(st))