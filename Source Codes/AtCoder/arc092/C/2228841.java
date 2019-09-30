import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
 
public class Main {
  private static void solve() {
    int n = ni();
    int[] a = na(n);
    
    int[] p = new int[n / 2 + (n % 2 == 1 ? 1 : 0)];
    int[] q = new int[n / 2];
    
    for (int i = 0; i < n; i ++) {
      if (i % 2 == 0) {
        p[i / 2] = a[i];
      } else {
        q[i / 2] = a[i];
      }
    }
 
    long max1 = Long.MIN_VALUE;
    long max2 = Long.MIN_VALUE;
    for (int v : p) {
      if (v > 0) max1 += v;
    }
    for (int v : q) {
      if (v > 0) max2 += v;
    }
    
    List<Integer> list = new ArrayList<>();
    LinkedList<Long> l = new LinkedList<>();
    for (int v : a) {
      l.add((long)v);
    }

    if (max1 == Long.MIN_VALUE && max2 == Long.MIN_VALUE) {
      int max = Integer.MIN_VALUE;
      int maxIdx = 0;
      for (int i = 0; i < n; i ++) {
        if (max < a[i]) {
          max = a[i];
          maxIdx = i;
        }
      }
      for (int i = 0; i < maxIdx; i ++) {
        list.add(1);
        l.removeFirst();
      }
      while(l.size() > 1) {
        list.add(l.size());
        l.remove(l.size() - 1);
      }
    } else {
      if (max1 < max2) {
        list.add(1);
        l.removeFirst();
      }
      if (l.size() % 2 == 0) {
        list.add(l.size());
        l.removeLast();
      }
      
      int ptr = 0;
      while (l.size() > 1 && ptr < l.size()) {
        if (l.get(ptr) < 0) {
          if (ptr == 0) {
            list.add(1);
            list.add(1);
            l.removeFirst();
            l.removeFirst();
          } else if (ptr == l.size() - 1) {
            list.add(l.size());
            list.add(l.size() - 1);
            l.removeLast();
            l.removeLast();
          } else {
            long right = l.remove(ptr + 1);
            long left = l.remove(ptr - 1);
            l.set(ptr - 1, right + left);
            list.add(ptr + 1);
          }
        } else {
          ptr += 2;
        }
      }
      
      while (l.size() > 1) {
        long left = l.remove(0);
        long right = l.remove(1);
        l.set(0, left + right);
        list.add(2);
      }
    }

    System.out.println(l.getFirst());
    System.out.println(list.size());
    for (int v : list) {
      System.out.println(v);
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