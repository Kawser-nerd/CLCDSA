package round1;

import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws IOException {
		//BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		//PrintWriter out = new PrintWriter(new FileWriter("A-small-out"));
		PrintWriter out = new PrintWriter(new FileWriter("A-large-out"));
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter out = new PrintWriter(System.out);
		
		int T = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= T; i++) {
			int n = Integer.parseInt(in.readLine());
			String[] V1 = in.readLine().split(" ");
			String[] V2 = in.readLine().split(" ");
			long[] v1 = new long[n], v2 = new long[n];
			
			for (int j = 0; j < n; j++) {
				v1[j] = Long.parseLong(V1[j]);
				v2[j] = Long.parseLong(V2[j]);
			}
			
			Arrays.sort(v1);
			Arrays.sort(v2);
			
			long res = 0;
			
			for (int j = 0; j < n; j++) {
				res += v1[j]*v2[n-1-j];
			}
			
			out.println("Case #" + i + ": " + res);
		}
		
		out.flush();

	}

}
