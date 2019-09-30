import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class D {
  static double[] dpc = new double[1024];
  static double[] dpa = new double[1024];
  
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("D.in"));
    PrintWriter out = new PrintWriter(new File("D.out"));
    
    dpc[1] = 0;
    dpc[2] = 2;
    dpa[1] = 0;
    dpa[2] = 1;
    for (int i = 3; i <= 1000; i++) {
      dpc[i] = 1;
      for (int j = 1; j < i; j++) {
        dpc[i] += (dpc[j] + dpa[i - j]) / i;
      }
      dpc[i] *= ((double) i) / (i - 1);
      dpa[i] = dpc[i] - 1;
    }
    
    int T = s.nextInt();
    int[] arr = new int[1024];
    boolean[] mark = new boolean[1024];
    for (int tc = 1; tc <= T; tc++) {
      out.print("Case #" + tc + ": ");
      int N = s.nextInt();
      for (int i = 1; i <= N; i++) arr[i] = s.nextInt();
      double answer = 0;
      Arrays.fill(mark, false);
      for (int i = 1; i <= N; i++) {
        int cycleLength = 0;
        int cur = i;
        while (!mark[cur]) {
          mark[cur] = true;
          cur = arr[cur];
          cycleLength++;
        }
        answer += dpc[cycleLength];
      }
      
      out.println(answer);
    }
    out.close();
    
    System.out.println(dpc[1000]);
  }
}
