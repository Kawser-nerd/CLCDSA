import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class MakeSmooth {
	public static void main(String args[]) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		int D,I,M,N, cases;
		cases = Integer.parseInt(in.readLine());
		for(int i=1; i<=cases; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			D = Integer.parseInt(st.nextToken());
			I = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());

			
			int[] data = new int[N];
			st = new StringTokenizer(in.readLine());
			for(int n=0; n<N; n++) data[n] = Integer.parseInt(st.nextToken());
			if(N<2||D==0) {out.println("Case #"+i+": "+0); continue;}
			int max = 256;
			long dp[][] = new long[N][max];
			for(int n=0; n<N; n++) for(int end=0; end<max; end++){
				long best = Long.MAX_VALUE;
				for(int last=0; last<max; last++) {
					long insertCost = 0;
					if(M==0&&end!=last) insertCost = 1000000000;
					else if(end!=last) insertCost = I*((Math.abs(end-last)-1)/M);
					long modifyCost = Math.abs(end-data[n]);
					modifyCost = Math.min(D, modifyCost);
					long oldCost = 0;
					if(n>0) oldCost = dp[n-1][last];
					
					best = Math.min(best, insertCost+modifyCost+oldCost);
				}
				dp[n][end] = best;
			}
			
			long thebest = Long.MAX_VALUE;
			for(int end=0; end<max; end++)
				thebest = Math.min(thebest, dp[N-1][end]);
			out.println("Case #"+i+": "+thebest);
		}
			
		out.close();
	}
}
