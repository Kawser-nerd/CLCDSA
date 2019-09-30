import java.util.*;
import java.io.*;

class CodeJam {
	static public void main(String []args) {
		long time1 = (new Date()).getTime();
	
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		
		System.err.print("arglen="+args.length);
		for (int idx=0; idx<args.length; idx++) {
			System.err.print(" "+args[idx]);
		}
		System.err.println();
		
		int N = parseInt(nextline(inp));
		for (int caseidx = 0; caseidx < N; caseidx++) {
			int S = parseInt(nextline(inp));
			String ename[] = new String[S];
			for (int sidx = 0; sidx < S; sidx++) {
				ename[sidx] = nextline(inp);
			}
			
			int Q = parseInt(nextline(inp));
			int match[] = new int[Q];
			for (int qidx = 0; qidx < Q; qidx++) {
				String qry = nextline(inp);
				match[qidx] = -1;
				for (int sidx = 0; sidx < S; sidx++) {
					if (ename[sidx].equals(qry)) {
						match[qidx] = sidx;
						break;
					}
				}
			}
			
			int switches[] = new int[S];
			Arrays.fill(switches, 0);
			
			for (int qidx = Q-1; qidx >= 0; qidx--) {
				int midx = match[qidx];
				if (midx >= 0) {
					int minval = Q;
					for (int sidx = 0; sidx < S; sidx++) {
						if (sidx != midx && switches[sidx] < minval) 
							minval = switches[sidx];
					}
					switches[midx] = minval+1;
				}
			}
						
			int minval = Q;
			for (int sidx = 0; sidx < S; sidx++) {
				if (switches[sidx] < minval) 
					minval = switches[sidx];
			}
			
			System.out.println("Case #"+(caseidx+1)+": "+minval);
		}
		
		long time2 = (new Date()).getTime();
		
		System.err.println("Time taken: "+(time2-time1));
		System.out.flush();
	}
	
	static public String nextline(BufferedReader inp) {
		String line = "";
		try { line = inp.readLine(); } catch (Exception e) {}
		return line;
	}
		
	static public int parseInt(String line) {
		int ret = 0;
		try { ret = Integer.parseInt(line); } catch (Exception e) {}
		return ret;
	}
}
