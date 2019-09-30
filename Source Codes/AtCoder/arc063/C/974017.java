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
    int n, k;
    int[] a, b, v, p;
    
    int[] assigned;
    List<Integer>[] graph;
    Queue<PairII> queue;
    
    class PairII implements Comparable<PairII> {
      int a, b;
      
      PairII(int na, int nb) {
        a = na;
        b = nb;
      }
      
      public int compareTo(PairII other) {
        if (this.a != other.a)
          return this.a - other.a;
        return this.b - other.b;
      }
    }
    
    void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      a = new int[n];
      b = new int[n];
      for (int i = 0; i < n - 1; ++i) {
        a[i] = in.nextInt();
        b[i] = in.nextInt();
      }
      k = in.nextInt();
      v = new int[k];
      p = new int[k];
      for (int i = 0; i < k; ++i) {
        v[i] = in.nextInt();
        p[i] = in.nextInt();
      }
      graph = (ArrayList<Integer>[]) new ArrayList[n + 1];
      for (int i = 0; i <= n; ++i)
        graph[i] = new ArrayList<>();
      for (int i = 0; i < n; ++i) {
        graph[a[i]].add(b[i]);
        graph[b[i]].add(a[i]);
      }
      assigned = new int[n + 1];
      Arrays.fill(assigned, -1);
      queue = new PriorityQueue<>();
      for (int i = 0; i < k; ++i) {
        assigned[v[i]] = p[i];
        queue.add(new PairII(p[i], v[i]));
      }
      while (!queue.isEmpty()) {
        PairII x = queue.poll();
        System.err.println(x.a + " " + x.b);
        int uu = x.b;
        int uv = x.a;
        for (int vv : graph[uu]) {
          if (assigned[vv] != -1 && Math.abs(assigned[vv] - assigned[uu]) != 1) {
            out.println("No");
            return;
          }
          if (assigned[vv] == -1) {
            assigned[vv] = assigned[uu] + 1;
            queue.add(new PairII(assigned[vv], vv));
          }
        }
      }
      out.println("Yes");
      for (int i = 1; i <= n; ++i)
        out.println(assigned[i]);
      
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.