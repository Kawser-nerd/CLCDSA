package treasure;

import java.math.BigInteger;

public class Treasure {
	
	final static int NKEYS = 201;
	static BigInteger visit;	
	static BigInteger[] achieves;
	static BigInteger[] opens;
	static int[] keys;
	static int[] key;
	static int[][] chestkeys;
	static int CHESTS;	
	
	public static String[] execute(String[] input) {		
		
		String[] out;
		String[] splitted;				
		
		int k, n;		
		int result[];
		
		int test = 1;
		int ntests;		
		
		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];
		
		for (int i = 1; test < 1+ntests;) {
			splitted = input[i++].split("\\s");
			k = Integer.parseInt(splitted[0]);
			n = Integer.parseInt(splitted[1]);
			
			CHESTS = n;
			achieves = new BigInteger[n];
			key = new int[n];
			opens = new BigInteger[NKEYS];
			keys = new int[NKEYS];
			for (int j = 0; j < NKEYS; j++) {
				opens[j] = BigInteger.valueOf(0);
			}			
			
			splitted = input[i++].split("\\s");
			for (int j = 0; j < k; j++) {
				keys[Integer.parseInt(splitted[j])]++;
			}
			
			chestkeys = new int[n][NKEYS];
			for (int j = 0; j < n; j++) {
				splitted = input[i++].split("\\s");
				key[j] = Integer.parseInt(splitted[0]);
				opens[key[j]] = opens[key[j]].setBit(j);
				int m = Integer.parseInt(splitted[1]);				
				for (int j1 = 2; j1 < 2+m; j1++) {
					chestkeys[j][Integer.parseInt(splitted[j1])]++;
				}				
			}
			
			for (int j = 0; j < n; j++) {
				achieves[j] = open(chestkeys[j]);
			}			
						
			result = openChests(n, keys);
			out[test-1] = "Case #" + test + ":";
			if(result==null)
				out[test-1] += " IMPOSSIBLE";
			else
				for (int j = 0; j < n; j++) {
					out[test-1] += " " + result[j];
				}
			
			System.out.println(out[test-1]);
			
			test++;
		}
		return out;
	}
	
	static int[] openChests(int n, int[] initkeys) {
		
		BigInteger expected = BigInteger.valueOf(0);
		for (int i = 0; i < n; i++) {
			expected = expected.setBit(i);
		}
		
		BigInteger sofar = BigInteger.valueOf(0);
		int[] r = new int[n];
		BigInteger ach = open(initkeys);
		
		for (int i = 0; i < n; i++) {			
			r[i] = -1;
			for (int j = 0; j < n; j++) {				
				if(!sofar.testBit(j) && ach.testBit(j)) {					
					visit = sofar.or(BigInteger.valueOf(0));					
					initkeys[key[j]]--;
					if(initkeys[key[j]]==0)
						ach = ach.xor(opens[key[j]]);
					dfs(j, ach);
					
					if(expected.xor(visit).signum()==0) {
						r[i] = j+1;
						sofar = sofar.setBit(j);
						addKeys(initkeys, chestkeys[j]);
						ach = ach.or(achieves[j]);
						break;
					}
					else {
						if(initkeys[key[j]]==0)
							ach = ach.or(opens[key[j]]);
						initkeys[key[j]]++;						
					}					
				}
			}
			if(r[i]<0)
				return null;		
		}
		return r;		
	}
	
	
	private static void addKeys(int[] dest, int[] src) {
		for (int i = 0; i < NKEYS; i++) {
			dest[i] += src[i];
		}
		
	}

	static BigInteger open(int[] k) {
		BigInteger r = BigInteger.valueOf(0);
		for (int i = 0; i < k.length; i++) {
			if(k[i]>0)
				r = r.or(opens[i]);
		}
		return r;		
	}
	
	
	static void dfs(int chest, BigInteger init) {
		visit = visit.setBit(chest);		
		for (int i = 0; i < CHESTS; i++) {
			if(!visit.testBit(i)) {
				if(achieves[chest].testBit(i))
					dfs(i, init);
				else if(init.testBit(i))
					dfs(i, init);
			}
		}
	}
	
}
