import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {
  static double inf = Double.MAX_VALUE / 10;

  private static void solve() {
    int n = ni();
    String[] large = new String[n];
    String[] small = new String[n];
    int[] m = new int[n];
    String[] id2node = new String[300];
    Map<String, Integer> nodeId = new HashMap<>();
    int currentId = 0;
    for (int i = 0; i < n; i ++) {
      large[i] = next();
      m[i] = ni();
      small[i] = next();
      
      if (!nodeId.containsKey(large[i])) {
        id2node[currentId] = large[i];
        nodeId.put(large[i], currentId ++);
      }
      if (!nodeId.containsKey(small[i])) {
        id2node[currentId] = small[i];
        nodeId.put(small[i], currentId ++);
      }
    }
    
    int p = nodeId.size();
    double[][] d = new double[p][p];
    for (double[] x : d) {
        Arrays.fill(x, inf);
    }
    for (int i = 0; i < p; i ++) {
      d[i][i] = 0;
    }

    for (int i = 0; i < n; i ++) {
      int u = nodeId.get(large[i]);
      int v = nodeId.get(small[i]);
      
      d[v][u] = Math.log(m[i]);
      d[u][v] = -Math.log(m[i]);
    }

    for (int i = 0; i < 3; i ++)
    d = wf(d);
    
    int retSmall = 0;
    int retLarge = 0;
    double ret = 0;
    for (int i = 0; i < p; i ++) {
      for (int j = 0; j < p; j ++) {
        if (i == j) continue;
        if (d[i][j] < 0) continue;
        
        if (d[i][j] < inf / 2 && ret < d[i][j]) {
          retSmall = i;
          retLarge = j;
          ret = d[i][j];
        }
      }
    }
    //System.out.println(Arrays.deepToString(d));
    System.out.println("1" + id2node[retLarge] + "=" + (long)(Math.exp(ret) + 0.001) + id2node[retSmall]);
  }

  public static double[][] wf(double[][] d) {
    int n = d.length;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][j] == inf && d[i][k] != inf && d[k][j] != inf) {
            d[i][j] = d[i][k] + d[k][j];
          }
        }
      }
    }
    return d;
  }
  
  
  public static void main(String[] args) {
    new Thread(null, new Runnable() {
      @Override
      public void run() {
        long start = System.currentTimeMillis();
        String debug = System.getProperty("debug");
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