import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int N = cin.nextInt();
      String a[] = new String[N];
      String b[] = new String[N];

      for(int i=0; i<N; ++i) {
        a[i] = cin.next();
        b[i] = cin.next();
      }

      Map<String, Integer> L = new HashMap<String, Integer>();
      Map<String, Integer> R = new HashMap<String, Integer>();

      int K = 0;

      for( String node : a ) {
        if( L.containsKey(node) ) { continue; }
        L.put(node, K++);
      }

      int base = K;

      for( String node : b ) {
        if( R.containsKey(node) ) { continue; }
        R.put(node, K++);
      }

      int S = K++;
      int Z = K++;

      int graph[][] = new int[K][K];
      for(int i=0; i<base; ++i) {
        graph[S][i] = 1;
      }

      for(int i=base; i<S; ++i) {
        graph[i][Z] = 1;
      }

      for(int i=0; i<N; ++i) {
        graph[ L.get(a[i]) ][ R.get(b[i]) ] = 1;
      }

      MincostFlow flow = new MincostFlow();
      int used[][] = new int[K][K];
      int res[] = flow.minCostFlow(S, Z, K, graph, used, new int[K][K]);

      int ans = res[1];
      ans += (base - ans) + (S - base - ans);
      ans = N - ans;

      System.out.println("Case #" + C + ": " + ans);

    }

  }

  class MincostFlow {

  private int INF = 1000000;

  int[] minCostFlow(int S, int T, int n, int graph[][], int used[][], int weight[][]) {
    return minCostFlow(S, T, n, graph, used, weight, INF);
  }

  // S -> T;
  // req : expected flow;
  // @return minimal cost (+ total flow : if total flow is unknown (req == INF));
  // @return null if flow < req (req != INF);
  int[] minCostFlow(int S, int T, int n, int graph[][], int used[][], int weight[][], int req) {

    boolean full = (req == INF);

    int sum = 0;
    int potential[] = new int[n];

    while( req > 0 ) {

      int res[] = flow(S, T, n, graph, used, weight, potential);
      if( res == null ) {
        return full ? new int[] { sum, INF - req } : null;
      }

      int flow = Math.min(res[0], req);
      sum += flow * res[1];
      req -= flow;

    }

    return new int[] { sum };

  }

  int[] flow(int S, int T, int n, int graph[][], int used[][], int weight[][], int potential[]) {

    int minValue[] = new int[n];
    for(int i=0; i<n; ++i) { minValue[i] = -1; }
    minValue[S] = 0;

    boolean check[] = new boolean[n];

    java.util.PriorityQueue<State> queue = new java.util.PriorityQueue<State>();
    queue.add(new State(S, potential[S], null, INF));

    State end = null;

    while( !queue.isEmpty() ) {

      State s = queue.poll();
      if( check[s.pos] ) { continue; }
      check[s.pos] = true;

      // flow ok;
      if( s.pos == T ) { end = s; }

      for(int i=0; i<n; ++i) {
        int gain = graph[s.pos][i] - used[s.pos][i];
        if( used[i][s.pos] > 0 ) {
          int next = s.score - weight[i][s.pos] + potential[s.pos] - potential[i];
          if( minValue[i] == -1 || minValue[i] > next ) {
            minValue[i] = next;
            queue.add(new State(i, next, s, Math.min(s.flow, used[i][s.pos])));
          }
        }
        else if( gain > 0 ) {
          int next = s.score + weight[s.pos][i] + potential[s.pos] - potential[i];
          if( minValue[i] == -1 || minValue[i] > next ) {
            minValue[i] = next;
            queue.add(new State(i, next, s, Math.min(s.flow, gain)));
          }
        }
      }

    }

    if( end == null ) { return null; }

    State s = end;
    int gain = s.flow;
    int score = s.score + potential[s.pos];

    // push actual flow;
    while( true ) {
      State t = s.prev;
      if( t == null ) { break; }
      if( used[s.pos][t.pos] >= gain ) {
        used[s.pos][t.pos] -= gain;
      }
      else if( graph[t.pos][s.pos] >= used[t.pos][s.pos] + gain ) {
        used[t.pos][s.pos] += gain;
      }
      s = t;
    }

    // update potential;
    for(int i=0; i<n; ++i) {
      if( minValue[i] == -1 ) { continue; }
      potential[i] += minValue[i];
    }

    return new int[] { gain, score };

  }

  class State implements Comparable<State> {

    int pos;
    int score;
    State prev;
    int flow;

    State(int pos, int score, State prev, int flow) {
      this.pos = pos;
      this.score = score;
      this.prev = prev;
      this.flow = flow;
    }

    public int compareTo(State s) {
      return score - s.score;
    }

  }

}


}
