import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class C {

	int M, N;
	int[][] board;
	int[] found;
	int max;
	
	C() throws Exception {

		File input = new File("input.txt"), output = new File("output.txt");

		Scanner scanner = new Scanner(input);
		BufferedWriter writer = new BufferedWriter(new FileWriter(output));

		int TestCases = scanner.nextInt();

		for (int Case = 1; Case <= TestCases; Case++) {

			writer.write("Case #" + Case + ": ");

			M = scanner.nextInt();
			N = scanner.nextInt();
			
			max = Math.min(M,N);
			
			board = new int[M][N];
			
			for(int i = 0; i < M; i++) {
				BigInteger b = new BigInteger(scanner.next(),16);
				BigInteger two = new BigInteger(2+"");
				for(int j = 0; j < N; j++) {
					if(b.mod(two).equals(BigInteger.ZERO))
						board[i][N-1-j] = 0;
					else
						board[i][N-1-j] = 1;
					b = b.divide(two);
				}
			}
			
			found = new int[max+1];
			
			int count = 0;
			
			for(int i = max; i > 0; i--) {
				find(i);
				if(found[i]>0) count++;
			}

			writer.write(count+"");
			
			for(int i = max; i > 0; i--)
				if(found[i]>0) {
					writer.newLine();
					writer.write(i+" "+found[i]);
				}

			writer.newLine();
		}

		scanner.close();
		writer.close();
	}
	
	void find(int size) {
		for(int i = 0; i <= M - size; i++)
			for(int j = 0; j <= N - size; j++)
			{
				if(find(i,j,size)) found[size]++;
			}
	}
	
	boolean find(int r, int c, int size) {
		if(board[r][c]<0) return false;
		int mod = (r+c+board[r][c])%2;
		for(int i = r; i < r+size; i++)
			for(int j = c; j < c+size; j++)
				if(board[i][j]<0||(i+j+board[i][j])%2!=mod) return false;
		for(int i = r; i < r+size; i++)
			for(int j = c; j < c+size; j++)
				board[i][j] = -1;
		return true;
	}

	public static void main(String[] args) throws Exception {
		new C();
	}
}