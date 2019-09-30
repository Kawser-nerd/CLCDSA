import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String arg[]) throws IOException { new Main().bw.close(); }

  BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  StringTokenizer st = null;
  String nxttok() { 
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch(Exception e) { return "";}
    return st.nextToken();
  }

  int nxtint() { return  Integer.parseInt(nxttok()); }
  long nxtlong() { return Long.parseLong(nxttok()); }

  int maxm = 5050;
  int inf = 101010101;
  int n;
  ArrayList<Integer> gr[];
  int a[];
  int dp[][];

  Main() throws IOException {
    n = nxtint();
    gr = new ArrayList[n];
    gr[0] = new ArrayList<Integer>();
    for (int i = 0; ++i < n; ) {
      int u = nxtint() - 1;
      //System.err.println(u);
      gr[u].add(i);
      gr[i] = new ArrayList<Integer>();
    }
    a = new int[n];
    for (int i = -1; ++i < n; ) a[i] = nxtint();
    dp = new int[n][2];

    for (int u = n; u-- > 0; ) {
      int min0[][] = new int[maxm][2];
      int min1[][] = new int[maxm][2];

      for (int i = 0; ++i < maxm; ) 
          min0[i][1] = min1[i][1] = inf;

      int s = 0;
      for (int v : gr[u]) {
        for (int i = -1; ++i < maxm; ) min0[i][s] = min1[i][s] = inf;
        for (int i = 0; i <= 1; ++i) {
          int t[] = new int[2];
          t[i] = a[v];
          t[i ^ 1] = dp[v][i];
          
          for (int f = maxm; f-- > 0; ) {
            if ((long)f + t[0] < maxm && min0[f][s ^ 1] != inf)
              min0[f + t[0]][s] = Math.min(min0[f + t[0]][s], min0[f][s ^ 1] + t[1]);
            if ((long)f + t[1] < maxm && min1[f][s ^ 1] != inf)
              min1[f + t[1]][s] = Math.min(min1[f + t[1]][s], min1[f][s ^ 1] + t[0]);
          }
        }
        s ^= 1;
      }
      
      s ^= 1;
      dp[u][0] = dp[u][1] = inf;
      for (int i = 0; i <= a[u]; ++i) {
        dp[u][0] = Math.min(dp[u][0], min0[i][s]);
        dp[u][1] = Math.min(dp[u][1], min1[i][s]);
      }
      if (dp[u][0] == inf && dp[u][1] == inf) {
        bw.write("IMPOSSIBLE");
        return;
      }
    }
    bw.write("POSSIBLE");
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.