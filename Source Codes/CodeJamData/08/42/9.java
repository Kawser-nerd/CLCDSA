import java.io.*;
import java.util.StringTokenizer;

/**
 * @author nik
 */
public class B {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
    PrintWriter out = new PrintWriter("b.out");

    int C = Integer.parseInt(in.readLine());

    for (int i = 1; i <= C; i++) {
      StringTokenizer tz = new StringTokenizer(in.readLine());
      int N = Integer.parseInt(tz.nextToken());
      int M = Integer.parseInt(tz.nextToken());
      int A = Integer.parseInt(tz.nextToken());
      
      String ans;
      if (A > N * M) {
        ans = "IMPOSSIBLE";
      }
      else {
        int a = A / M;
        int b,c=1,d = M;
        if (a * M == A) {
          b = 0;
        }
        else {
          a++;
          b = a*d - A;
        }
        ans = "0 0 " + a + " " + b + " " + c + " " + d;
      }
      out.println("Case #" + i + ": " + ans);
    }

    in.close();
    out.close();
  }
}
