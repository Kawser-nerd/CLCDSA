import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;
public class Main {
	public static long[] primes = new long[9592];
	public static long[] squares = new long[9592];
	public static long[] cubes = new long[9592];
	public static FHSet primeset = new FHSet(100000);
	private static class Pair {
		long red;
		int a;
		public Pair(long v) {
			red = v;
			a = 1;
		}
	}
	public static void main(String args[]) {
		Sc sc = new Sc(System.in);
		int ind = 0;
		primes[ind] = 2;
		squares[ind] = 4;
		cubes[ind++] = 8;
		for(long i = 3; i<=100000; i+=2) {
			long sqrt = (long) Math.sqrt(i);
			boolean prime = true;
			for(int j = 1; j<ind; j++) {
				long p = primes[j];
				if(p>sqrt) break;
				if(i%p == 0) {
					prime = false;
					break;
				}
			}
			if(prime) {
				primes[ind] = i;
				squares[ind] = i*i;
				cubes[ind++] = i*i*i;
				primeset.add(i);
			}
		}

		int n = sc.nI();
		FHMap map = new FHMap(640007);
		Pair[] pairs = new Pair[n];
		int indp = 0;
		for(int i = 0; i<n; i++) {
			long v = reduce(sc.nL());
			Pair p = map.get(v);
			if(p!=null) {
				p.a++;
			} else {
				p = new Pair(v);
				map.put(p);
				pairs[indp++] = p;
			}
		}

		FHSet set = new FHSet(640007);
		//HashSet<Long> set = new HashSet<>(2560021);
		int picked = 0;
		for(int i = 0; i<indp; i++) {
			Pair p = pairs[i];
			if(p.red == 1) {
				picked++;
				continue;
			}
			if(!set.contains(p.red)) {
				long inv = inv(p.red);
				int max = p.a;
				if(inv != -1) {
					Pair pp = map.get(inv);
					if(pp != null) {
						max = Math.max(max,pp.a);
						set.add(inv);
					}
				}
				picked+=max;
			}
		}
		System.out.println(picked);
	}
	public static long inv(long v) {
		long ret = 1;
		long p = 0;
		long sq = 0;
		long vsq = 0;
		long vp = 0;
		for(int i = 0; i<326 && v != 1; i++) {
			p = primes[i];
			sq = squares[i];
			if(ret>10000000000L) return -1;
			vsq = v/sq;
			if(vsq*sq == v) {
				ret *= p;
				v = vsq;
				continue;
			}
			
			vp = v/p;
			if(vp*p == v) {
				ret *= sq;
				v = vp;
			}
		}
		if(v!=1) {
			long sqrt = (long) Math.sqrt(v);
			if(sqrt*sqrt == v) {
				ret *= sqrt;
				v = 1;
			} else if(primeset.contains(v)) {
				if((ret*v > 10000000000L) || (ret*v*v > 10000000000L)) return -1;
				else return ret*v*v;
			} else return -1;
		} 
		

		return (ret > 10000000000L) ? -1 : ret;
	}
	public static long reduce(long v) {
		for(int i = 0; i<326; i++) {
			long cube = cubes[i];
			if(cube>v) break;
			long vc = v/cube;
			while(vc*cube == v) {
				v = vc;
				vc = v/cube;
			}
		}
		return v;
	}
	private static class FHMap {
		Pair[] map;
		long mod;
		int size = 0;
		
		public FHMap(int mod){
			map = new Pair[mod];
			this.mod = mod;
		}
		
		public void put(Pair p) {
			int w = (int) (p.red%mod);
			while(true) {
				if(map[w] == null) {
					map[w] = p;
					size++;
					return;
				} else if(map[w].red == p.red) {
					map[w] = p;
					return;
				}
				w = (int) ((w + 1)%mod);
			}
		}
		public Pair get(long k) {
			int w = (int) (k%mod);
			while(true) {
				if(map[w] == null) {
					return null;
				} else if(map[w].red == k) {
					return map[w];
				}
				w = (int)((w + 1)%mod);
			}
		}
	}
	private static class FHSet {
		long[] map;
		long mod;
		
		public FHSet(int mod){
			map = new long[mod];
			this.mod = mod;
		}
		
		public void add(long p) {
			int w = (int) (p%mod);
			while(true) {
				if(map[w] == 0) {
					map[w] = p;
					return;
				} else if(map[w] == p) {
					return;
				}
				w = (int) ((w + 1)%mod);
			}
		}
		public boolean contains(long k) {
			int w = (int) (k%mod);
			while(true) {
				if(map[w] == 0) {
					return false;
				} else if(map[w] == k) {
					return true;
				}
				w = (int)((w + 1)%mod);
			}
		}
	}
}

class Sc {
    public Sc(InputStream i) {
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasM() {
        return peekToken() != null;
    }

    public int nI() {
        return Integer.parseInt(nextToken());
    }

    public double nD() { 
        return Double.parseDouble(nextToken());
    }

    public long nL() {
        return Long.parseLong(nextToken());
    }

    public String n() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null) 
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}