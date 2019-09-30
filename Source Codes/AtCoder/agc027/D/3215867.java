import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {

  private static void solve() {
    int[] primes = sieveAtkin(10000);
    
    int n = ni();
    if (n == 2) {
      System.out.println("4 7");
      System.out.println("23 10");
      return;
    }
    long[][] a = new long[n][n];

    Set<Long> set = new HashSet<>();
    for (int i = 0; i < n; i ++) {
      for (int j = i % 2; j < n; j += 2) {
        a[i][j] = primes[(i + j) / 2];
      }
    }

    for (int i = 0; i < n; i ++) {
      for (int j = i % 2; j < n; j += 2) {
        a[i][j] *= primes[n + ((n - 1) / 2) + (i - j) / 2];
        set.add(a[i][j]);
      }
    }
    
    int[][] dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i ++) {
      for (int j = (i + 1) % 2; j < n; j += 2) {
        long x = 1;
        for (int[] d: dir) {
          int ni = i + d[0];
          int nj = j + d[1];
          
          if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
            continue;
          }
          x *= a[ni][nj] / gcd(a[ni][nj], x);
          
          if (x < 0 || x > 1000000000000000L) throw new RuntimeException();
        }
        a[i][j] = x + 1;
        set.add(a[i][j]);
      }
    }
    
    if (set.size() != n * n) throw new RuntimeException();

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        sb.append(a[i][j]);
        if (j == n - 1) {
          sb.append("\n");
        } else {
          sb.append(" ");
        }
      }
    }
    System.out.print(sb);
  }

  public static long gcd(long a, long b) {
    if (a > b) {
      long tmp = a;
      a = b;
      b = tmp;
    }
    while (a != 0) {
      long c = a;
      a = b % c;
      b = c;
    }
    return b;
  }

  public static int[] sieveAtkin(int size) {
    boolean[] isPrime = new boolean[size + 1];
    int sqrtN = (int) Math.sqrt(size);
    int n;
    for (int x = 1; x <= sqrtN; ++x) {
      for (int y = 1; y <= sqrtN; ++y) {
        n = 4 * x * x + y * y;
        if (n <= size && (n % 12 == 1 || n % 12 == 5)) {
          isPrime[n] = !isPrime[n];
        }
        n = 3 * x * x + y * y;
        if (n <= size && n % 12 == 7) {
          isPrime[n] = !isPrime[n];
        }
        n = 3 * x * x - y * y;
        if (x > y && n <= size && n % 12 == 11) {
          isPrime[n] = !isPrime[n];
        }
      }
    }

    for (n = 5; n <= sqrtN; ++n) {
      if (isPrime[n]) {
        for (int k = n * n; k <= size; k += n * n) {
          isPrime[k] = false;
        }
      }
    }
    isPrime[2] = isPrime[3] = true;

    int[] ret = new int[size];
    int count = 0;
    for (int i = 1; i < size; i++) {
      if (isPrime[i]) {
        ret[count++] = i;
      }
    }
    return Arrays.copyOf(ret, count);
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