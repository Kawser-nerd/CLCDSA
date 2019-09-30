import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class B{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		new B().go();
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		int T = INT(in.readLine());
		for(int t = 1; t <= T; t++){
			ST();
			int N = INT(st.nextToken());
			int M = INT(st.nextToken());
			int[][] ts = new int[N][M];
			int[][] ws = new int[N][M];
			int[][] ss = new int[N][M];
			for(int i = 0; i < N; i++){
				ST();
				for(int j = 0; j < M; j++){
					ss[i][j] = INT(st.nextToken());
					ws[i][j] = INT(st.nextToken());
					ts[i][j] = INT(st.nextToken());
				}
			}
			int mx = 2*N;
			int my = 2*M;
			PriorityQueue<State> que = new PriorityQueue();
			que.add(new State(mx-1,0,0));
			int[][] cost = new int[mx][my];
			int inf = Integer.MAX_VALUE;
			for(int i = 0; i < mx; i++) fill(cost[i], inf);
			int[] dx = {-1,1,0,0};
			int[] dy = {0,0,-1,1};
			while(true){
				State s = que.poll();
				if(cost[s.x][s.y] != inf) continue;
				cost[s.x][s.y] = s.c;
				if(s.x == 0 && s.y == my-1) break;
				for(int i = 0; i < dx.length; i++){
					int nx = s.x+dx[i];
					int ny = s.y+dy[i];
					if(nx < 0 || ny < 0 || nx >= mx || ny >= my) continue;
					if(cost[nx][ny] != inf) continue;
					int nc = 0;
					int NS = ss[nx/2][ny/2];
					int WE = ws[nx/2][ny/2];
					int TS = ts[nx/2][ny/2];
					if(nx != s.x){
						if(s.x/2 == nx/2) nc = s.c + wait(s.c, TS, NS, WE)+1;
						else nc = s.c+2;
					}else{
						if(s.y/2 == ny/2) nc = s.c + wait(s.c, TS+NS, WE, NS)+1;
						else nc = s.c+2;
					}
		//			System.out.printf("At (%d,%d) at time %d reaches (%d,%d) at time %d%n",s.x,s.y,s.c,nx,ny,nc);
					que.add(new State(nx, ny, nc));
				}
			}
			System.out.printf("Case #%d: %d%n",t,cost[0][my-1]);
		}
	}

	int wait(int at, int TS, int NS, int WE){
	//	System.out.printf("Testing wait from time %d, TS = %d, NS = %d, WE = %d%n",at, TS, NS, WE);
		int ival = NS+WE;
		at = (at - TS)%ival;
		at += ival;
		at %= ival;
		int ret;
		if(at < NS) ret = 0;
		else ret = ival - at;
	//	System.out.println("Returns "+ret);
		return ret;
	}

	class State implements Comparable<State>{
		int x, y, c;
		State(int xx, int yy, int cc){ x = xx; y = yy; c = cc;}
		public int compareTo(State s){
			return c - s.c;
		}
	}
}