import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p = 0; p < N; p++) {
			int n = Integer.parseInt(br.readLine());
			Set<Integer> set = new HashSet<Integer>();
			for(int i = 0; i < 2*n-1; i++) {
				String[] s = br.readLine().split(" ");
				for(int j = 0; j < n; j++) {
					int v = Integer.parseInt(s[j]);
					if(set.contains(v)) {
						set.remove(v);
					} else {
						set.add(v);
					}
				}
			}

			int[] ret = new int[n];
			int at = 0;
			for(int vv : set) {
				ret[at] = vv;
				at++;
			}
			Arrays.sort(ret);

			pw.print("Case #" + (p+1) + ":");
			for(int i = 0; i < n; i++) pw.print(" " + ret[i]);
			pw.println();
		}


		pw.flush();
		pw.close();

	}
}