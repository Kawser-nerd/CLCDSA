using System;
using System.Linq;
public class Hello{
    public static void Main()
    {
        // Your code here!
        int N = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        int Alice = 0;
        int Bob = 0;
        Array.Sort(a);
        Array.Reverse(a);
        
        for(int i = 0; i < N; i++)
        {
            if(i % 2 == 0)
            {
                Alice += a[i];
            }
            else
            {
                Bob += a[i];
            }
            
        }
        
        Console.WriteLine(Alice - Bob);
        
        
    }
}