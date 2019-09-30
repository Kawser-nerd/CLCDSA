namespace ABC005 {
  class ProblemB {
    static void Main(string[] args) {
      int n = int.Parse(System.Console.ReadLine());
      int[] t = new int[n];
      for (int i = 0; i < n; i++) {
        t[i] = int.Parse(System.Console.ReadLine());
      }
      System.Console.WriteLine(Min(t));
    }
    public static int Min(int[] array) {
      int ret = array[array.Length - 1];
      for (int i = 0; i < array.Length - 1; i++) {
        if (ret > array[i]) {
          ret = array[i];
        }
      }
      return ret;
    }
  }
}