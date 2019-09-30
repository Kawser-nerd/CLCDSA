import java.io.*;
import java.util.Scanner;

/**
 * @author nik
 */
public class C {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("C-small-attempt0.in"));
    PrintWriter out = new PrintWriter("c.out");

    int C = in.nextInt();
    for (int c = 1; c <= C; c++) {
      int R = in.nextInt();
      boolean[][] gr = new boolean[110][110];
      int k = 0;
      for (int i = 0; i < R; i++) {
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        for (int x = x1; x <= x2; x++) {
          for (int y = y1; y <= y2; y++) {
            if (!gr[x][y]) k++;
            gr[x][y] = true;
          }
        }
      }

      int t = 0;
      boolean[][] gr2 = new boolean[110][110], tt;
      while (k > 0) {
        for (int x = 0; x < gr.length; x++) {
          for (int y = 0; y < gr[0].length; y++) {
            if (x == 0 || y == 0) gr2[x][y] = false;
            else {
              gr2[x][y] = gr[x][y] && (gr[x-1][y] || gr[x][y-1])
                       || !gr[x][y] && gr[x-1][y] && gr[x][y-1];
            }
            if (gr2[x][y] && !gr[x][y]) k++;
            if (!gr2[x][y] && gr[x][y]) k--;
          }
        }

        tt = gr; gr = gr2; gr2 = tt;
        t++;
      }
      out.println("Case #" + c + ": " + t);
    }

    in.close();
    out.close();
  }
}
