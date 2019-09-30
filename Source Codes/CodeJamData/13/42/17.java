import java.io.*;
import java.util.*;

public class prizes {
	static BufferedReader in;
	static StringTokenizer st;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("prizes.in"));
		out = new PrintWriter(new FileWriter("prizes.out"));
		
		int tt = nextInt();
		for (int t=1; t<=tt; t++) {
			out.printf("Case #%d: ", t);
			
			long teams = (1L << nextInt());
			long prizes = nextLong();
			out.println(solveGuaranteed(teams, prizes) + " " + solvePossible(teams, prizes));
		}
		
		out.close();
		in.close();
	}
	
	public static long solveGuaranteed(long teams, long prizes) {
		if (prizes == teams)
			return teams-1;
		if (prizes <= teams/2)
			return 0;
		
		long rank = solveGuaranteed(teams/2, prizes - teams/2); 
		return 2*(rank+1);
	}
	
	public static long solvePossible(long teams, long prizes) {
		if (prizes == teams)
			return teams-1;
		if (prizes >= teams/2)
			return teams-2;
		long rank = solvePossible(teams/2, prizes);
		return rank*2;
	}
}
