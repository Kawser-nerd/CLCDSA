import java.util.*;
import java.io.*;

class CodeJam {
	static public void main(String []args) {
		long time1 = (new Date()).getTime();
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		
		int N = parseInt(nextline(inp));
		for (int caseidx = 0; caseidx < N; caseidx++) {
			int T = parseInt(nextline(inp));
			int tda[] = new int[60*24 + T];
			int tdb[] = new int[60*24 + T];
			Arrays.fill(tda, 0);
			Arrays.fill(tdb, 0);
			String line = nextline(inp);
			StringTokenizer tok = new StringTokenizer(line);
			int NA = parseInt(tok.nextToken());
			int NB = parseInt(tok.nextToken());
			for (int idx = 0; idx < NA; idx++) {
				line = nextline(inp);
				tok = new StringTokenizer(line, ": ");
				int hr = parseInt(tok.nextToken());
				int mn = parseInt(tok.nextToken());
				int leave = hr*60 + mn;
				hr = parseInt(tok.nextToken());
				mn = parseInt(tok.nextToken());
				int arrive = hr*60 + mn;
				int ready = arrive + T;
				
				tda[leave]--;
				tdb[ready]++;
			}
			
			for (int idx = 0; idx < NB; idx++) {
				line = nextline(inp);
				tok = new StringTokenizer(line, ": ");
				int hr = parseInt(tok.nextToken());
				int mn = parseInt(tok.nextToken());
				int leave = hr*60 + mn;
				hr = parseInt(tok.nextToken());
				mn = parseInt(tok.nextToken());
				int arrive = hr*60 + mn;
				int ready = arrive + T;
				
				tdb[leave]--;
				tda[ready]++;
			}
			
			int mina = 0;
			int minb = 0;
			int cura = 0;
			int curb = 0;
			for (int idx=0; idx<tda.length; idx++) {
				cura += tda[idx];
				curb += tdb[idx];
				if (cura < mina) mina = cura;
				if (curb < minb) minb = curb;
			}
			
			System.out.println("Case #"+(caseidx+1)+": "+(-mina)+" "+(-minb));
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
