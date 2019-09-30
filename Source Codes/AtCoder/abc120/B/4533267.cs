using System;

static class abc120b
{
    static void Main(string[] args)
    {
        var t = Console.ReadLine().Split();
        var A = int.Parse(t[0]);
        var B = int.Parse(t[1]);
        var K = int.Parse(t[2]);

        var count = 0;
        for (var i = Math.Min(A, B); i > 0; --i){
            if (A % i == 0 && B % i == 0){
                if(++count==K){
                    Console.WriteLine(i);
                    break;
                }
            }
        }
    }
}