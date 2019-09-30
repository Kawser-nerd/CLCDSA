using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            char[] c = Console.ReadLine().ToCharArray();
            int n = int.Parse(Console.ReadLine());
            
            int[] nums;
            List<char> rc = new List<char>();
            for(int i = 0 ; i < n ; i++)
            {
                rc.Clear();
                nums = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
                
                for(int ci = nums[0]-1; ci < nums[1] ; ci++)
                {
                    rc.Add(c[ci]);
                }
                rc.Reverse();
                int a = 0;
                for(int ri = nums[0]-1 ; ri < nums[1] ; ri++)
                {
                    c[ri] = rc[a];
                    a++;
                }

            }
            string ss = new String(c);
            Console.WriteLine(ss);
    	}
    }
}