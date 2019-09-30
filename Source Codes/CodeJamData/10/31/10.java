package QualC2010;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Rope {
	public static void main(String[] args) throws Exception {
		BufferedReader B = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter A = new PrintWriter(new FileWriter("A-large.out"));
		int N, n, x, y, i, j, k;
		StringTokenizer st;
		int[][] wire;

		int t = Integer.parseInt(B.readLine());
		// for(int P = 0; P < 6; P++){System.out.println(sub[500-P][3]);}
		for (int T = 0; T < t; T++) {
			n = 0;
			N = Integer.parseInt(B.readLine());
			wire = new int[N][2];
			for (i = 0; i < N; i++) {
				st = new StringTokenizer(B.readLine());
				wire[i][0] = Integer.parseInt(st.nextToken());
				wire[i][1] = Integer.parseInt(st.nextToken());
			}
			for (i = 0; i < N; i++) {
				for (j = 0; j < i; j++) {
					if((wire[i][0] - wire[j][0])*(wire[i][1] - wire[j][1]) < 0){
						n++;
					}
				}

			}
			A.println("Case #" + (T + 1) + ": " + n);
		}

		A.close();
	}
}
