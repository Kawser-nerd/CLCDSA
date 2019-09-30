N = int(input())
S1 = input()
S2 = input()

def delete_node(node):
    if node in relations:
        will_deleted_nodes = relations.pop(node)
        for will_deleted_node in will_deleted_nodes:
            delete_node(will_deleted_node)

firsts = [S1[0], S2[0]]

relations = {}
for s1, s2 in zip(S1, S2):
    if s1 not in relations:
        relations[s1] = set()
    relations[s1].add(s2)
    if s2 not in relations:
        relations[s2] = set()
    relations[s2].add(s1)

for item in range(10):
    string = str(item)
    delete_node(string)

ans = 1
while relations:
    key = list(relations.keys())[0]
    ans *= (10 - (key in firsts))
    delete_node(key)

print(ans)