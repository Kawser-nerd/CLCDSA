import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("C-large.in"));
		System.setOut(new PrintStream(new FileOutputStream("C-large.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			
			char[][] res = new char[R][C];
			for (int i = 0; i < R; i++) Arrays.fill(res[i], '*');
			
			int blank = R*C-M;
			int wid = 0;
			int hei = 0;
			int wex = 0;
			int hex = 0;
			
			if (blank == 1) {
				wid = 1;
				hei = 1;
			} else if (R == 1) {
				wid = blank;
				hei = R;
			} else if (C == 1) {
				hei = blank;
				wid = C;
			} else if (blank == R*C) {
				wid = C;
				hei = R;
			} else {
				for (int w = 2; w <= C; w++) {
					for (int h = 2; h <= R; h++) {
						int rem = blank - w*h;
						if (w*h == blank) {
							wid = w;
							hei = h;
							wex = 0;
							hex = 0;
						} else if (rem > 1) {
							if (w < C) {
								if (rem < h) {
									wid = w;
									hei = h;
									wex = 0;
									hex = rem;
								}
							}
							if (h < R) {
								if (rem < w) {
									wid = w;
									hei = h;
									wex = rem;
									hex = 0;
								}
							}
							if (w < C && h < R) {
								for (int wx = 2; wx < rem - 1; wx++) {
									int hx = rem - wx;
									if (wx < w && hx < h) {
										wid = w;
										hei = h;
										wex = wx;
										hex = hx;
									}
								}
							}
						}
					}
				}
			}
			
			if (wid == 0) {
				System.out.printf("Case #%d:%nImpossible%n", caseNum);
			} else {
				for (int r = 0; r < hei; r++) {
					for (int c = 0; c < wid; c++) {
						res[r][c] = '.';
					}
				}
				for (int r = 0; r < hex; r++) {
					res[r][wid] = '.';
				}
				for (int c = 0; c < wex; c++) {
					res[hei][c] = '.';
				}
				res[0][0] = 'c';
				System.out.printf("Case #%d:%n", caseNum);
				for (int r = 0; r < R; r++) {
					System.out.println(new String(res[r]));
				}
			}
		}
	}
}
