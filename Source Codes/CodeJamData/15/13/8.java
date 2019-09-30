import java.io.*;
import java.util.*;

public class logging {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "C-large";
  
  static class Point implements Comparable<Point> {
    public long x, y;
    public int idx;
    public double angle;
    
    public Point (long x, long y) {
      this.x = x;
      this.y = y;
    }
    
    public Point (long x, long y, int idx) {
      this.x = x;
      this.y = y;
      this.idx = idx;
    }
    
    public int compareTo(Point other) {
      return (int)Math.signum(angle - other.angle);
    }
    
    public String toString() {
      return x+" "+y;
    }
  }
  
  public static long cross(Point p, Point q, Point r) {
    return (r.y - p.y) * (q.x - p.x) - (q.y - p.y) * (r.x - p.x);
  }
  
  public static long dist (Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }

  private static void main2() throws IOException {
    int N = in.nextInt();
    Point[] p = new Point[N];
    Point[] pc = new Point[2*N];
    for (int i = 0; i < N; i++) {
      int x = in.nextInt(), y = in.nextInt();
      pc[i] = new Point(x, y, i);
      pc[i+N] = new Point(x, y, i);
      p[i] = new Point(x, y);
    }
    
    int[] seen = new int[N];
    double[] prev = new double[N];
    int gen = 0;
    for (int i = 0; i < N; i++) {
      ++gen;
      for (int j = 0; j < 2 * N; j++) {
        if (pc[j].idx == i) pc[j].angle = 1 << 29;
        else {
          if (seen[pc[j].idx] == gen) {
            pc[j].angle = prev[pc[j].idx] + 2 * Math.PI;
          } else {
            seen[pc[j].idx]= gen; 
            prev[pc[j].idx] = pc[j].angle = Math.atan2(pc[j].y-p[i].y,pc[j].x-p[i].x); 
          }
        }
      }
      Arrays.sort(pc);
      
      int t2 = 0;
      int min = N-1;
      for (int t1 = 0; t1 < N-1; t1++) {
        t2 = Math.max(t2, t1);
        while (t2+1 < t1+N-1 && cross(pc[t1], p[i], pc[t2+1]) < 0) {t2++;}
        min = Math.min(t2 - t1, min);
      }
      
      out.println(min);
    }
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      System.out.println(test);
      out.println("Case #" + test + ":");
      main2();
    }

    out.close();
    System.exit(0);
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
  }
}
