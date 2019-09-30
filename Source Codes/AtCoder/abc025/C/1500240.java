import java.util.Scanner;

/**
 * http://abc025.contest.atcoder.jp/tasks/abc025_c
 */
public class Main {
 
	static final int N = 3;
	static final int B = 1;
	static final int W = 2;
	static final int[][] b = new int[N-1][N];
	static final int[][] c = new int[N][N-1];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int y=0; y<N-1; y++)
			for(int x=0; x<N; x++)
				b[y][x] = sc.nextInt();
		for(int y=0; y<N; y++)
			for(int x=0; x<N-1; x++)
				c[y][x] = sc.nextInt();
		sc.close();
		int[][] board = dfs(new int[N][N], B);
				
		System.out.println(getScore(board,B));
		System.out.println(getScore(board,W));
		
	}
	
	static int[][] dfs(int[][] board, int turn){
		int maxScore = -1;
		int[][] maxBoard = null;
		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				if(board[y][x]==0){
					int[][] next=getCopy(board);
					next[y][x] = turn;
					int[][] last = dfs(next, turn==B ? W : B);
					int score = getScore(last, turn);
					if(score>maxScore){
						maxScore = score;
						maxBoard = getCopy(last);
					}
				}
			}
		}
		return maxBoard==null ? board : maxBoard;
	}
		
	static int getScore(int[][] board, int turn){
		int score=0;
		for(int y=0; y<N-1; y++){
			for(int x=0; x<N; x++){
				if(board[y][x]==0) continue;
				if(turn==W && board[y][x]!=board[y+1][x]) score+=b[y][x];
				if(turn==B && board[y][x]==board[y+1][x]) score+=b[y][x];
			}
		}
		for(int y=0; y<N; y++){
			for(int x=0; x<N-1; x++){
				if(board[y][x]==0) continue;
				if(turn==W && board[y][x]!=board[y][x+1]) score+=c[y][x];
				if(turn==B && board[y][x]==board[y][x+1]) score+=c[y][x];
			}
		}
		return score;
	}
	
	static int[][] getCopy(int[][] board){
		int[][] copy = new int[N][N];
		for(int y=0; y<N; y++)
			for(int x=0; x<N; x++)
				copy[y][x] = board[y][x];
		return copy;
	}

}