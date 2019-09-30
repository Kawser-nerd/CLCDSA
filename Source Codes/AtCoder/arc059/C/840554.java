//import java.awt.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream;
    if (args.length > 0 && args[0].equals("devTesting")) {
      try {
        inputStream = new FileInputStream(args[1]);
      } catch(FileNotFoundException e) {
        throw new RuntimeException(e);
      }
    } else {
      inputStream = System.in;
    }
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }
  
  static class TaskE {
    final int ring = (int) 1e9 + 7;
    int n, c;
    int[] ai, bi;
    int[][] state, pow, sum;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      c = in.nextInt();
      ai = new int[n];
      bi = new int[n];
      for (int i = 0; i < n; ++i) {
        ai[i] = in.nextInt();
      }
      for (int i = 0; i < n; ++i) {
        bi[i] = in.nextInt();
      }
      pow = new int[401][401];
      for (int i = 0; i <= 400; ++i) {
        for (int j = 0; j <= 400; ++j) {
          pow[i][j] = (int) pow(i, j);
        }
      }
      sum = new int[n][401];
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 400; ++j) {
          for (int k = ai[i]; k <= bi[i]; ++k) {
            sum[i][j] = (int) add(sum[i][j], pow[k][j]);
          }
        }
      }
      state = new int[n][c + 1];
      for (int[] i : state) {
        Arrays.fill(i, -1);
      }
      long ans = go(n - 1, c);
      out.println(ans);
    }
    
    long go(int pos, int cnd) {
      if (pos < 0) {
        if (cnd == 0) {
          return 1L;
        }
        return 0L;
      }
      if (state[pos][cnd] != -1) {
        return state[pos][cnd];
      }
      long ans = 0L;
      for (int i = 0; i <= cnd; ++i) {
        ans = add(ans, mul(sum[pos][i], go(pos - 1, cnd - i)));
      }
      state[pos][cnd] = (int) ans;
      return ans;
    }
    
    long add(long a, long b) {
      long ans = (a + b) % ring;
      if (ans < 0L) {
        ans += ring;
      }
      return ans;
    }
    
    long mul(long a, long b) {
      return a * b % ring;
    }
    
    long pow(long a, long b) {
      if (a == 0L) {
        return 0L;
      }
      long ans = 1L;
      while (b != 0) {
        if ((b & 1) != 0) {
          ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>>= 1;
      }
      return ans;
    }
    
  }
    
      
  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream));
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
    
    public String nextLine() {
      try {
        return reader.readLine();
      } catch(IOException e) {
        throw new RuntimeException(e);
      }
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

    public boolean hasInput() {
      try {
        if (tokenizer != null && tokenizer.hasMoreTokens()) {
          return true;
        }
        reader.mark(1);
        int ch = reader.read();
        if (ch != -1) {
          reader.reset();
          return true;
        }
        return false;
      } catch(IOException e) {
        throw new RuntimeException(e);
      }
    }
    
  }
}