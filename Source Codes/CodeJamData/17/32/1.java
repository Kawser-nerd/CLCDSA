import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class Care implements Runnable {
  private static final String NAME = "care";

  private  StreamTokenizer in;

  int nextInt() throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  long nextLong() throws Exception {
    in.nextToken();
    return (long) in.nval;
  }

  @Override
  public void run() {
    try {
      //Scanner in = new Scanner(new File(NAME + ".in"));
      //BufferedReader in = new BufferedReader(new FileReader(new File(NAME + ".in")));
      in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + ".in"))));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = nextInt();

      int day = 1440;
      int max = 720;
      for (int test = 1; test <= tests; test++) {
        int ac = nextInt();
        int aj = nextInt();
        boolean[] c = new boolean[day + 1];
        boolean[] j = new boolean[day + 1];
        for (int i = 0; i < ac; i++) {
          int l = nextInt();
          int r = nextInt();
          for (int k = l; k < r; k++) {
            c[k] = true;
          }
        }
        for (int i = 0; i < aj; i++) {
          int l = nextInt();
          int r = nextInt();
          for (int k = l; k < r; k++) {
            j[k] = true;
          }
        }

        int[][][] res = new int[day + 1][max + 1][2];

        for (int i = 0; i <= day; i++) {
          for (int k = 0; k <= max; k++) {
            res[i][k][0] = res[i][k][1] = 10 * day;
          }
        }
        res[0][0][0] = 0;
        for (int i = 0; i < day; i++) {
          if (!c[i]) {
            for (int k = 1; k <= max; k++) {
              res[i + 1][k][0] = Math.min(res[i + 1][k][0], res[i][k - 1][0]);
              res[i + 1][k][0] = Math.min(res[i + 1][k][0], res[i][k - 1][1] + 1);
            }
          }
          if (!j[i]) {
            for (int k = 0; k <= max; k++) {
              res[i + 1][k][1] = Math.min(res[i + 1][k][1], res[i][k][1]);
              res[i + 1][k][1] = Math.min(res[i + 1][k][1], res[i][k][0] + 1);
            }
          }
        }
//        System.out.println(Arrays.toString(c));
//        System.out.println(Arrays.toString(j));
//        System.out.println("---");
//        for (int i = 0; i <= day; i++ ) {
//          for (int k = 0; k <= max; k++) {
//            System.out.print(res[i][k][0] + " ");
//          }
//          System.out.println();
//          for (int k = 0; k <= max; k++) {
//            System.out.print(res[i][k][1] + " ");
//          }
//          System.out.println("\n-----");
//        }
        int rr0 = Math.min(res[day][max][0], res[day][max][1] + 1);

        for (int i = 0; i <= day; i++) {
          for (int k = 0; k <= max; k++) {
            res[i][k][0] = res[i][k][1] = 10 * day;
          }
        }
        res[0][0][1] = 0;
        for (int i = 0; i < day; i++) {
          if (!c[i]) {
            for (int k = 1; k <= max; k++) {
              res[i + 1][k][0] = Math.min(res[i + 1][k][0], res[i][k - 1][0]);
              res[i + 1][k][0] = Math.min(res[i + 1][k][0], res[i][k - 1][1] + 1);
            }
          }
          if (!j[i]) {
            for (int k = 0; k <= max; k++) {
              res[i + 1][k][1] = Math.min(res[i + 1][k][1], res[i][k][1]);
              res[i + 1][k][1] = Math.min(res[i + 1][k][1], res[i][k][0] + 1);
            }
          }
        }
        int rr1 = Math.min(res[day][max][0] + 1, res[day][max][1]);
        System.out.println("Case #" + test);
        out.println("Case #" + test + ": " + Math.min(rr0, rr1));
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Care()).start();
  }
}