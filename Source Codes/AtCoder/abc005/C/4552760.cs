namespace ABC005 {
  class ProblemC {
    static void Main(string[] args) {
      int t = int.Parse(System.Console.ReadLine());
      int n = int.Parse(System.Console.ReadLine());
      int[] a = new int[n];
      string[] str = System.Console.ReadLine().Split(' ');
      for (int i = 0; i < n; i++) {
        a[i] = int.Parse(str[i]);
      }
      int m = int.Parse(System.Console.ReadLine());
      int[] b = new int[m];
      str = System.Console.ReadLine().Split(' ');
      for (int i = 0; i < m; i++) {
        b[i] = int.Parse(str[i]);
      }

      bool[] flag = new bool[m];
      int start = 0;
      for (int i = 0; i < m; i++) {
        flag[i] = false;
        for (int j = start; j < n; j++) {
          if (b[i] - t <= a[j] && a[j] <= b[i]) {
            flag[i] = true;
            start = j + 1;
            break;
          }
        }
      }
      System.Console.WriteLine(And(flag) ? "yes" : "no");
    }
    public static bool And(bool[] array) {
      bool ret = array[array.Length - 1];
      for (int i = 0; i < array.Length - 1; i++) {
        ret = ret && array[i];
      }
      return ret;
    }
  }
}