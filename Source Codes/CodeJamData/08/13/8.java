package round1;

import java.io.*;
import java.math.BigDecimal;

public class C {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small.in"));
		//BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C-small-out"));
		//PrintWriter out = new PrintWriter(new FileWriter("C-large.out"));
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter out = new PrintWriter(System.out);
		
		String[] ans = new String[31];
		ans[2] = "027";
		String tmp = "";
		
		BigDecimal a = new BigDecimal("2.2360679774997896964091736687313");
		a = a.add(new BigDecimal(3));
		BigDecimal b = a.multiply(a).multiply(a);
		
		for (int i = 3; i <= 30; i++) {
			tmp = b.toString().split("\\.")[0];
			ans[i] = tmp.substring(tmp.length()-3, tmp.length());
			//out.println(ans[i]);
			b = b.multiply(a);
		}
		
		int T = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= T; i++) {
			int n = Integer.parseInt(in.readLine());
			out.println("Case #" + i + ": " + ans[n]);
		}
		
		out.flush();

	}

}
