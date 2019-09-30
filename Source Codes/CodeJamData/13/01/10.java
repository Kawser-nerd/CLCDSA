package ticTacToeTomek;

public class TicTacToeTomek {

	public static String[] execute(String[] input) {
		
		String[] words = {"X won", "O won", "Draw", "Game has not completed"};
		String[] out;
		String line;
				
		int[][] board = new int[4][4];		
		
		int result;
		
		int test = 1;
		int ntests;		
		
		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];
		
		for (int i = 1; test < 1+ntests;) {
			
			for (int j = 0; j < 4; j++) {
				line = input[i++];				
				for (int k = 0; k < 4; k++) {
					if(line.charAt(k)=='X')
						board[j][k] = 1;
					else if(line.charAt(k)=='O')
						board[j][k] = 2;
					else if(line.charAt(k)=='T')
						board[j][k] = 3;
					else
						board[j][k] = 0;
				}
			}
			i++;
			result = gameState(board);			
			out[test-1] = "Case #" + test + ": " + words[result];
			
			System.out.println(out[test-1]);
			
			test++;
		}
		return out;
	}

	private static int gameState(int[][] board) {
		
		if(check(board, 1))
			return 0;
		else if(check(board, 2))
			return 1;
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if(board[i][j]==0)
						return 3;
				}
			}
			
			return 2;		
		}
	}

	private static boolean check(int[][] b, int x) {
		boolean r;
		for (int i = 0; i < 4; i++) {
			r = true;
			for (int j = 0; j < 4; j++) {
				if(b[i][j]!=x && b[i][j]!=3) {
					r = false;
					break;
				}
			}
			if(r)
				return r;
			
			r = true;
			for (int j = 0; j < 4; j++) {
				if(b[j][i]!=x && b[j][i]!=3) {
					r = false;
					break;
				}
			}
			if(r)
				return r;
		}
		
		r = true;
		for (int i = 0; i < 4; i++) {
			if(b[i][i]!=x && b[i][i]!=3) {
				r = false;
				break;
			}
		}
		if(r)
			return r;
		
		r = true;
		for (int i = 0; i < 4; i++) {
			if(b[i][3-i]!=x && b[i][3-i]!=3) {
				r = false;
				break;
			}					
		}
		if(r)
			return r;
		
		return r;
	}
}
