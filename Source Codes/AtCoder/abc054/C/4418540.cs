using System;
using System.Linq;

namespace ABC054_C_CS_
{
    class Program
    {
        static int N,M;
        static bool[,] graph;//????
        static bool[] visited;//?????????

        static int Dfs(int v,int N,bool[] visited){
            bool allVisited = true;//??????????????????

            for(var i = 0;i < N;i++){//1?????????false???
                if(!visited[i]){
                    allVisited = false;
                }
            }

            if(allVisited){//??????1???
                return 1;
            }

            int ret = 0;

            //?????????????????????
            for(var i = 0;i < N;i++){
                //??i????????????????????????????i + 1???
                if(!graph[v,i]) continue;
                if(visited[i]) continue;

                visited[i] = true;//i?????
                ret += Dfs(i,N,visited);//i????????
                visited[i] = false;//????????

            }

            return ret;
        }
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            N = s[0];
            M = s[1];
            graph = new bool[N,N];
            visited = new bool[N];
            for(var i = 0;i < M;i++){
                var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                graph[input[0] - 1,input[1] - 1] = graph[input[1] - 1,input[0] - 1] = true;
            }
            visited[0] = true;
            Console.WriteLine(Dfs(0,N,visited));
        }
    }
}