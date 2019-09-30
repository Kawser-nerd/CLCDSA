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
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }
  
  static class TaskA {    
    int n;
    int[] t, a;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      t = new int[n];
      a = new int[n];
      for (int i = 0; i < n; ++i) {
        t[i] = in.nextInt();
        a[i] = in.nextInt();
      }
      long tv = 1, av = 1;
      long total = tv + av;
      for (int i = 0; i < n; ++i) {
        if (tv <= t[i] && av > a[i]) {
          long mult = (long) av / a[i];
          if (av % a[i] != 0)
            ++mult;
          av = a[i] * mult;
          tv = t[i] * mult;
          continue;
        }
        if (tv > t[i] && av <= a[i]) {
          long mult = (long) tv / t[i];
          if (tv % t[i] != 0)
            ++mult;
          tv = t[i] * mult;
          av = a[i] * mult;
          continue;
        }
        if (tv > t[i] && av > a[i]) {
          long amult = (long) av / a[i];
          if (av % a[i] != 0)
            ++amult;
          long tmult = (long) tv / t[i];
          if (tv % t[i] != 0)
            ++tmult;
          long mult = Math.max(amult, tmult);
          tv = t[i] * mult;
          av = a[i] * mult;
          continue;
        }
        tv = t[i];
        av = a[i];
      }
      out.println(tv + av);
    }
    
    long gcd(long a, long b) {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
    
    long mcm(long a, long b) {
      return a / gcd(a, b) * b;
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