using System;

public class Hello{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        int g1 = int.Parse(Console.ReadLine());
        int g2 = int.Parse(Console.ReadLine());
        int g3 = int.Parse(Console.ReadLine());
        int n = N;
        if (N == g1 || N == g2 || N == g3) {
            Console.WriteLine("NO");
        } else {
            for (int i = 0; i < 100; i++) {
            if (n - 3 >= 0 && n - 3 != g1 && n - 3 != g2 && n - 3 != g3) {
                n -= 3;
            } else if (n - 2 >= 0 && n - 2 != g1 && n - 2 != g2 && n - 2 != g3) {
                n -= 2;
            } else if (n - 1 >= 0 && n - 1 != g1 && n - 1 != g2 && n - 1 != g3) {
                n -= 1;
            }
        }
        if (n == 0)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
        }
        
    }
}