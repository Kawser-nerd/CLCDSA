import java.util.*;

public class c {
	static char MINE = '*', PLAYER = 'c', EMPTY = '.';
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			
			boolean done = false;
			char[][] board = new char[r][c];
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
					board[i][j] = EMPTY;
			System.out.printf("Case #%d:%n", t);
			if(m == r*c-1) {
				for(char[] x : board) Arrays.fill(x, MINE);
				board[0][0] = PLAYER;
				done = true;
			}
			else if(r == 1 || c == 1) {
				for(int i=r-1; i>=0; i--)
					for(int j=c-1; j>=0; j--)
						if(m --> 0)
							board[i][j] = MINE;
				board[0][0] = PLAYER;
				done = true;
			}
			else {
				for(int filledRows = 0; !done && filledRows <= r - 2; filledRows++) {
					for(int filledCols = 0; !done && filledCols <= c - 2; filledCols++) {
						int left = m - filledRows*c - filledCols*r + filledRows*filledCols;
						if(left < 0) continue;
						int leftRows = r-filledRows, leftCols = c-filledCols;
						int playable = (leftRows-2)*(leftCols-2);
						if(playable < left) continue;
						
						board[0][0] = PLAYER;
						for(int i=0; i<r; i++)
							for(int j=0; j<c; j++)
								if(i >= leftRows || j >= leftCols)
									board[i][j] = MINE;
						for(int i=leftRows-1; i>= 2; i--)
							for(int j=leftCols-1; j >=2; j--)
								if(left-->0)
									board[i][j] = MINE;
						done = true;
					}
				}
			}
			if(done) for(char[] x : board) System.out.println(new String(x));
			else System.out.println("Impossible");
		}
	}
}