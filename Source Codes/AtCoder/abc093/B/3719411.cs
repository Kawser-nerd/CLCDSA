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
            string[] input = Console.ReadLine().Split(' ');
            int A = int.Parse(input[0]);
            int B = int.Parse(input[1]);
            int K = int.Parse(input[2]);
            
            List<int> list = new List<int>(); 
            
            for(int i = A ; i < A+K ; i++)
            {
                if(i <= B) list.Add(i);
            }
            for(int i = B ; i > B - K; i--)
            {
                if(i >= A){
                    if(!list.Contains(i))
                    {
                        list.Add(i);
                    }
                }
            }
            list.Sort();
            foreach(int i in list) Console.WriteLine(i);
        }
    }
}