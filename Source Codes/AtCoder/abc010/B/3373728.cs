using System.Linq;
using static System.Console;

class Program {
  static void Main() {
    int[] t = { 0, 0, 1, 0, 1, 2, 3, 0, 1, 0 };
    ReadLine();
    WriteLine(ReadLine().Split().Select(int.Parse).Select(x => t[x]).Sum());
  }
}