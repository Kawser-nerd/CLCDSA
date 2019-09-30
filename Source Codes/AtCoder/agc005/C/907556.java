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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }
  
  static class TaskC {    
    int n;
    int[] a;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      a = new int[n];
      int min = Integer.MAX_VALUE / 2, max = 0;
      int[] freq = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
        min = Math.min(min, a[i]);
        max = Math.max(max, a[i]);
        ++freq[a[i]];
      }
      if (freq[min] > 2) {
        out.println("Impossible");
        return;
      }
      for (int i = max; i > min; --i)
        if (freq[i] < 2) {
          out.println("Impossible");
          return;
        }
      if (freq[min] == 1 && max % 2 != 0 || freq[min] == 2 && max % 2 == 0) {
        out.println("Impossible");
        return;
      }
      out.println("Possible");
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