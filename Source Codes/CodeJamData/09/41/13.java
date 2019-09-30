import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("A-large.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for (int itr = 1; itr <= cases; itr++) {
			int size = Integer.parseInt(br.readLine());
			
			int[] board = new int [size];
			for (int i = 0; i < size; i++) {
				String s = br.readLine();
				for (int j = 0; j < size; j++)
					if (s.charAt(j) == '1')
						board[i] = j;
			}
			
			int out = 0;
			boolean done = false;
			while (!done) {
				done = true;
				for (int i = 0; i < size; i++) {
					if (board[i] > i) {
						done = false;
						int s = 0;
						for (int j = i+1; j < size; j++)
							if (board[j] <= i) {
								s = j;
								break;
							}
						
						for (int j = s; j > i; j--) {
							int t = board[j];
							board[j] = board[j-1];
							board[j-1] = t;
							out++;
						}
					}
				}
			}
			ps.println("Case #" + itr + ": " + out);
		}
		
		br.close();
		ps.close();
	}

}
