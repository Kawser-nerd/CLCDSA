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
    final long ring = 9223372036854775783L;
    int n;
    int[][] c;
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      c = new int[n][4];
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < 4; ++j)
          c[i][j] = in.nextInt();
      int ptr = 0;
      Map<Long, Integer> table = new HashMap<Long, Integer>();
      for (int i = 0; i < n; ++i) {
        long mask = pack(c[i][3], c[i][2], c[i][1], c[i][0]);
        for (int j = 0; j < 4; ++j) {
          if (!table.containsKey(mask))
            table.put(mask, ptr++);
          mask = rotater(mask);
        }
      }
      int[] count = new int[ptr];
      for (int i = 0; i < n; ++i) {
        long mask = pack(c[i][3], c[i][2], c[i][1], c[i][0]);
        for (int j = 0; j < 4; ++j) {
          ++count[table.get(mask)];
          mask = rotater(mask);
        }
      }
      long acc = 0;
      boolean flag = false;
      List<Long> list = new ArrayList<Long>();
      Deque<Integer> queue1 = new ArrayDeque<Integer>();
      Deque<Integer> queue2 = new ArrayDeque<Integer>();
      Deque<Integer> queue3 = new ArrayDeque<Integer>();
      for (int i = 0; i < n; ++i) {
        long lmask = pack(c[i][3], c[i][2], c[i][1], c[i][0]);
        long bk1 = lmask;
        for (int j = 0; j < 4; ++j) {
          int idx = table.get(bk1);
          queue1.add(idx);
          --count[idx];
          bk1 = rotater(bk1);
        }
        for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < n; ++k)
            if (k != i) {
              long rmask = pack(c[k][3], c[k][2], c[k][1], c[k][0]);
              long bk2 = rmask;
              for (int p = 0; p < 4; ++p) {
                int idx = table.get(bk2);
                queue2.add(idx);
                --count[idx];
                bk2 = rotater(bk2);
              }
              for (int p = 0; p < 4; ++p) {
                long prod = 1;
                long rrmask = rmask;
                long llmask = lmask;
                boolean okay = true;
                for (int q = 0; q < 4; ++q) {
                  long mask = pack(extract(llmask, 16, 16), extract(rrmask, 0, 16), extract(rrmask, 16, 16), extract(llmask, 0, 16));
                  if (table.containsKey(mask)) {
                    prod *= count[table.get(mask)];
                    long bk3 = mask;
                    for (int r = 0; r < 4; ++r) {
                      int idx = table.get(bk3);
                      queue3.add(idx);
                      --count[idx];
                      bk3 = rotater(bk3);
                    }
                  } else
                    okay = false;
                  llmask = rotater(llmask);
                  rrmask = rotatel(rrmask);
                }
                if (okay) {
                  acc += prod;
                  if (acc > Long.MAX_VALUE / 48 && acc % 24 == 0) {
                    list.add(acc);
                    acc = 0;
                  }
                }
                while (!queue3.isEmpty()) {
                  int idx = queue3.poll();
                  ++count[idx];
                }
                rmask = rotater(rmask);
              }
              while (!queue2.isEmpty()) {
                int idx = queue2.poll();
                ++count[idx];
              }
            }
          lmask = rotater(lmask);
        }
        while (!queue1.isEmpty()) {
          int idx = queue1.poll();
          ++count[idx];
        }
      }
      long ans = 0;
      for (long i : list)
        ans += i / 24;
      ans += acc / 24;
      out.println(ans);
    }
    
    long pack(long a, long b, long c, long d) {
      return a << 48 | b << 32 | c << 16 | d;
    }
    
    long extract(long a, int offset, int size) {
      return a >>> offset & (1L << size) - 1;
    }
    
    long rotater(long a) {
      return a << 16 | a >>> 48;
    }
    
    long rotatel(long a) {
      return a >>> 16 | a << 48;
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