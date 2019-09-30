import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner();
		int base = 0;
		int n = sc.nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; ++i) {
			b[i] = sc.nextInt();
			if (b[i] == 0)
				++base;
		}
		int Q = sc.nextInt();
		int[][] q = new int[Q][2];
		for (int i = 0; i < Q; ++i) {
			q[i][0] = sc.nextInt();
			q[i][1] = sc.nextInt();
		}
		Arrays.sort(q, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
		RMQ rmq = new RMQ(n + 1);
		rmq.set(0, 0);
		int p = 0;
		for (int i = 0; i < Q; ++i) {
			while (q[i][0] - p > 1) {
				int c = b[p] == 1 ? 1 : -1;
				rmq.set(p + 1, Math.min(c + rmq.query(p), rmq.query(p + 1)));
				++p;
			}
			rmq.set(q[i][1], rmq.query(p, q[i][1] + 1));
		}
		while (n - p > 0) {
			int c = b[p] == 1 ? 1 : -1;
			rmq.set(p + 1, Math.min(c + rmq.query(p), rmq.query(p + 1)));
			++p;
		}
		System.out.println(base + rmq.query(n));
	}

	class RMQ {
		int n;
		int[] v;

		public RMQ(int n_) {
			n = 1;
			while (n < n_)
				n *= 2;
			v = new int[2 * n];
			Arrays.fill(v, Integer.MAX_VALUE / 3);
		}

		void add(int k, int val) {
			k += n;
			v[k] += val;
			while (k > 1) {
				k >>= 1;
				v[k] = Math.min(v[2 * k], v[2 * k + 1]);
			}
		}

		void set(int k, int val) {
			k += n;
			v[k] = val;
			while (k > 1) {
				k >>= 1;
				v[k] = Math.min(v[2 * k], v[2 * k + 1]);
			}
		}

		int query(int a) {
			return v[a + n];
		}

		int query(int a, int b) {
			a += n;
			b += n;
			int ret = Integer.MAX_VALUE / 3;
			while (a < b) {
				if ((a & 1) > 0) {
					ret = Math.min(ret, v[a++]);
				}
				if ((b & 1) > 0) {
					ret = Math.min(ret, v[--b]);
				}
				a >>= 1;
				b >>= 1;
			}
			return ret;
		}

	}
	
	class Scanner {
	    private final InputStream in = System.in;
	    private final byte[] buffer = new byte[1024];
	    private int ptr = 0;
	    private int buflen = 0;
	    private boolean hasNextByte() {
	        if (ptr < buflen) {
	            return true;
	        }else{
	            ptr = 0;
	            try {
	                buflen = in.read(buffer);
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	            if (buflen <= 0) {
	                return false;
	            }
	        }
	        return true;
	    }
	    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
	    private boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
	    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
	    public String next() {
	        if (!hasNext()) throw new NoSuchElementException();
	        StringBuilder sb = new StringBuilder();
	        int b = readByte();
	        while(isPrintableChar(b)) {
	            sb.appendCodePoint(b);
	            b = readByte();
	        }
	        return sb.toString();
	    }
	    public int nextInt() {
	        if (!hasNext()) throw new NoSuchElementException();
	        int n = 0;
	        boolean minus = false;
	        int b = readByte();
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        if (b < '0' || '9' < b) {
	            throw new NumberFormatException();
	        }
	        while(true){
	            if ('0' <= b && b <= '9') {
	                n *= 10;
	                n += b - '0';
	            }else if(b == -1 || !isPrintableChar(b)){
	                return minus ? -n : n;
	            }else{
	                throw new NumberFormatException();
	            }
	            b = readByte();
	        }
	    }
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}