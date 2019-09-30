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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }
  
  static class TaskE {    
    int n, l, q, xi, ai, bi;
    int[] hotelsPos;
    int[][] right, left;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      hotelsPos = new int[n];
      for (int i = 0; i < n; ++i) {
        hotelsPos[i] = in.nextInt();
      }
      l = in.nextInt();
      q = in.nextInt();
      pre();
      for (int i = 0; i < q; ++i) {
        ai = in.nextInt();
        bi = in.nextInt();
        --ai;
        --bi;
        out.println(query(ai, bi));
      }
    }
    
    void pre() {
      right = new int[17][n];
      left = new int[17][n];
      right[0][n - 1] = n;
      left[0][0] = -1;
      for (int i = 0; i < n - 1; ++i) {
        right[0][i] = Arrays.binarySearch(hotelsPos, hotelsPos[i] + l);
        if (right[0][i] < 0) {
          right[0][i] = ~right[0][i]; 
          --right[0][i];
        }
      }
      for (int i = 1; i < n; ++i) {
        left[0][i] = Arrays.binarySearch(hotelsPos, hotelsPos[i] - l);
        if (left[0][i] < 0) {
          left[0][i] = ~left[0][i]; 
        }
      }
      for (int i = 1; i < 17; ++i) { // f^(2^m)[i] = f^(2^(m - 1))[f^(2^(m - 1))[i]] -- O(n log(2^(max m))) = O(nm)
        for (int j = 0; j < n; ++j) {
          if (right[i - 1][j] < n) {
            right[i][j] = right[i - 1][right[i - 1][j]];
          } else {
            right[i][j] = n;
          }
          if (left[i - 1][j] > -1) {
            left[i][j] = left[i - 1][left[i - 1][j]];
          } else {
            left[i][j] = -1;
          }
        }
      }
    }
    
    int query(int a, int b) {
      int ans = 0;
      if (a < b) {
        for (int i = 16; i >= 0; --i) {
          if (right[i][a] < b) {
            a = right[i][a];
            ans += 1 << i;
          }
        }
      } else {
        for (int i = 16; i >= 0; --i) {
          if (left[i][a] > b) {
            a = left[i][a];
            ans += 1 << i;
          }
        }
      }
      ++ans;
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