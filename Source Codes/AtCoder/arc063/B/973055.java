// -*- coding: utf-8 -*-
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
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }
  
  static class TaskD {    
    int n, t;
    int[] a;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      t = in.nextInt();
      a = new int[n];
      int[][] table = new int[n][17];
      for (int i = 0; i < n; ++i)
        a[i] = in.nextInt();
      pre(table, a, n);
      int max = 0;
      for (int i = 0; i < n - 1; ++i) {
        int idx = rmq(table, a, i + 1, n - 1);
        max = Math.max(max, a[idx] - a[i]);
      }
      int ans = 0;
      for (int i = 0; i < n - 1; ++i) {
        int idx = rmq(table, a, i + 1, n - 1);
        if (a[idx] - a[i] == max)
          ++ans;
      }
      out.println(ans);
    }
    
    void pre(int[][] m, int[] o, int n) {
      for (int i = 0; i < n; ++i)
        m[i][0] = i;
      for (int j = 1; 1 << j - 1 < n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
          if (o[m[i][j - 1]] > o[m[i + (1 << (j - 1))][j - 1]])
            m[i][j] = m[i][j - 1];
          else
            m[i][j] = m[i + (1 << (j - 1))][j - 1];
    }
      
    int rmq(int[][] m, int[] o, int a, int b) {
      int d = Integer.highestOneBit(b - a + 1);
      int c = Integer.bitCount(d - 1);
      if (o[m[a][c]] > o[m[b - d + 1][c]])
        return m[a][c];
      else
        return m[b - d + 1][c];
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