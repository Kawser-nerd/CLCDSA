import java.io.*;
import java.util.*;

public class technobabble {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "C-large";
  
  public static HashMap<String, Integer> mp1, mp2;
  public static int sid1, sid2;
  public static int getId1(String s) {
    if (mp1.containsKey(s)) return mp1.get(s);
    mp1.put(s, sid1++);
    return sid1-1;
  }
  public static int getId2(String s) {
    if (mp2.containsKey(s)) return mp2.get(s);
    mp2.put(s, sid2++);
    return sid2-1;
  }

  private static void main2() throws IOException {
    int n = in.nextInt();
    mp1 = new HashMap<>();
    mp2 = new HashMap<>();
    sid1 = 0;
    sid2 = 0;
    init(2*n+2, 2*(n+n+n));
    for (int i = 0; i < n; i++) {
      int a1 = getId1(in.next()), a2 = getId2(in.next());
      add_edge(a1, n+a2, 1);
    }
    for (int i = 0; i < sid1; i++) add_edge(N-1,i,1);
    for (int i = 0; i < sid2; i++) add_edge(i+n,N-2,1);
    out.println(n-(sid1+sid2-dinic(N-1,N-2)));
  }
  public static int N;
  public static int INF = 1 << 29;
  public static int[] eadj, eprev, elast;
  public static int eidx;
  private static int[] flow, capa, now;

  public static void init(int _N, int M) {
    N = _N;
    eadj = new int[M];
    eprev = new int[M];
    elast = new int[N];
    flow = new int[M];
    capa = new int[M];
    now = new int[N];
    level = new int[N];
    eidx = 0;
    Arrays.fill(elast, -1);
  }

  private static void add_edge(int a, int b, int c) {
    eadj[eidx] = b; flow[eidx] = 0; capa[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; flow[eidx] = c; capa[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  private static int dinic(int source, int sink) {
    int res, flow = 0;
    while (bfs(source, sink)) { // see if there is an augmenting path
      System.arraycopy(elast, 0, now, 0, N);
      while ((res = dfs(source, INF, sink)) > 0)
        // push all possible flow through
        flow += res;
    }
    return flow;
  }

  private static int[] level;

  private static boolean bfs(int source, int sink) {
    Arrays.fill(level, -1);
    int front = 0, back = 0;
    int[] queue = new int[N];
    level[source] = 0;
    queue[back++] = source;
    while (front < back && level[sink] == -1) {
      int node = queue[front++];
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        int to = eadj[e];
        if (level[to] == -1 && flow[e] < capa[e]) {
          level[to] = level[node] + 1;
          queue[back++] = to;
        }
      }
    }

    return level[sink] != -1;
  }

  private static int dfs(int cur, int curflow, int goal) {
    if (cur == goal)
      return curflow;

    for (int e = now[cur]; e != -1; now[cur] = e = eprev[e]) {
      if (level[eadj[e]] > level[cur] && flow[e] < capa[e]) {
        int res = dfs(eadj[e], Math.min(curflow, capa[e] - flow[e]), goal);
        if (res > 0) {
          flow[e] += res;
          flow[e ^ 1] -= res;
          return res;
        }
      }
    }
    return 0;
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
      out.print("Case #" + test + ": ");
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
