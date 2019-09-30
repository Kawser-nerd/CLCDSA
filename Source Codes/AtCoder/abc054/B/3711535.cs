using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        static char[,] A;
        static char[,] B;
        static int N;
        static int M;
        
        public static void Main(string[] args)
    	{
            string[] s = Console.ReadLine().Split(' ');
            N = int.Parse(s[0]);
            M = int.Parse(s[1]);
            
            A = new char[N,N];
            B = new char[M,M];
            bool ok = false;
            
            
            string ss;
            for(int i = 0 ; i < N ; i++)
            {
                ss = Console.ReadLine();
                for(int j = 0 ; j < N ; j++) A[i,j] = ss[j];
            }
            for(int i = 0 ; i < M ; i++)
            {
                ss = Console.ReadLine();
                for(int j = 0 ; j < M ; j++) B[i,j] = ss[j];
            }
            
            for(int i = 0 ; i < N - M+1 ; i++)
            {
                for(int j = 0 ; j < N - M+1 ; j++)
                {
                    if(check(i,j))ok = true;
                }
            }
            
            if(ok) Console.WriteLine("Yes");
            else Console.WriteLine("No");
    	}
    	public static bool check(int x , int y)
    	{
    	    char[,] c = new char[M,M];
    	    for(int i = 0 ; i < M ; i++)
    	    {
    	        for(int j = 0 ; j < M ; j++)
    	        {
    	            c[i,j] = A[i+x,j+y];
    	            if(B[i,j] != c[i,j]) return false; 
    	        }
    	    }
    	    
    	    return true;
    	}
    }
}