import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
  static int[] visit = new int[1024];
  static int[] a = new int[1024];
  static int[] b = new int[1024];
  
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("B.in"));
    PrintWriter out = new PrintWriter(new File("B.out"));
    
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      out.print("Case #" + tc + ": ");
      int N = s.nextInt();
      
      Arrays.fill(visit, 0);
      for (int i = 0; i < N; i++) {
        a[i] = s.nextInt();
        b[i] = s.nextInt();
      }
      
      int ans = 0;
      int stars = 0;
      boolean progress = true;
      outer: while (progress) {
        if (stars == 2 * N) break;
        ans++;
        progress = false;
        for (int i = 0; i < N; i++) {
          if (visit[i] == 0 && b[i] <= stars) {
            progress = true;
            stars += 2;
            visit[i] = 2;
            continue outer;
          }
        }
        
        for (int i = 0; i < N; i++) {
          if (visit[i] == 1 && b[i] <= stars) {
            progress = true;
            stars += 1;
            visit[i] = 2;
            continue outer;
          }
        }
        
        int bestb = 0;
        int besti = 0;
        for (int i = 0; i < N; i++) {
          if (visit[i] == 0 && a[i] <= stars) {
            progress = true;
            if (bestb < b[i]) {
              bestb = b[i];
              besti = i;
            }
          }
        }
        if (progress) {
          visit[besti] = 1;
          stars += 1;
        }
      }
      
      if (stars == 2 * N)
        out.println(ans);
      else
        out.println("Too Bad");
    }
    out.close();
  }
}
