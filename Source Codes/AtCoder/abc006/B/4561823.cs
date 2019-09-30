namespace ABC006 {
  class ProblemB {
    static void Main(string[] args) {
      long n = long.Parse(System.Console.ReadLine());
      
      long[] a = new long[n];
      switch (n) {
        case 1:
          a[0] = 0;
          break;
        case 2:
          a[0] = 0; a[1] = 0;
          break;
        case 3:
          a[0] = 0; a[1] = 0; a[2] = 1;
          break;
        default:
          a[0] = 0; a[1] = 0; a[2] = 1;
          for (int i = 3; i < n; i++) {
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007;
          }
          break;
      }
      System.Console.WriteLine(a[n - 1]);
    }
  }
}