import java.util.ArrayList;
import java.util.List;

public class Main {
  
  private static class Node {
    Node[] child = new Node[2];
    
    int depth;
    
    public Node(int depth) {
      this.depth = depth;
    }

    public void add(char[] s) {
      if (depth == s.length) {
        return;
      }
      
      int v = s[depth] - '0';
      
      if (child[v] == null) {
        child[v] = new Node(depth + 1);
      }
      child[v].add(s);
    }
    
  }

  private static void solve() {
    int n = ni();
    long l = nl();
    
    Node root = new Node(0);
    for (int i = 0; i < n; i ++) {
      char[] s = ns();
      root.add(s);
    }
    
    dfs(root, l);
    
    long x = 0;
    for (long y : list) {
      x ^= y;
    }
    
    if (x == 0) {
      System.out.println("Bob");
    } else {
      System.out.println("Alice");
    }

  } 
  static List<Long> list = new ArrayList<>();
  private static void dfs(Node node, long l) {
    if (node.child[0] == null && node.child[1] == null) {
      return;
    }

    if (node.child[0] == null || node.child[1] == null) {
      long v = l - node.depth;
      long g = 1;
      while (v % 2 == 0) {
        g <<= 1;
        v /= 2;
      }
      list.add(g);
    }
    
    if (node.child[0] != null) {
      dfs(node.child[0], l);
    }
    if (node.child[1] != null) {
      dfs(node.child[1], l);
    }
  }

  public static void main(String[] args) {
    new Thread(null, new Runnable() {
      @Override
      public void run() {
        long start = System.currentTimeMillis();
        String debug = args.length > 0 ? args[0] : null;
        if (debug != null) {
          try {
            is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
          } catch (Exception e) {
            throw new RuntimeException(e);
          }
        }
        reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
        solve();
        out.flush();
        tr((System.currentTimeMillis() - start) + "ms");
      }
    }, "", 64000000).start();
  }

  private static java.io.InputStream is = System.in;
  private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
  private static java.util.StringTokenizer tokenizer = null;
  private static java.io.BufferedReader reader;

  public static String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new java.util.StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  private static double nd() {
    return Double.parseDouble(next());
  }

  private static long nl() {
    return Long.parseLong(next());
  }

  private static int[] na(int n) {
    int[] a = new int[n];
    for (int i = 0; i < n; i++)
      a[i] = ni();
    return a;
  }

  private static char[] ns() {
    return next().toCharArray();
  }

  private static long[] nal(int n) {
    long[] a = new long[n];
    for (int i = 0; i < n; i++)
      a[i] = nl();
    return a;
  }

  private static int[][] ntable(int n, int m) {
    int[][] table = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[i][j] = ni();
      }
    }
    return table;
  }

  private static int[][] nlist(int n, int m) {
    int[][] table = new int[m][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[j][i] = ni();
      }
    }
    return table;
  }

  private static int ni() {
    return Integer.parseInt(next());
  }

  private static void tr(Object... o) {
    if (is != System.in)
      System.out.println(java.util.Arrays.deepToString(o));
  }
}