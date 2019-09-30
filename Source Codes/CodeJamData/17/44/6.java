import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {
    	
    	int Col = cin.nextInt();
    	int Row = cin.nextInt();
    	int M = cin.nextInt();
    	
    	String map[] = new String[Row];
    	for( int i = 0 ; i < Row; ++i ) {
    		map[i] = cin.next();
    	}

      System.out.println("Case #" + C + ": " + solve(Col, Row, M, map));

    }

    cin.close();

  }
  
  private int dx[] = { 1, 0, -1, 0 };
  private int dy[] = { 0, 1, 0, -1 };
  
  private void check(int Sindex, int Scount, int Tcount, int y, int x, int Col, int Row, String map[], int M, int graph[][], int weight[][], boolean Tsee[][][]) {
	  int score[] = new int[Tcount];
	  for(int i = 0; i < Tcount; ++i ) {
		  score[i] = -1;
	  }
	  boolean vis[][] = new boolean[Row][Col];
	  int queue[][] = new int[Row * Col][];
	  
	  int p = 0;
	  queue[p++] = new int[] { y, x, 0 };
	  vis[y][x] = true;
	  
	  for( int i = 0; i < p; ++i ) {
		  int cur[] = queue[i];
		  for(int j = 0; j < Tcount; ++j ) {
			 if( Tsee[j][ cur[0] ][ cur[1] ] ) {
				 if( score[j] == -1 ) { score[j] = cur[2]; }
				 else { score[j] = Math.min(score[j], cur[2]); }
			 }
		  }
		  // System.err.println(cur[0] + " " + cur[1] + " " + cur[2]);
		  if( cur[2] == M ) { continue; }
		  for(int j = 0; j < 4; ++j ) {
			 int Y = cur[0] + dy[j];
			 int X = cur[1] + dx[j];
			 if( Y < 0 || Y >= Row || X < 0 || X >= Col || vis[Y][X] || map[Y].charAt(X) == '#' ) { continue; }
			 queue[p++] = new int[] { Y, X, cur[2] + 1 };
			 vis[Y][X] = true;
		  }
	  }

	  for(int i = 0; i < Tcount; ++i ) {
		  // has edge;
		  if( score[i] >= 0 ) {
			  graph[Sindex][Scount + i] = 1;
			  weight[Sindex][Scount + i] = score[i];
			  // System.err.println(Sindex + " => " + (Scount + i));
		  }
	  }
  }
  
  private String solve(int Col, int Row, int M, String map[]) {
	  int Tcount = 0;
	  for(int i = 0; i < Row; ++i ) {
		  for(int j = 0; j < Col; ++j ) {
			  if( map[i].charAt(j) == 'T' ) { ++Tcount; }
		  }
	  }
	  boolean Tsee[][][] = new boolean[Tcount][Row][Col];
	  int Tindex = 0;
	  for(int i = 0; i < Row; ++i ) {
		  for(int j = 0; j < Col; ++j ) {
			  if( map[i].charAt(j) != 'T' ) { continue; }
			  for(int k = i + 1; k < Row; ++k ) {
				  if( map[k].charAt(j) == '#' ) { break; }
				  Tsee[Tindex][k][j] = true;
			  }
			  for(int k = i - 1; k >= 0; --k ) {
				  if( map[k].charAt(j) == '#' ) { break; }
				  Tsee[Tindex][k][j] = true;
			  }
			  for(int k = j + 1; k < Col; ++k ) {
				  if( map[i].charAt(k) == '#' ) { break; }
				  Tsee[Tindex][i][k] = true;
			  }
			  for(int k = j - 1; k >= 0; --k ) {
				  if( map[i].charAt(k) == '#' ) { break; }
				  Tsee[Tindex][i][k] = true;
			  }
			  ++Tindex;
		  }
	  }
	  int Scount = 0;
	  for( int i = 0; i < Row; ++i ) {
		  for(int j = 0; j < Col; ++j ) {
			  if( map[i].charAt(j) == 'S' ) { ++Scount; }
		  }
	  }
	  int Source = Tcount + Scount;
	  int Target = Source + 1;
	  int Nodes = Target + 1;
	  MincostFlow flow = new MincostFlow();
	  int used[][] = new int[Nodes][Nodes];
	  int weight[][] = new int[Nodes][Nodes];
	  int graph[][] = new int[Nodes][Nodes];
	  for(int i = 0; i < Tcount; ++i ) {
		  graph[Scount + i][Target] = 1;
	  }
	  for(int i = 0; i < Scount; ++i ) {
		  graph[Source][i] = 1;
	  }
	  int Sindex = 0;
	  for( int i = 0; i < Row; ++i ) {
		  for(int j = 0; j < Col; ++j ) {
			  if( map[i].charAt(j) == 'S' ) {
				  check(Sindex, Scount, Tcount, i, j, Col, Row, map, M, graph, weight, Tsee);
				  ++Sindex;
			  }
		  }
	  }

	  int result[] = flow.minCostFlow(Source, Target, Nodes, graph, used, weight);
	  int ans = result[1];
	  int P = 0;
	  int can[][] = new int[ans][];
	  boolean hit[] = new boolean[Tcount];
	  boolean vis[] = new boolean[ans];
	  for( int i = 0; i < Scount; ++ i ) {
		  for( int j = 0; j < Tcount; ++j ) {
			  if( used[i][j + Scount] == 1 ) {
				  can[P++] = new int[] { i, j };
			  }
		  }
	  }
	  String answer = "" + ans;
	  Main:
	  for( int i = 0; i < ans; ++i ) {
		  answer += "\n";
		  for( int j = 0; j < ans; ++j ) {
			  if( vis[j] ) { continue; }
			  int aa[] = can[j];
			  int S = aa[0];
			  int T = aa[1] + Scount;
			  boolean ok = true;
			  for( int k = 0; k < Tcount; ++k ) {
				  if( graph[S][k + Scount] == 0 ) { continue; }
				  if( weight[S][k + Scount] < weight[S][T] && hit[k] == false ) {
					  ok = false;
					  break;
				  }
			  }
			  if( ok ) {
				  vis[j] = true;
				  hit[aa[1]] = true;
				  answer += (aa[0] + 1) + " " + (aa[1] + 1);
				  continue Main;
			  }
		  }
	  }
	  return answer;
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

