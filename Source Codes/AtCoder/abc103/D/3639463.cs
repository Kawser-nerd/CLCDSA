using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class test
{	

    public static int ans = 0;
    public static int n;
    //public static int m;
    //public static int cnt;

    public static void Main()
	{
        int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int n = nums[0];
        int m = nums[1];

        int[] islands = new int[n];
        int[] A = new int[m];
        int[] B = new int[m];

        for(int i = 0 ; i < m ; i++)
        {
            nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            A[i] = nums[0];
            B[i] = nums[1];
        }
        Array.Sort(B,A);
        int c = 0;
        for(int i = 0 ; i < m ; i++)
        {
            if(A[i] < c){
            } else {
                islands[B[i]-1] = 1;
                c = B[i];
            }
        }
        ans = islands.Sum();
        Console.WriteLine(ans);
 
        
    }
}