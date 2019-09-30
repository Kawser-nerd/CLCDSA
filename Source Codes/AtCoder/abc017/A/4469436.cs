using System;

    class Program {
    static void Main(string[] args) {
        double score = 0;
      for(int i = 0; i < 3; ++i) {
            string[] str = Console.ReadLine().Split(' ');
            score += double.Parse(str[0]) * double.Parse(str[1]) / 10.0;
        }
        Console.WriteLine(score);
     }
    }