import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Bai1 {
	
	static class Segment implements Comparable<Segment>{
		double v, len;
		
		double st, fn;
		
		Segment(double st, double fn, double v) {
			this.st = st;
			this.fn = fn;
			this.len = fn - st;
			this.v = v;
		}
		
		public int compareTo(Segment s) {
			if(v<s.v) return -1;
			else if(v == s.v) return 0;
			else return 1;
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		// Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Alarge.out"));
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {
			
			double x = sc.nextDouble();
			double walk = sc.nextDouble();
			double run = sc.nextDouble();
			double more = run - walk;
			
			double t = sc.nextDouble();
			
			int n = sc.nextInt();
			ArrayList<Segment> list = new ArrayList<Segment>();
			Segment[] a = new Segment[n];
			
			for(int i=0;i<n;++i) {
				double b = sc.nextDouble();
				double e = sc.nextDouble();
				double v = sc.nextDouble();
				
				a[i] = new Segment(b, e, v + walk);
			}
			
			Arrays.sort(a, new Comparator<Segment>(){
				public int compare(Segment s1, Segment s2) {
					if(s1.st < s2.st) return -1;
					else if(s1.st == s2.st) return 0;
					else return 1;
				}
			});
			
			if(a[0].st > 0) list.add(new Segment( 0, a[0].st, walk));
			for(int i=0;i<n;++i) {
				if(i > 0) {
					if(a[i].st > a[i-1].fn) list.add(new Segment(a[i-1].fn, a[i].st, walk));
				}
				list.add(a[i]);
			}
			
			if(a[n-1].fn < x) list.add(new Segment(a[n-1].fn, x, walk));
			
			Collections.sort(list);
			
			double total = 0;
			for(Segment s : list) total += s.len / s.v;
			
			for(Segment s : list) {
				double time = Math.min( t, s.len / (s.v + more));
				double len = time * (s.v + more);
				total -= len / s.v;
				total += time;
				t -= time;
			}

			pw.print("Case #" + test + ": ");
			
			pw.printf("%.8f", total);
			
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
