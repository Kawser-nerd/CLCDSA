using System;
namespace Atcoder { 
    class Program{
        public static void Main(string[] arg){
            int n = int.Parse(Console.ReadLine());
            int x = 2025 - n;
            for (int i = 1; i < 10; i++){
                if (x % i == 0 && (x / i) < 10){
                    Console.WriteLine("{0} x {1}", i, x / i);
                }
            }
             }
    }
}