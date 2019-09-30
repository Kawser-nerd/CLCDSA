using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static private bool[,] connect = new bool[100,100];
        static private bool[] used = new bool[100];
        static private bool error=false;
        static private int N=0;
        static private void dfs(int now, int last){
            if(used[now]){
                error= true;
                return;
            }
            used[now]=true;
            for(int i=0; i<N; i++){
               if(connect[now,i] && last!=i){
                   dfs(i,now);
               }
            }
        }
        static void Main(string[] args){
            string[] s = Console.ReadLine().Split(' ');
            N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            for(int i=0; i<M; i++){
                s = Console.ReadLine().Split(' ');
                connect[int.Parse(s[0])-1,int.Parse(s[1])-1]=connect[int.Parse(s[1])-1,int.Parse(s[0])-1]=true;
            }

            int sum=0;
            for(int i=0; i<N; i++){
                if(!used[i]){
                    error=false;
                    dfs(i,-1);
                    sum += error ? 0 : 1;
                }
            }
            Console.WriteLine(sum);
        }   
    }
}