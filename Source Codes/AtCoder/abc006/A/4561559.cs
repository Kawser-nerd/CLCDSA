namespace ABC006 {
  class ProblemA {
    static void Main(string[] args) {
      int n = int.Parse(System.Console.ReadLine());
      System.Console.WriteLine(n % 3 == 0 ? "YES" : "NO");
    }
  }
}