#?? dfs ??????????true???????false??????????
#???????????????????????edge(u,v)??????????
#(???????????????????????)
#true????????????

N,M = (int(_) for _ in input().split())
E = []
V = [[i+1,0] for i in range(N)] #0?????????????????1????
searched_vertex = [] #?????vertex?stuck(????????????????????)
for i in range(M):
    u,v = (int(_) for _ in input().split())
    E.append([u,v,True])#?????False????????

cnt_trees = 0

def find_tree(vertex):
    flag = True
    index,reached = vertex
    if reached == 0:
        V[index-1][1] = 1
    searched_vertex.append(index)
    #print(V)
    #print(searched_vertex)
    while searched_vertex:
        i = searched_vertex[len(searched_vertex)-1]
        for edge_index in range(len(E)):
            u,v,unused = E[edge_index]
            #print("u={}".format(E[edge_index]))
            if unused :
                if u == i:
                    E[edge_index][2] = False
                    #v?????vertex????stuck??????
                    for ind in range(len(searched_vertex)):
                        if v == searched_vertex[ind]:#?????
                            flag = False#????????????reached??????flag????
                            break
                    else:
                        V[v-1][1] = 1 #vertex??????????????????????
                        #print("1.{}".format(V))
                        searched_vertex.append(v)
                        #print('break!')
                        break

                elif v == i:
                    E[edge_index][2] = False
                    #u?????vertex????stuck???????
                    for ind in range(len(searched_vertex)):
                        if u == searched_vertex[ind]:
                            flag = False
                            break
                    else:
                        V[u-1][1] = 1
                        #print("2.{}".format(V))
                        searched_vertex.append(u)
                        break
            #print('unbreak!')
        else:
            searched_vertex.pop()
        #print(searched_vertex)
    return flag


#print(V)
for index,reached in V:
    if reached == 0:
        for j in range(len(E)):
            E[j][2] = True
        if find_tree((index,reached)):
            cnt_trees += 1
        #print(V)

print(cnt_trees)