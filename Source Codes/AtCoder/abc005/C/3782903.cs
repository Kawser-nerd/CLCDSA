using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Program
{

    public class Program
    {	
        public static void Main()
    	{
            int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int T = n[0];
            
            int N = int.Parse(Console.ReadLine());
            List<int> takoyaki = new List<int>();
            n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            for(int i = 0 ; i < N ; i++) takoyaki.Add(n[i]);
            
            int M = int.Parse(Console.ReadLine());
            List<int> kyaku = new List<int>();
            n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            for(int i = 0 ; i < M ; i++) kyaku.Add(n[i]);
            
            bool eat = true;
            for(int i = 0 ; i < M ; i++)
            {
                eat = true;
                for(int j = 0 ; j < N ; j++)
                {
                    if(!eat) continue; 
                    if(kyaku[i] - takoyaki[j] <= T && kyaku[i] - takoyaki[j] >= 0)
                    {
                        takoyaki[j] = 999999999;
                        kyaku[i] = -99999999;
                        eat = false;
                    }
                }
            }
            
            bool ok = true;
            for(int i = 0 ; i < M ; i++)
            {

                if(kyaku[i] > 0) ok = false;
            }
            
            if(ok) Console.WriteLine("yes");
            else Console.WriteLine("no");
            
            
    	}
    }
}