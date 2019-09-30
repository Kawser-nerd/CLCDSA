import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

	
	static char[][] maze;
	static int[][] d;
	static int INF = 10000000;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		// ?????
		class P{
			public int px;
			public int py;
			public P(int px, int py) {
				// TODO Auto-generated constructor stub
				this.px = px;
				this.py = py;
			}
		}
		
		int R = Integer.parseInt(sc.next());
		int C = Integer.parseInt(sc.next());
		int sy = Integer.parseInt(sc.next()) - 1 ;
		int sx = Integer.parseInt(sc.next()) - 1 ;
		int gy = Integer.parseInt(sc.next()) - 1 ;
		int gx = Integer.parseInt(sc.next()) - 1 ;
		
		int[] dx = {1,-1,0,0};
		int[] dy = {0,0,1,-1};
		
		maze = new char[R][C];
		for(int i=0; i<R; i++){
			maze[i] = sc.next().toCharArray();
		}

		d = new int[R][C];
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				d[i][j] = INF;
			}
		}
		
		
		ArrayDeque<P> que = new ArrayDeque<P>();
		que.add(new P(sx,sy));
		d[sy][sx] = 0;
		while(!que.isEmpty()){
			P p = que.removeLast();
			if(p.px == gx && p.py == gy)break;
			for(int i=0; i<4; i++){
				int next_x = p.px + dx[i];
				int next_y = p.py + dy[i];
				if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R && 
						maze[next_y][next_x] != '#' && d[next_y][next_x] == INF){
					que.push(new P(next_x,next_y));
					d[next_y][next_x] = d[p.py][p.px] + 1;
				}
			}
		}
		System.out.println(d[gy][gx]);

		
		sc.close();
	}

	
}