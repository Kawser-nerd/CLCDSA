import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	private int next1(Integer[] a, int idx) {
		if(idx==-1) return -1;		
		for(int i=idx;i<a.length;i++) {
			if(a[i] == 1) {
				return i;		
			}
		}
		return -1;
	}
	
	private int last1(Integer[] a, int idx) {
		if(idx==-1) return -1;
		for(int i=idx;i<a.length;i++) {
			if(a[i] == 0) {
				return i-1;
			}
		}
		return -1;
	}
	
	private List<List<String>> seiri(Integer[] m) {

		List<List<String>> r = new ArrayList<>();

		int i = 0;
		while (true) {
			int lidx = next1(m, i);
			int ridx = last1(m, lidx+1);

			String ls, rs;

			if (lidx == -1) {
				break;
			}

			ls = idxToTime(lidx);

			if (ridx == -1) {
				rs = "2400";
				i = -1;
			} else {
				rs = idxToTime(ridx);
				i = ridx+1;
			}

			r.add(Arrays.asList(ls, rs));

		}

		return r;
	}

	private static int timeToIdx(int t) {
		int h = t/100;
		int m = t%100;
		return h*60 + m;
	}
	private static String idxToTime(int idx) {
		return String.format("%02d%02d", idx/60, (idx%60));
	}
	
	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();

		Integer[] m = new Integer[24*60+1];
		Arrays.fill(m, 0);
		
		for (int i = 0; i < n; i++) {
			String s = sc.next().trim();

			int lhs = Integer.parseInt(s.substring(0, 4));
			int rhs = Integer.parseInt(s.substring(5, 9));

			lhs -= lhs % 5;
			rhs += (5 - (rhs % 5)) % 5;

			Arrays.fill(m, timeToIdx(lhs), timeToIdx(rhs)+1, 1);

		}
//System.err.println(Arrays.asList(m));
		List<List<String>> result = seiri(m);
//System.err.println(result);
		for (List<String> rr : result) {
			out.println(rr.get(0) + "-" + rr.get(1));
		}

		sc.close();
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}