namespace ABC005 {
  class ProblemA {
    static void Main(string[] args) {
      string[] str = System.Console.ReadLine().Split(' ');
      int x = int.Parse(str[0]), y = int.Parse(str[1]);
      System.Console.WriteLine(y / x);
    }
  }
}