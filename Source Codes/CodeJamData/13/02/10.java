package lawnmower;

public class Lawnmower {

	public static String[] execute(String[] input) {
		
		String[] words = {"NO", "YES"};
		String[] out;
		String[] splitted;
				
		
		int n, m;
		int[][] board;
		
		int result;
		
		int test = 1;
		int ntests;		
		
		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];
		
		for (int i = 1; test < 1+ntests;) {
			splitted = input[i++].split("\\s");
			n = Integer.parseInt(splitted[0]);
			m = Integer.parseInt(splitted[1]);
			board = new int[n][m];			
			for (int j = 0; j < n; j++) {
				splitted = input[i++].split("\\s");
				for (int k = 0; k < m; k++) {
					board[j][k] = Integer.parseInt(splitted[k]);					
				}
			}
			
			result = isFeasible(board, n, m);			
			out[test-1] = "Case #" + test + ": " + words[result];
			
			System.out.println(out[test-1]);
			
			test++;
		}
		return out;
	}

	private static int isFeasible(int[][] board, int n, int m) {
		
		int[] maxrow = new int[n];
		int[] maxcol = new int[m];		
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(board[i][j]>maxrow[i])
					maxrow[i] = board[i][j];
				if(board[i][j]>maxcol[j])
					maxcol[j] = board[i][j];
			}
		}		
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(board[i][j]<maxrow[i])
					if(board[i][j]<maxcol[j])
						return 0;
			}
		}
		
		return 1;
	}
}
