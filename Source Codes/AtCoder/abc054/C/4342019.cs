using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static private int[] NM;
        static private bool[,] connect = new bool[8,8];
        static private bool[] visited = new bool[8];
        static private int sum=0;
        static private void dfs(int count, int last){
            if(count == NM[0]){
                sum++;
                return;
            }
            for(int i=0; i<NM[0]; i++){
                if(!visited[i] && connect[last, i]){
                    visited[i] = true;
                    dfs(count+1, i);
                    visited[i] = false;
                }
            }
        }
        static void Main(string[] args){
            NM = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            for(int i=0; i<NM[1]; i++){
                var ab = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                connect[ab[0]-1,ab[1]-1] = connect[ab[1]-1,ab[0]-1] = true;
            }
            visited[0]=true;
            dfs(1,0);
            Console.WriteLine(sum);
        }
    }   
}