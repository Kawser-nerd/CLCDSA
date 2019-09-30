import java.io.*;
import java.util.*;

public class C {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "C-large";

  private static void main2() throws IOException {
    r = in.nextInt();
    c = in.nextInt();
    int n = 2*(r+c);
    int[] perm = new int[n];
    boolean[] covered = new boolean[n];
    for (int i = 0; i < n; i++) perm[i] = in.nextInt()-1;
    
    grid = new char[r][c];
    for (char[] x : grid) Arrays.fill(x, '.');

    boolean[] placed = new boolean[n];
    int taken = 0;
    while (taken < n) {
      boolean found = false;
      for (int j = 0; j < n; j += 2) {
        if (placed[j]) continue;
        int a1 = perm[j], a2 = perm[j+1];
        boolean ok = true;
        for (int k = (a1+1)%n; k != a2; k = (k+1)%n) {
          if (!covered[k]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          if (!fill(a1,a2)) {
            out.println("IMPOSSIBLE");
            return;
          }
          covered[a1] = true;
          covered[a2] = true;
          placed[j] = true;
          found = true;
          taken += 2;
          continue;
        }
        ok = true;
        for (int k = (a2+1)%n; k != a1; k = (k+1)%n) {
          if (!covered[k]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          if (!fill(a2,a1)) {
            out.println("IMPOSSIBLE");
            return;
          }
          covered[a1] = true;
          covered[a2] = true;
          placed[j] = true;
          found = true;
          taken += 2;
          continue;
        }
      }
      if (!found) {
        out.println("IMPOSSIBLE");
        return;
      }
    }
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
      if (grid[i][j] == '.') grid[i][j] = '/';
    for (char[] x : grid)
      out.println(new String(x));
  }
  public static int r,c;
  public static char[][] grid;
  public static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
  public static boolean fill(int from, int to) {
    int curdir = 0;
    int cx = 0, cy = 0;
    if (from <= c-1) {
      curdir = 2;
      cx = 0;
      cy = from;
    } else if (from <= c+r-1) {
      curdir = 3;
      cx = from-c;
      cy = c-1;
    } else if (from <= c+r+c-1) {
      curdir = 0;
      cx = r-1;
      cy = c-1 - (from-c-r);
    } else {
      curdir = 1;
      cx = r-1 - (from-c-r-c);
      cy = 0;
    }
    while (true) {
      if (grid[cx][cy] == '.') {
        switch(curdir) {
          case 0:
            grid[cx][cy] = '\\';
            break;
          case 1:
            grid[cx][cy] = '/';
            break;
          case 2:
            grid[cx][cy] = '\\';
            break;
          case 3:
            grid[cx][cy] = '/';
            break;
        }
      }
      switch(grid[cx][cy]) {
        case '/':
          curdir ^= 1;
          cx += dx[curdir];
          cy += dy[curdir];
          break;
        case '\\':
          curdir ^= 3;
          cx += dx[curdir];
          cy += dy[curdir];
          break;
      }
      if (cx < 0 || cx >= r || cy < 0 || cy >= c) break;
    }
    int dest = 0;
    if (cx < 0) dest = cy;
    else if (cy == c) dest = cx+c;
    else if (cx == r) dest = (c-1-cy)+c+r;
    else dest = (r-1-cx)+c+r+c;
    return to == dest;
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.println("Case #" + test + ":");
      main2();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
