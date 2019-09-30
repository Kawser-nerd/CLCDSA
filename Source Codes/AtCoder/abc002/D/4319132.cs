using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static private bool mask(int mask, int shift){
            return (mask&(1<<shift)) != 0 ? true : false; 
        }
        static void Main(string[] args){
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]), M = int.Parse(s[1]);
            bool[,] connect = new bool[N,N];
            for(int i=0; i<M; i++){
                s = Console.ReadLine().Split(' ');
                int x = int.Parse(s[0]), y = int.Parse(s[1]);
                connect[x-1, y-1] = connect[y-1, x-1] = true;
            }
            int max = 0;
            for(int i=0; i<(1<<N); i++){
                List<int> mem = new List<int>();
                bool flag = false;
                for(int r=0; r<N; r++){
                    if(mask(i,r)) mem.Add(r);
                }
                for(int j=0; j<mem.Count(); j++){
                    for(int k=j+1; k<mem.Count(); k++){
                        if(!connect[mem[j],mem[k]]){
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(!flag) max = Math.Max(max, mem.Count());
            }
            Console.WriteLine(max);
        }   
    }
}