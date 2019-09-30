using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine();
        
        var x = 0;
        var max = x;
        foreach (var ch in s.ToCharArray())
        {
          	if (ch == 'I')
            {
                x++;
            }
            else
            {
                x--;
            }
          
          	if (max < x)
          	{
            	max = x;
         	}
        }
      
      	Console.WriteLine(max);
    }
}