import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("A.in"));
    PrintWriter out = new PrintWriter(new File("A.out"));
    
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      out.print("Case #" + tc + ": ");
      int N = s.nextInt();
      int bloc = 1, oloc = 1;
      int bextra = 0, oextra = 0;
      int total = 0;
      for (int i = 0; i < N; i++) {
        if (s.next().equals("O")) {
          int dest = s.nextInt();
          int needed = Math.max(Math.abs(dest - oloc) - oextra, 0) + 1;
          total += needed;
          bextra += needed;
          oextra = 0;
          oloc = dest;
        } else {
          int dest = s.nextInt();
          int needed = Math.max(Math.abs(dest - bloc) - bextra, 0) + 1;
          total += needed;
          oextra += needed;
          bextra = 0;
          bloc = dest;
        }
      }
      out.println(total);
    }
    out.close();
  }

}
