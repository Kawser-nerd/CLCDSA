import java.io.*;
import java.util.*;

public class _2017Round1AqC {

  public static void main(String args[]) throws Exception {
    InputReader in;
    PrintWriter w;
    boolean online = true;
    String fileName = "C-small-attempt1";

    if (online) {
      in = new InputReader(new FileInputStream(new File(fileName + ".in")));
      w = new PrintWriter(new FileWriter(fileName + "out.txt"));
    } else {
      in = new InputReader(System.in);
      w = new PrintWriter(System.out);
    }

    int max = 100;
    int T = in.nextInt();
    
    int vis[][][][] = new int[max + 1][max + 1][max + 1][max + 1];
    int steps[][][][] = new int[max + 1][max + 1][max + 1][max + 1];

    for (int t = 1; t <= T; t++) {
      
      int Hd = in.nextInt();
      int Ad = in.nextInt();
      int Hk = in.nextInt();
      int Ak = in.nextInt();
      int b = in.nextInt();
      int d = in.nextInt();
      
      Queue<Integer> q = new ArrayDeque<Integer>();
      q.add(Hd);
      q.add(Ad);
      q.add(Hk);
      q.add(Ak);
      
      vis[Hd][Ad][Hk][Ak] = t;
      steps[Hd][Ad][Hk][Ak] = 0;
      
      int ans = -1;
      
      while (q.size() > 0) {
        int hd = q.remove();
        int ad = q.remove();
        int hk = q.remove();
        int ak = q.remove();
        int ct = steps[hd][ad][hk][ak];
        
        //System.out.println(hd + " " + ad + " " + hk + " " + ak + " " + ct);
        
        // ATTACK
        if (ad >= hk) {
          ans = ct+ 1;
          break;
        } else {
          if (hd > ak && vis[hd - ak][ad][hk - ad][ak] != t) {
            vis[hd - ak][ad][hk - ad][ak] = t;
            steps[hd - ak][ad][hk - ad][ak] = ct + 1;
            q.add(hd - ak);
            q.add(ad);
            q.add(hk - ad);
            q.add(ak);
          }
        }
        
        // BUFF
        if (hd > ak && vis[hd - ak][Math.min(hk, ad + b)][hk][ak] != t) {
          vis[hd - ak][Math.min(hk, ad + b)][hk][ak] = t;
          steps[hd - ak][Math.min(hk, ad + b)][hk][ak] = ct + 1;
          q.add(hd - ak);
          q.add(Math.min(hk, ad + b));
          q.add(hk);
          q.add(ak);
        }
        
        // CURE
        if (Hd > ak && vis[Hd - ak][ad][hk][ak] != t) {
          vis[Hd - ak][ad][hk][ak] = t;
          steps[Hd - ak][ad][hk][ak] = ct + 1;
          q.add(Hd - ak);
          q.add(ad);
          q.add(hk);
          q.add(ak);
        }
        
        // DEBUFF
        if (hd > ak - d && vis[hd - Math.max(0, ak - d)][ad][hk][Math.max(0, ak - d)] != t) {
          vis[hd - Math.max(0, ak - d)][ad][hk][Math.max(0, ak - d)] = t;
          steps[hd - Math.max(0, ak - d)][ad][hk][Math.max(0, ak - d)] = ct + 1;
          q.add(hd - Math.max(0, ak - d));
          q.add(ad);
          q.add(hk);
          q.add(Math.max(0, ak - d));
        }
      }
      
      w.println("Case #" + t + ": " + (ans == -1 ? "IMPOSSIBLE" : ans));
    }

    w.close();
  }
  
  static class InputReader {

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, snumChars;

    public InputReader(InputStream st) {
      this.stream = st;
    }

    public int read() {
      if (snumChars == -1)
        throw new InputMismatchException();
      if (curChar >= snumChars) {
        curChar = 0;
        try {
          snumChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (snumChars <= 0)
          return -1;
      }
      return buf[curChar++];
    }

    public int nextInt() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public long nextLong() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public int[] nextIntArray(int n) {
      int a[] = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = nextInt();
      }
      return a;
    }

    public String readString() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public String nextLine() {
      int c = read();
      while (isSpaceChar(c))
        c = read();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isEndOfLine(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
      return c == '\n' || c == '\r' || c == -1;
    }

  }

}
