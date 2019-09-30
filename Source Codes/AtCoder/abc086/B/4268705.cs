using System;

class Program
{
    static void Main(string[] args)
    {
        string[] s = Console.ReadLine().Split(' ');
        int a = int.Parse(s[0] + s[1]);
        string S = null;
        for(int i=1; i<=1000; i++){
            S = i*i == a ? "Yes" : "No";
            if(S == "Yes")break;
        }
        Console.WriteLine(S);
    }
}