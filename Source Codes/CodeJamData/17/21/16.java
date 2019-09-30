package r1b2017;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int d = in.nextInt();
			int n = in.nextInt();
			double max = 0;
			for (int i = 0; i < n; i++) {
				int k = in.nextInt();
				int s = in.nextInt();
				double cur = 1.0 * (d - k) / s;
				if (cur > max) {
					max = cur;
				}
			}
			double res = d / max;
			out.println(res);
		}

		out.flush();
	}
	
}
