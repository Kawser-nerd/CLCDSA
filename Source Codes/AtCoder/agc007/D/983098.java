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
    int n, e, t;
    int[] x;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      e = in.nextInt();
      t = in.nextInt();
      x = new int[n + 1];
      for (int i = 1; i <= n; ++i)
        x[i] = in.nextInt();
      long[][] state = new long[3][n + 1];
      int ptr = 0;
      for (int i = 1; i <= n; ++i) {
        while (2 * (x[i] - x[ptr + 1]) > t)
          ++ptr;
        state[1][i] = ptr;
      }
      long min = Long.MAX_VALUE / 2;
      for (int i = 1; i <= n; ++i) {
        for (int j = (int) state[1][i - 1]; j < (int) state[1][i]; ++j)
          min = Math.min(min, state[0][j] - 2 * x[j + 1]);
        state[0][i] = Math.min(min + 2 * x[i], state[0][(int) state[1][i]] + t);
      }
      long ans = state[0][n] + e;
      out.println(ans);
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