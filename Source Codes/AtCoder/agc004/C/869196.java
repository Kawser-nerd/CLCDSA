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
    int testCase = 1;
    solver.solve(1, in, out);
    out.close();
  }
  
  static class TaskC {
    long h, w;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      h = in.nextInt();
      w = in.nextInt();
      char[][] superpost = new char[(int) h][];
      for (int i = 0; i < h; ++i)
        superpost[i] = in.next().toCharArray();
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
          if (i % 2 == 0 && j < w - 1 || j == 0 || superpost[i][j] == '#')
            out.print('#');
          else
            out.print('.');
        out.println();
      }
      out.println();
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
          if (i % 2 == 1 && j > 0 || j == w - 1 || superpost[i][j] == '#')
            out.print('#');
          else
            out.print('.');
          out.println();
      }
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