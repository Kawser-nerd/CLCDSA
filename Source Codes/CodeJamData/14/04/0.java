import java.util.*;

public class d {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			int n = in.nextInt();
			double[] a = new double[n];
			double[] b = new double[n];
			for(int i=0; i<n; i++) a[i] = in.nextDouble();
			for(int i=0; i<n; i++) b[i] = in.nextDouble();
			
			int warScore = playWar(a, b);
			int decScore = playDecWar(a, b);
			System.out.printf("Case #%d: %d %d%n", t, decScore, warScore);
		}
	}
	static int playDecWar(double[] a, double[] b) {
		Arrays.sort(a);
		Arrays.sort(b);
		int ret = 0;
		for(int i=0; i<a.length; i++)
			ret = Math.max(ret, playDecWar(a, b, i));
		return ret;
	}
	static int playDecWar(double[] a, double[] b, int fakeout) {
		int ret = 0;
		int n = a.length;
		for(int i=0; i<fakeout; i++)
			if(a[i] > b[n-1-i])
				return -1;
		TreeSet<Double> left = new TreeSet<Double>();
		for(int i=0; i<n-fakeout; i++) left.add(b[i]);
		for(int i=fakeout; i<n; i++) {
			double x = a[i];
			Double first = left.first();
			if(x > first) {
				ret++;
				left.pollFirst();
			}
			else left.pollLast();
		}
		return ret;
	}
	static int playWar(double[] a, double[] b) {
		Arrays.sort(a);
		TreeSet<Double> left = new TreeSet<Double>();
		int ret = 0;
		for(double x : b) left.add(x);
		for(double x : a) {
			Double next = left.higher(x);
			if(next == null) ret++;
			else left.remove(next);
		}
		return ret;
	}
}