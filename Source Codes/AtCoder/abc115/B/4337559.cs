using System;
class Program {
  static void Main(string[] args) {
    int n = int.Parse(Console.ReadLine());
    int all = 0;
    int biggest = 0;
    int num_buffer;
    for (int cnt = 0; cnt < n; cnt++) {
      num_buffer = int.Parse(Console.ReadLine());
      all += num_buffer;
      if (biggest < num_buffer) biggest = num_buffer;
    }
    all -= biggest / 2;
    Console.WriteLine(all);
  }
}