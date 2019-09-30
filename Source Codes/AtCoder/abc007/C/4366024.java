import java.awt.Point;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main{
	static int R;
	static int C;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		C = sc.nextInt();
		int sx = sc.nextInt()-1;
		int sy = sc.nextInt()-1;
		int gx = sc.nextInt()-1;
		int gy = sc.nextInt()-1; 
		String board[][] = new String[R][C];

		for (int i = 0; i < R; i++) {
			board[i] = sc.next().split("");
		}
		int ans = searchRoute(sx,sy,gx,gy,board);
		System.out.println(ans);
	}

	public static int searchRoute(int sx,int sy,int gx,int gy,String board[][]) {
		Deque<Point> p = new ArrayDeque<>();
		p.add(new Point(sx,sy));
		int moves = 0;

		board[sx][sy] = "0";
		int[] dx = {-1,1,0,0};
		int[] dy = {0,0,-1,1};
		int s,i,j;

		int h = board.length;
		int w = board[h-1].length;

		while(true){
			s = p.size();
			for (int k = 0; k < s; k++) {
				i = p.getFirst().x;
				j = p.removeFirst().y;
				for (int a = 0; a < 4; a++) {
					if (i+dx[a] < 0 || h <= i+dx[a]) {
						continue;
					}
					if (j+dy[a] < 0 || w <= j+dy[a]) {
						continue;
					}
					if (!board[i+dx[a]][j+dy[a]].equals(".")) {
						continue;
					}
					board[i+dx[a]][j+dy[a]] = String.valueOf(moves + 1);
					p.addLast(new Point(i+dx[a],j+dy[a]));
				}
			}
			moves++;
			if (s==0) {
				break;
			}
		}
		if (board[gx][gy].equals(".")) {
			return -1;
			}
		return Integer.parseInt(board[gx][gy]);
	}
}