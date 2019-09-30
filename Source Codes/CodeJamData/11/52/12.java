import java.io.*;
import java.util.*;

public class BaiB {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		PrintWriter pw = new PrintWriter(new FileWriter("Blarge.out"));
		
		int ntest = sc.nextInt();
		for(int test=1;test<=ntest;++test) {
			
			System.err.println("Run test = " + test);
			
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i=0;i<n;++i)
				a[i] = sc.nextInt();
			int[] c = new int[10001];
			
			for(int i=0;i<n;++i)
				++c[a[i]];
			
			
			pw.print("Case #" + test + ": ");
			
			if(n == 0) pw.print(0);
			else {
				ArrayList<int[]> ar = new ArrayList<int[]>();
				for(int i=1;i<c.length;++i) {
					while(c[i] > 0) {
						int s = i;
						int e = i;
						while(e < c.length && c[e] > 0) {
							--c[e];
							++e;
						}
						--e;
						
						ar.add(new int[]{s,e});
					}
				}
				int[][] segs = new int[ar.size()][];
				for(int i=0;i<segs.length;++i)
					segs[i] = ar.get(i);
				
				boolean tiep = true;
				while(tiep) {
					tiep = false;
					day: for(int i=0;i<segs.length;++i)
						for(int j=0;j<segs.length;++j) {
							if(segs[i][0] < segs[j][0] && segs[j][1] < segs[i][1]) {
								
								int t = segs[i][1];
								segs[i][1] = segs[j][1];
								segs[j][1] = t;
								
								tiep = true;
								break day;
							}
						}
				}
				
				int res = Integer.MAX_VALUE;
				for(int[] s : segs)
					res = Math.min(res, s[1] - s[0] + 1);
				
				pw.print(res);
			}
			
			pw.println();
			
		}
		
		sc.close();
		pw.close();
	}
}
