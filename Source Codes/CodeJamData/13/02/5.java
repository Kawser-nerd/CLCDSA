import static java.lang.Math.min;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws Exception{
		
		
		Scanner scanner = new Scanner(new File("B-large.in"));
			
		PrintStream writer = new PrintStream(new File("output.txt"));
		int T = scanner.nextInt();
		for (int c = 0; c < T; c++){
			
			
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			int[][] field = new int[N][];
			
			int[] counts = new int[101];   // how many of each number
			int smallest = Integer.MAX_VALUE;
			for (int i= 0; i < N; i++){
				field[i] = new int[M];
				for (int j = 0; j < M; j++){
					int bit = field[i][j] = scanner.nextInt();
					smallest = min(smallest, bit);
					counts[bit]++;
				}
			}
			
			boolean ret = checkPossible(field, counts, smallest, N, M);
			System.out.printf("Case #%d: %s\n", c+1, ret? "YES" : "NO");
			writer.printf("Case #%d: %s\n", c+1, ret? "YES" : "NO");
		}
	}
	
	
	static boolean checkPossible(int[][] field, int[] counts, int smallest, int N, int M){
		
		// find smallest TODO: this is the performance bottle neck 
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (field[i][j] != smallest)
					continue;
				
				// check row, if it's good, then set 
				// the row, and decrement counts, update smallest
				// return if the subproblem is also good
				if (checkRow(field, i, smallest, M))
				{
					counts[smallest] -= clearRow(field, i, M);
					smallest = getNextSmallest(counts, smallest);
					if (Integer.MAX_VALUE == smallest)
						return true;
					else
						return checkPossible(field, counts, smallest, N, M);
						
				}
				
				else if (checkColumn(field, j, smallest, N))
				{
					counts[smallest] -= clearColumn(field, j, N);
					smallest = getNextSmallest(counts, smallest);
					if (Integer.MAX_VALUE == smallest)
						return true;
					else
						return checkPossible(field, counts, smallest, N, M);
				}
				
				return false;
				// else check columns, do the same thing as row. 
				// if neither is good, then return false
				
			}
		}
		return true;
	}
	
	/**
	 * @param field
	 * @param rowId
	 * @param number
	 * @param rowOrColumn  1 for row, 0 for column
	 * @return
	 */
	static boolean checkRow(int[][] field, int rowId, int number, int M){
		for (int j = 0;  j< M; j++){
			int bit = field[rowId][j];
			if (bit != 0 && bit != number)
				return false;
		}
		return true;
	}
	
	static int clearRow(int[][] field, int rowId, int M){
		int cnt = 0;
		for (int j = 0; j < M; j++){
			if (field[rowId][j] != 0){
				cnt++;
				field[rowId][j] = 0;
			}
		}
		return cnt;
	}
	
	static boolean checkColumn(int[][] field, int columnId, int number, int N){
		for (int i= 0;  i< N; i++){
			int bit = field[i][columnId];
			if (bit != 0 && bit != number)
				return false;
		}
		return true;
	}
	
	static int clearColumn(int[][] field, int columnId, int N){
		int cnt = 0;
		for (int i = 0; i < N; i++){
			if (field[i][columnId] != 0){
				cnt++;
				field[i][columnId]= 0;
			}
		}
		return cnt;
	}
	
	static int getNextSmallest(int[] counts, int crt){
		
		while(crt < counts.length){
			if (counts[crt] != 0)
				return crt;
			crt++;
		}
		return Integer.MAX_VALUE;
	}
	
}
