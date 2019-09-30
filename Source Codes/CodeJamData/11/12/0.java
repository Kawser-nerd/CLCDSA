import java.io.*;
import java.util.*;

public class Bai2 {
	public static void main(String[] args) throws Exception {
		// Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Blarge.out"));
		
		int[] p = new int[12];
		p[0] = 1;
		for(int i=1;i<p.length;++i) p[i] = 28 * p[i-1];
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {
			System.err.println("Running test " +  test);
			int n = sc.nextInt();
			int m = sc.nextInt();
			char[][] words = new char[n][];
			for(int i=0;i<n;++i)
				words[i] = sc.next().toCharArray();
			boolean[][] have = new boolean[n][256];
			for(int i=0;i<n;++i) {
				for(int j=0;j<words[i].length;++j)
					have[i][words[i][j]] = true;
			}
			String res = "";
			for(int i=0;i<m;++i) {
				char[] order = (" " + sc.next()).toCharArray();
				int[] pos = new int[256];
				for(int j=1;j<order.length;++j)
					pos[order[j]] = j;
				TreeSet<Long>[] ts = new TreeSet[27];
				for(int t=0;t<27;++t) ts[t] = new TreeSet<Long>();
				for(int j=0;j<n;++j) {
					long cur = p[words[j].length] - 1;
					if(have[j][order[1]]) ts[0].add(cur);
					for(int k=1;k<=26;++k) {
						if(have[j][order[k]]) {
							for(int t=0;t<words[j].length;++t) if(words[j][t] == order[k]) {
								cur += (words[j][t] - 'a' + 1 - 27) * p[t];
							}
						}
						if(k < 26 && have[j][order[k+1]]) ts[k].add(cur);
					}					
				}
				int best = -1, jbest = 0;
				for(int j=0;j<n;++j) {
					long cur = p[words[j].length] - 1;
					int z = 0;
					for(int k=1;k<=26;++k) {
						if(ts[k-1].contains(cur) && !have[j][order[k]]) ++z;
						if(have[j][order[k]]) {
							for(int t=0;t<words[j].length;++t) if(words[j][t] == order[k]) {
								cur += (words[j][t] - 'a' + 1 - 27) * p[t];
							}
						}
					}		
					if(best < z) {
						best = z;
						jbest = j;
					}
				}
				res = res + " " + new String(words[jbest]);
			}
			
			pw.print("Case #" + test + ":");
			pw.print(res);
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
