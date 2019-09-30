def magic(first, second, arrange1, arrange2):
    nums1 = arrange1[int(first)-1].split(" ")
    nums1 = [int(num) for num in nums1]
    nums2 = arrange2[int(second)-1].split(" ")
    nums2 = [int(num) for num in nums2]
    numsBoth = [num for num in nums1 if num in nums2]
    if len(numsBoth)> 1:
        return "Bad magician!"
    elif len(numsBoth) == 0:
        return "Volunteer cheated!"
    else:
        return str(numsBoth[0])

input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
with open("output", "a") as outputfile:
    for num in range(0,int(lines[0])):
        outputfile.write("Case #"+str(num+1)+": "+magic(lines[num*10+1], lines[num*10+6], lines[num*10+2:num*10+6], lines[num*10+7:num*10+11])+"\n")
        
