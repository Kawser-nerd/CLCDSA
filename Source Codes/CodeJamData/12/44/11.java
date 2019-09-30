import java.util.*;

public class codejamD {
	static int r,c;
	static char[][] board;
	static int[] dx = {0,0,-1}, dy = {1,-1,0};
	static boolean done;
	static HashSet<ArrayList<Integer>> seen = new HashSet<ArrayList<Integer>>();
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			r = in.nextInt();
			c = in.nextInt();
			board = new char[r][c];
			for(int i=0; i<r; i++)
				board[i] = in.next().trim().toCharArray();
			System.out.println("Case #" + t + ":");
			for(int d=0; d<10; d++) {
				int tx = -1;
				int ty = -1;
				for(int j=0; j<r; j++)
					for(int k=0; k<c; k++)
						if(board[j][k] == '0'+d) {
							tx = j;
							ty = k;
						}
				if(tx == -1) break;
				boolean[][] possible = new boolean[r][c];
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(tx); q.add(ty);
				possible[tx][ty] = true;
				int count = 1;
				while(!q.isEmpty()) {
					int cx = q.poll();
					int cy = q.poll();
					for(int i=0; i<3; i++) {
						int nx = cx+dx[i];
						int ny = cy+dy[i];
						if(!ok(nx,ny)) continue;
						if(board[nx][ny] == '#') continue;
						if(possible[nx][ny]) continue;
						possible[nx][ny] = true;
						count++;
						q.add(nx);
						q.add(ny);
					}
				}
				System.out.print(d+": " + count);
				seen.clear();
				ArrayList<Integer> states = new ArrayList<Integer>();
				for(int i=0; i<r; i++)
					for(int j=0; j<c; j++)
						if(possible[i][j] && !possible[i][j-1]) {
							states.add(i);
							states.add(j);
						}
				done = false;
				converge(states,tx,ty);
				System.out.println(done?" Lucky":" Unlucky");
			}
		}
	}
	static void converge(ArrayList<Integer> states, int tx, int ty) {
		if(done) return;
		if(seen.contains(states)) return;
		seen.add(states);
		boolean finish = true;
		for(int i=0; i<states.size(); i+=2)
			if(tx != states.get(i) || ty != states.get(i+1))
				finish = false;
		if(finish) {
			done = true;
			return;
		}
		for(int i=0; i<states.size(); i+=2)
			if(states.get(i) > tx)
				return; //too far
		for(int dir=0; dir<3; dir++) {
			ArrayList<Integer> next = new ArrayList<Integer>();
			for(int i=0; i<states.size(); i+=2) {
				int nx = states.get(i) - dx[dir];
				int ny = states.get(i+1) - dy[dir];
				if(board[nx][ny] == '#') {
					nx = states.get(i);
					ny = states.get(i+1);
				}
				next.add(nx);
				next.add(ny);
			}
			converge(next,tx,ty);
		}
	}
	static boolean ok(int x, int y) {
		return x>=0 && y>=0 && x<r && y<c;
	}
}
