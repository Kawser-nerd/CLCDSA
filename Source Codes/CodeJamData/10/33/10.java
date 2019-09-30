package QualC2010;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Chess {
	public static void main(String[] args) throws Exception {
		BufferedReader B = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter A = new PrintWriter(new FileWriter("C-large.out"));
		int N, M, n, x, y, i, j, k,count;
		int[] total;
		String s = "0123456789ABCDEF", S;
		StringTokenizer st;
		byte[][] board = new byte[512][512];
		int t = Integer.parseInt(B.readLine());
		for (int T = 0; T < t; T++) {			
			count = 0;
			st = new StringTokenizer(B.readLine());
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			total = new int[513];
			for (i = 0; i < M; i++) {
				S = B.readLine();
				for (j = 0; j < N/4; j++) {
					n = s.indexOf(S.substring(j, j + 1));
					for (x = 0; x < 4; x++) {
						board[i][4 * j + x] = (byte)((n >> (3 - x)) % 2);
					}
				}
			}
			for (n = Math.min(M, N); n > 0; n--) {
				for (i = 0; i <= M - n; i++) {
					row: for (j = 0; j <= N - n; j++) {
						k = board[i][j];
						for (x = 0; x < n; x++) {
							for (y = 0; y < n; y++) {
								if(board[x+i][y+j] < 0 || (board[i][j] + x+y) % 2 != (board[x+i][y+j])%2){
									continue row;
								}
							}
						}
						total[n]++;
						for (x = 0; x < n; x++) {
							for (y = 0; y < n; y++) {
								board[x+i][y+j] = -1;
							}
						}
					}
				}
				if(total[n] > 0){count++;}
			}
			
			A.println("Case #" + (T + 1) + ": " + count);
			for(i = 512; i > 0; i--){
				if(total[i] > 0){
					A.println(i + " " + total[i]);
				}
			}
		}

		A.close();
	}
}
