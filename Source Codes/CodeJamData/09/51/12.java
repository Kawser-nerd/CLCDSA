import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class A{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		int T = INT(in.readLine());
		for(int i = 1; i <= T; i++){
			System.out.printf("Case #%d: ",i);
			new A().go();
		}
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		ST();
		mx = INT(st.nextToken());
		my = INT(st.nextToken());
		nogo = new boolean[mx][my];
		int boxes = 0;
		char[][] map = new char[mx][];
		for(int i = 0; i < mx; i++){
			map[i] = in.readLine().toCharArray();
			for(int j = 0; j < my; j++) if(map[i][j] == 'o' || map[i][j] == 'w') boxes++;
		}
		int[] sx = new int[boxes];
		int[] sy = new int[boxes];
		int sc = 0;
		int[] gx = new int[boxes];
		int[] gy = new int[boxes];
		int gc = 0;
		for(int i = 0; i < mx; i++){
			for(int j = 0; j < my; j++){
				char c = map[i][j];
				if(c == '#') nogo[i][j] = true;
				if(c == 'x' || c == 'w'){
					gx[gc] = i;
					gy[gc++] = j;
				}
				if(c == 'o' || c == 'w'){
					sx[sc] = i;
					sy[sc++] = j;
				}
			}
		}
		LinkedList<State> que = new LinkedList();
		State start = new State();
		start.xs = sx;
		start.ys = sy;
		State end = new State();
		end.xs = gx;
		end.ys = gy;
		que.add(start);
		HashSet<State> seen = new HashSet();
		seen.add(start);
		while(que.size() > 0){
			State s = que.removeFirst();
			if(s.equals(end)){
				System.out.println(s.c);
				return;
			}
			for(State ss: s.getMoves()){
				if(seen.add(ss)) que.add(ss);
			}
		}
		System.out.println(-1);
	}
	int[] dx = {-1,1,0,0};
	int[] dy = {0,0,-1,1};
	boolean[][] nogo;
	int mx, my;
	class State{
	   	int[] xs, ys;
	   	int c;

	   	List<State> getMoves(){
			List<State> ret = new ArrayList();
			boolean connected = isConnected();
			for(int i = 0; i < xs.length; i++){
				for(int j = 0; j < 4; j++){
		//			System.out.println("Testing from "+xs[i]+","+ys[i]+": "+(xs[i]+dx[j])+", "+(ys[i]+dy[j]));
					if(empty(xs[i]+dx[j], ys[i]+dy[j]) && empty(xs[i]-dx[j], ys[i]-dy[j])){
						State cand = getNewState(i, xs[i]+dx[j], ys[i]+dy[j]);
						if(!connected && !cand.isConnected()) continue;
						ret.add(cand);
					}
				}
			}
	//		System.out.println(this+" "+ret.size());
			return ret;
		}
		State getNewState(int i, int x, int y){
			State ret = new State();
			ret.xs = xs.clone();
			ret.ys = ys.clone();
			ret.xs[i] = x;
			ret.ys[i] = y;
			ret.normalize();
			ret.c = c+1;
			return ret;
		}

		public int hashCode(){
			int ret = 0;
			for(int i = 0; i < xs.length; i++){
				ret += xs[i] + ys[i]*17;
				ret *= 13;
			}
			return ret;
		}
		public boolean equals(Object o){
			State s = (State)o;
			for(int i = 0; i < xs.length; i++){
				if(s.xs[i] != xs[i] || s.ys[i] != ys[i]) return false;
			}
			return true;
		}
		void normalize(){
			for(int i = 0; i < xs.length; i++){
				for(int j = i+1; j < xs.length; j++){
					if(xs[i] > xs[j] || (xs[i] == xs[j] && ys[i] > ys[j])){
						int tmp = xs[i];
						xs[i] = xs[j];
						xs[j] = tmp;
						tmp = ys[i];
						ys[i] = ys[j];
						ys[j] = tmp;
					}
				}
			}
		}
		boolean isConnected(){
			seen = new boolean[xs.length];
			boolean ret = dfs(0) == xs.length;
			//System.out.println(Arrays.toString(xs)+" "+Arrays.toString(ys)+": "+ret);
			return ret;
		}
		boolean[] seen;
		int dfs(int at){
			if(seen[at]) return 0;
			seen[at] = true;
			int ret = 1;
			for(int i = 0; i < xs.length; i++){
				if(abs(xs[i] - xs[at]) + abs(ys[i]-ys[at]) == 1) ret += dfs(i);
			}
			return ret;
		}

		boolean empty(int x, int y){
	//		System.out.println(x+" "+y+": ("+mx+","+my+")");
			if(x < 0 || y < 0 || x >= mx || y >= my) return false;
	//		System.out.println(1);
			if(nogo[x][y]) return false;
	//		System.out.println(2);
			for(int i = 0; i < xs.length; i++){
				if(xs[i] == x && ys[i] == y) return false;
	//			System.out.println(3+"...");
			}
	//		System.out.println(4);
			return true;
		}
	}
}

