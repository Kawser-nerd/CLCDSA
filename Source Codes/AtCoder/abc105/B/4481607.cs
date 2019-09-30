using System;

class Program
{
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i <= n/4;i ++) {
            for (int j = 0; j <= n/4-i; j ++) {
                if (i*4 + j*7 == n) {
                    Console.WriteLine("Yes");
                    return;
                }
                if (i == n/4) {
                    Console.WriteLine("No");
                    return;
                }
            }
        }
    }
}