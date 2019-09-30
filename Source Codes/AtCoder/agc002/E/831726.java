/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 07 Aug 2016 12:44:17 AM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int[] numbers = new int[n];
      for (int i = 0; i < n; i++) {
        numbers[i] = in.nextInt();
      }
      Arrays.sort(numbers);
      for (int i = 0, j = n - 1; i < j; i++, j--) {
        int tmp = numbers[i]; numbers[i] = numbers[j]; numbers[j] = tmp;
      }
      int now = 0;
      for (int i = 0; i < n; i++) {
        if (numbers[i] >= now + 1) now++;
        else {
          break;
        }
      }
      int a = (numbers[now - 1] - now);
      int b = 0;
      int idx = now;
      while (idx < n && numbers[idx] == now) {
        b++; idx++;
      }
      b--; a++;
      if ((a & 1) == 0 || (b & 1) == 0) {
        out.println("First");
      }
      else {
        out.println("Second");
      }
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