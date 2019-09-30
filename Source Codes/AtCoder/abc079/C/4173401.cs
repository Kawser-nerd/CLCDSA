using System;
using System.Linq;
public class Hello{
    public static void Main(){
        // Your code here!
        int[] a = Console.ReadLine().ToCharArray().Select(x => int.Parse(x.ToString())).ToArray();
        int n = a.Length - 1;
        
        
        for(int i = 0; i < Math.Pow(2, n); i++)
        {
            string[] s = new string[3];
            for(int j = 0; j < n; j++)
            {
                if((1 & i>>j) == 1) s[j] = "+";
                else s[j] = "-";
            }
            
            int sum = a[0];
            for(int k = 0; k < s.Length; k++)//7??????????
            {
                if(s[k] == "+") sum += a[k + 1];
                else sum -= a[k + 1];
            }
            
            if(sum == 7)
            {
                Console.WriteLine(a[0] + s[0] + a[1] + s[1] + a[2] + s[2] + a[3] + "=7");
                return;
            }
        }
        
    }
}