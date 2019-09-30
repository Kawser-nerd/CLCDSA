package qualification;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws IOException {
		String file = "C-large";
		Scanner sc = new Scanner(new FileReader(file + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));

		int cases = sc.nextInt(); sc.nextLine();
		for(int cas = 1; cas <= cases; cas++) {
			int r = sc.nextInt(), k = sc.nextInt(), n = sc.nextInt();
			int[] g = new int[n];
			for(int i = 0; i < n; i++)
				g[i] = sc.nextInt();
			
			int[] num = new int[n], next = new int[n];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(num[i] + g[(i+j)%n] <= k) {
						num[i] += g[(i+j)%n];
						next[i] = (i+j+1)%n;
					}
					else
						break;
			
			int start = -1;
			boolean[] vis = new boolean[n];
			for(int i = 0; ; i = next[i])
				if(vis[i]) {
					start = i;
					break;
				}
				else
					vis[i] = true;
			
			int size = 1;
			long val = num[start];
			for(int i = next[start]; i != start; i = next[i]) {
				size++;
				val += num[i];
			}
			
			long profit = 0;
			for(int i = 0; i != start && r > 0; i = next[i], r--)
				profit += num[i];
			
			profit += r / size * val;
			r -= r/size * size;
			
			for(int i = start; r > 0; i = next[i], r--)
				profit += num[i];
			
			out.printf("Case #%d: %d%n", cas, profit);
		}
		
		out.close();
	}
}
