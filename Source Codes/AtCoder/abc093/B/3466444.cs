using System;
using System.Text;

namespace Main
{
  class Program
  {
    static void Main(string[] args)
    {
      string[] lines = Console.ReadLine().Split(' ');
      int a = int.Parse(lines[0]);
      int b = int.Parse(lines[1]);
      int k = int.Parse(lines[2]);

      StringBuilder buf = new StringBuilder();
      if (b - a < k * 2)
      {
        for (int i = a; i <= b; i++)
            buf.Append(i).Append('\n');
      }
      else
      {
        for (int i = a; i < a + k; i++)
          buf.Append(i).Append('\n');
        for (int i = b - k + 1; i <= b; i++)
          buf.Append(i).Append('\n');
      }

      Console.Write(buf);
    }
  }
}