using System;
class Program
{
    static void Main()
    {
        int n;
        n = int.Parse(Console.ReadLine());
        string[] s = Console.ReadLine().Split(' ');
        int[] l = new int[n];
        for(int i=0;i<n;i++){
            l[i] = int.Parse(s[i]);
        }
        Array.Sort(l);
        int sum = 0;
        for(int i=0;i<n-1;i++)
        {
            sum += l[i];
        }
        if(l[n-1] < sum)
        {
            Console.Write("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}