import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
  static double[] logP = new double[1 << 17];
  
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("A.in"));
    PrintWriter out = new PrintWriter(new File("A.out"));
    
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      out.print("Case #" + tc + ": ");
      int A = s.nextInt(), B = s.nextInt();
      double best = A + B + 1;
      logP[0] = Math.log(s.nextDouble());
      best = Math.min(best, (2 * (A - 1) + (B - A) + 1) + (B + 1) - (B + 1) * Math.exp(logP[0]));
      for (int i = 1; i < A; i++) {
        logP[i] = logP[i-1] + Math.log(s.nextDouble());
        best = Math.min(best, (2 * (A - 1 - i) + (B - A) + 1) + (B + 1) - (B + 1) * Math.exp(logP[i]));
      }
      best = Math.min(best, B + 2);
      out.println(best);
    }
    out.close();
  }

}
