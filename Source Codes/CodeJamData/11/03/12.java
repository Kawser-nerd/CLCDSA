import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("C.in"));
    PrintWriter out = new PrintWriter(new File("C.out"));
    
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      out.print("Case #" + tc + ": ");
      int N = s.nextInt();
      int sum = 0;
      int xor = 0;
      int min = Integer.MAX_VALUE;
      for (int i = 0; i < N; i++) {
        int cur = s.nextInt();
        sum += cur;
        xor ^= cur;
        min = Math.min(min, cur);
      }
      if (xor != 0) {
        out.println("NO");
      } else {
        out.println(sum - min);
      }
    }
    out.close();
  }
}
