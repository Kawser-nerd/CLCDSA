import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int pp = 0; pp < N; pp++) {
			String[] ss = br.readLine().split(" ");

			int d = Integer.parseInt(ss[0]);
			int n = Integer.parseInt(ss[1]);

			double max = 0.0;
			for(int i = 0; i < n; i++) {
				ss = br.readLine().split(" ");

				int k = Integer.parseInt(ss[0]);
				int s = Integer.parseInt(ss[1]);
				double time = (d-k)/((double)s);
				System.out.println(d + " " + k + " " + s + " " + time);
				max = Math.max(max,time);
			}

			double ret = d/max;


			pw.println("Case #" + (pp+1) + ": " + ret);
		}


		pw.flush();
		pw.close();

	}
}