import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "al";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int d = nextInt(), k = nextInt();
			long[] arr = new long[k];
			long max = Long.MIN_VALUE;
			for (int i = 0; i < arr.length; i++) {
				arr[i] = nextLong();
				max = Math.max(arr[i], max);
			}

			long res = -1;
			int cntRes = 0;
			if (arr.length <= 1) {
				cntRes = 2;
			}
			else if (arr.length >= 3){
				long lim = 1;
				for (int i = 0; i < d; i++) {
					lim *= 10;
				}
				boolean[] isPrime = new boolean[(int) lim];
				Arrays.fill(isPrime, true);
				
				LinkedList<Integer> allPrime = new LinkedList<Integer>();
				for (int i = 2; i < isPrime.length; i++) {
					if (isPrime[i]) {
						allPrime.add(i);
						for(long j = ((long)i) * i; j < isPrime.length; j += i)
							isPrime[(int)j] = false;
					}
				}
				
				for (Integer p : allPrime) if (p > max) {
					long left = (arr[1] - arr[0]) % p;
					if (left < 0) left += p;
					
					long right = (arr[2] - arr[1]) % p;
					if (right < 0) right += p;
					
					long a = (right * inverse(left, p)) % p;
					long b = (arr[1] - (arr[0] * a) % p) % p;
					if (b < 0) b += p;
					
					if(isGood(a, b, p, arr)) {
						long newRes = (a * arr[arr.length-1] + b) % p;
						if (res != newRes)
							++cntRes;
						res = newRes;
						if (cntRes >= 2) break;
					}
				}
			}
			else {
				if (arr[0] == arr[1]) {
					cntRes = 1;
					res = arr[0];
				}
				else cntRes = 2;
			}
			
			writeCase(test);
			if (cntRes == 1)
				writer.println(res);
			else {
				writer.println("I don't know.");
			}
			writer.flush();
		}
	}
	
	private boolean isGood(long a, long b, int p, long[] arr) {
		long s = arr[0];
		for (int i = 1; i < arr.length; i++) {
			s = (a * s + b) % p;
			if (s != arr[i])
				return false;
		}
		return true;
	}
	
	private long inverse(long n, long mod) {
		return powerMod(n, mod-2, mod);
	}
	
	private long powerMod(long b, long e, long mod) {
		if (e==0) return (1%mod);
		else {
			long r = powerMod(b, e/2, mod);
			r = (r*r) % mod;
			if (e%2 > 0) r = (r * b) % mod;
			return r;
		}
	}
	
	private void writeCase(int test) {
		writer.printf("Case #%d: ", test+1);
	}
	void debug(Object...os) {
		System.out.println(Arrays.deepToString(os));
	}
	//--------------------- IO stuffs ---------------------
    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(new Main());
        thread.start();
        thread.join();
    }
	public void run() {
        try {
        	reader = _ReadFromFile ? new BufferedReader(new FileReader(IN_FILE)) : new BufferedReader(new InputStreamReader(System.in));
        	writer = _WriteToFile ? new PrintWriter(OUT_FILE) : new PrintWriter(new BufferedOutputStream(System.out));
            tokenizer = null;
            core();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }
    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
    String nextToken() throws Exception {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
