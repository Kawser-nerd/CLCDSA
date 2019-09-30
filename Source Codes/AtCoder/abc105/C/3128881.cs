using System;
public class Hello
{
    public static void Main()
    {
        // Your code here!
        int N = int.Parse(Console.ReadLine());
        string ans = "";
        while(N != 0)
        {
            if(N % 2 != 0)
            {
                ans = "1" + ans;
                N--;
            }
            else
            {
                ans = "0" + ans;
            }
            N /= -2;
        }
        if(ans == "") //N = 0???
        {
            ans = "0";
        }
        
        Console.WriteLine(ans);
    }
}