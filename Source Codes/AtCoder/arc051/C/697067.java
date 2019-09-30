import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

	public static long MOD = 1000000007;
	public static int a;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		a = sc.nextInt();
		int b = sc.nextInt();
		if (a == 1) {
			int[] x = new int[n];
			for(int i=0;i<n;i++) {
				x[i] = sc.nextInt();
			}
			Arrays.sort(x);
			for(int i=0;i<n;i++) {
				System.out.println(x[i]);
			}
			return;
		}
		Number[] x = new Number[n];
		TreeSet<Number> ts = new TreeSet<>();
		for(int i=0;i<n;i++) {
			x[i] = new Number(i,sc.nextInt(),0);
			ts.add(x[i]);
		}

		while(b > 0) {
			Number min = ts.first();
			Number max = ts.last();
			if (b > 100 && new Number(-1,min.x,min.y+1).compareTo(max) > 0) {
				int d = b / n;
				for(int i=0;i<n;i++) {
					x[i].y += d;
				}
				b -= d * n;
				continue;
			}
			ts.pollFirst();
			min.y++;
			ts.add(min);
			b--;
		}
		
		for(Number num: ts) {
			System.out.println(num.x * pow(a, num.y, MOD) % MOD);
		}
	}
	
	public static long pow(long a,long n,long mod) {
		long res = 1;
		while(n > 0) {
			if ((n & 1) > 0) {
				res = (res * a) % mod;
			}
			a = (a * a) % mod;
			n/=2;
		}
		return res;
	}

	static class Number implements Comparable<Number>{
		int i;
		long x,y;
		public Number(int i,long x,long y) {
			this.i = i;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Number o) {
			int c = compareIgnoreId(o);
			if (c != 0) return c;
			return Integer.compare(i, o.i);
		}
		
		public int compareIgnoreId(Number o) {
			if (y > o.y) return -o.compareTo(this);
			long x2 = o.x;
			for(int i=0;i<o.y-y&&x2<=x;i++) {
				x2 *= a;
			}
			return Long.compare(x, x2);
		}
		
		
	}

}