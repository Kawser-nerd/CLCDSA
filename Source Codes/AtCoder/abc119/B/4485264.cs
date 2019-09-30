using System;

    class Program {
    static void Main(string[] args) {
        int N = int.Parse(Console.ReadLine());
        int count = 0;
        double JPYs = 0;
        double BTCs = 0;

        while (true) {
            ++count;
            if (count > N) break;

            string[] str = Console.ReadLine().Split(' ');
            double x = double.Parse(str[0]);
            string y = str[1];

            if(y == "JPY") {
                JPYs += x;
            }else if(y == "BTC") {
                BTCs += x;
            }
        }
        
        Console.WriteLine(JPYs + (BTCs * 380000.0));
    }

     
    }