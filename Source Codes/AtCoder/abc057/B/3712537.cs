using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        public static void Main(string[] args)
        {
            string[] buf = Console.ReadLine().Split(' ');
            int N = int.Parse(buf[0]);
            int M = int.Parse(buf[1]);
            int mcp = 0;
            int min = 999999999;
            
            int[] pX = new int[N];
            int[] pY = new int[N];
            for(int i = 0 ; i < N ; i++)
            {
                buf = Console.ReadLine().Split(' ');
                pX[i] = int.Parse(buf[0]);
                pY[i] = int.Parse(buf[1]);
            }
            
            int[] cX = new int[M];
            int[] cY = new int[M];
            for(int i = 0 ; i < M ; i++)
            {
                buf = Console.ReadLine().Split(' ');
                cX[i] = int.Parse(buf[0]);
                cY[i] = int.Parse(buf[1]);
            }
            
            for(int i = 0 ; i < N ; i++)
            {
                min = 999999999;
                mcp = 0;
                for(int j = 0 ; j < M ; j++)
                {
                    int kyori = Math.Abs(pX[i] - cX[j]) + Math.Abs(pY[i] - cY[j]);
                    if(kyori < min)
                    {
                        min = kyori;
                        mcp = j+1;
                    }
                }
                Console.WriteLine(mcp);
            }
        }
    }
}