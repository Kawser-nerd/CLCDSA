import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class tickets {
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
	
	static final long MOD = 1000002013L;
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("tickets.in"));
		out = new PrintWriter(new FileWriter("tickets.out"));
		
		int tt = nextInt();
		for (int t=1; t<=tt; t++) {
			out.printf("Case #%d: ", t);
			
			long nStops = nextInt();
			long nPpl = nextInt();
			
			long cost = 0;
			TreeMap<Long, Long> stops = new TreeMap<Long, Long>();
			for (int i=0; i<nPpl; i++) {
				long from = nextInt();
				long to = nextInt();
				long pass = nextInt();
				
				long trip = computeCost(from, to, nStops) % MOD;
				cost += (trip * pass);
				cost %= MOD;
				
				add(stops, from, pass);
				add(stops, to, -pass);
			}
			
			long better = 0;
			Stack<Long> ppl = new Stack<Long>();
			Stack<Long> from = new Stack<Long>();
			for (Entry<Long, Long> e : stops.entrySet()) {
				long station = e.getKey();
				long numP = e.getValue();
				if (numP > 0) {
					ppl.push(numP);
					from.push(station);
				}
				
				while (numP < 0) {
					long nextS = from.pop();
					long nextP = ppl.pop();
					
					long pass = min(-numP, nextP);
					long trip = computeCost(nextS, station, nStops) % MOD;
					better += (trip * pass);
					better %= MOD;
					
					nextP -= pass;
					numP += pass;
					
					if (nextP > 0) {
						ppl.push(nextP);
						from.push(nextS);
					}
				}
			}
			
			long ans = (cost + MOD - better)%MOD;
			out.println(ans);
		}
		
		out.close();
		in.close();
	}
	
	private static long min(long a, long b) {
		return a<b?a:b;
	}

	private static void add(TreeMap<Long, Long> stops, long key, long incr) {
		if (!stops.containsKey(key))
			stops.put(key, 0L);
		stops.put(key, stops.get(key)+incr);
	}

	public static long computeCost(long a, long b, long nStops) {
		long diff = b-a;
		return (2*nStops - diff + 1) * diff/2;
	}
}
