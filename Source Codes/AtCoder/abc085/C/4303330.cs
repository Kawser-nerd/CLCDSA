using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int Y = int.Parse(s[1]); 
            int[] com = new int[]{-1,-1,-1};
            for(int i=0; i<=N; i++){
                for(int j=0; j<=N; j++){
                    if(10*i+5*j+(N-i-j) == Y/1000 && N-i-j>=0){
                        com = new int[]{i, j, N-i-j};
                        break;
                    }
                }
            }
            Console.WriteLine(string.Join(" ", com));
        }
    }
}