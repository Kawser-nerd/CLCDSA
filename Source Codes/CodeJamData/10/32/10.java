package QualC2010;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Load {
	public static void main(String[] args) throws Exception {
		BufferedReader B = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter A = new PrintWriter(new FileWriter("B-large.out"));
		int N, n, x, y, i, j, k; long L,P,C;
		StringTokenizer st;
		
		int t = Integer.parseInt(B.readLine());
		for (int T = 0; T < t; T++) {
			n = 0;
			k = 0;
			st = new StringTokenizer(B.readLine());
			L = Long.parseLong(st.nextToken());
			P = Long.parseLong(st.nextToken());
			C = Long.parseLong(st.nextToken());
			while(C*L < P){L *= C; k++;}
			while(k > 0){
				k /= 2; n++;
			}
			
			A.println("Case #" + (T + 1) + ": " + n);
		}

		A.close();
	}
}
