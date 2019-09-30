using System;

class Program
{
  static void Main(string[] args)
  {
    int[] t = new int[3];
    string[] str = Console.ReadLine().Split(' ');
    t[0] = int.Parse(str[0]);
    t[1] = int.Parse(str[1]);
    t[2] = int.Parse(str[2]);

    int n5 = 0;
    int n7 = 0;

    for(int i = 0; i<3; i++) {
      if (t[i] == 5) {
        n5++;
      } else if (t[i] == 7) {
        n7++;
      }
    }

    if (n5 == 2 && n7 == 1) {
      Console.Write("YES");
    } else {
      Console.Write("NO");
    }
  }
}