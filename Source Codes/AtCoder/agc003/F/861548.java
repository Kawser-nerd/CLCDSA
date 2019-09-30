/*************************************************************************
  >         File: Main.java
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 01 Sep 2016 07:59:07 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  static final int MO = (int) (1e9 + 7);
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;

    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    TaskF solver = new TaskF();
    solver.solve(1, in, out);
    out.close();
  }

  static class Matrix {
    static final int N = 3;
    long[][]  value = new long[N][N];
    Matrix(boolean ident) {
      if (ident) for (int i = 0; i < N; i++) value[i][i] = 1;
    }
  }

  static class TaskF {
    char[][] mp;
    int n, m;
    long k;

    private Matrix mul(Matrix a, Matrix b) {
      Matrix ans = new Matrix(false);
      for (int i = 0; i < Matrix.N; i++) {
        for (int j = 0; j < Matrix.N; j++) {
          for (int k = 0; k < Matrix.N; k++) {
            ans.value[i][j] += a.value[i][k] * b.value[k][j] % MO;
            ans.value[i][j] %= MO;
          }
        }
      }
      return ans;
    }

    private Matrix powd(Matrix x, long y) {
      Matrix ans = new Matrix(true);
      for (; y > 0; y >>= 1) {
        if (y % 2 != 0) ans = mul(ans, x);
        x = mul(x, x);
      }
      return ans;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt(); m = in.nextInt(); k = in.nextLong();
      if (k <= 1) {
        out.println(1);
        return ;
      }
      mp = new char[n][];
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        mp[i] = in.next().toCharArray();
        for (int j = 0; j < m; j++) if (mp[i][j] == '#') cnt++;
      }
      char[] left = new char[n + 1], right = new char[n + 1];
      for (int i = 0; i < n; i++) {
        left[i] = mp[i][0]; right[i] = mp[i][m - 1];
      }
      int rowMatch = match(mp[0], mp[n - 1]), columnMatch = match(left, right);
      if (rowMatch > 0 && columnMatch > 0) {
        out.println("1");
      } else if (rowMatch == 0 && columnMatch == 0) {
        out.println(powd(cnt, k - 1));
      } else {
        int r = 0, c = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if (i + 1 < n && mp[i][j] == mp[i + 1][j] && mp[i][j] == '#') r++;
            if (j + 1 < m && mp[i][j] == mp[i][j + 1] && mp[i][j] == '#') c++;
          }
        }
        int need = rowMatch == 0 ? c : r;
        Matrix base = new Matrix(false);
        base.value[1][0] = 1; base.value[1][1] = cnt;
        base.value[2][2] = rowMatch + columnMatch;
        base.value[2][1] = 1L * (MO - 1) * (rowMatch + columnMatch) % MO;
        //for (int i = 0; i < Matrix.N; i++) {
        //  for (int j = 0; j < Matrix.N; j++) {
        //    out.print(base.value[i][j] + " ");
        //  }
        //  out.println();
        //}
        base = powd(base, k - 1);
        long f2 = cnt - need, g2 = need;
        //for (int i = 0; i < Matrix.N; i++) {
        //  for (int j = 0; j < Matrix.N; j++) {
        //    out.print(base.value[i][j] + " ");
        //  }
        //  out.println();
        //}
        long answer = (base.value[0][0] + f2 * base.value[1][0] % MO + g2 * base.value[2][0] % MO) % MO;
        out.println(answer);
      }
    }

    private int match(char[] a, char[] b) {
      int n = a.length;
      int result = 0;
      for (int i = 0; i < n; i++) if (a[i] == '#' && b[i] == '#') result++;
      return result;
    }

    private long powd(long x, long y) {
      long ans = 1;
      while (y != 0) {
        if (y % 2 != 0) ans = ans * x % MO;
        x = x * x % MO;
        y >>= 1;
      }
      return ans;
    }
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

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }
  }
}