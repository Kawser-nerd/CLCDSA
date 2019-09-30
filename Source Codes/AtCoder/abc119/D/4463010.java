import java.util.*;
import java.io.*;

public class Main {
	
	static int[] w;
	
	public static int steps(int value, int goal) {
		System.out.println(value+" "+goal);
		if (value==goal) return 0;
		else {
			int min = 1<<30;
			if (value >= 2 && value > goal) min = Math.min(min, steps(value-1 , goal) + 1);
			if (value < goal) min = Math.min(min, steps(value+1 , goal) + 1);
			for (int i=0; i<w.length; i++) {
				min = Math.min(min, steps(value + w[i] , goal) + 10);
			}
			return min;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int a = sc.nextInt(), b = sc.nextInt(), q = sc.nextInt();
		
		TreeSet<Long> shrines = new TreeSet<Long>(),
				temples = new TreeSet<Long>();
		
		for (int i=0; i<a; i++) shrines.add(sc.nextLong());
		for (int i=0; i<b; i++) temples.add(sc.nextLong());
		
		for (int i=0; i<q; i++) {
			long s = sc.nextLong();
			Long leftS = shrines.floor(s), rightS = shrines.ceiling(s),
					leftT = temples.floor(s), rightT = temples.ceiling(s);
			if (leftS==null) leftS = -1L<<60; 
			if (leftT==null) leftT = -1L<<60; 
			if (rightS==null) rightS = 1L<<60; 
			if (rightT==null) rightT = 1L<<60; 
			//both left
			long min = Math.max(s-leftS, s-leftT);
			//both right
			min = Math.min(min, Math.max(rightS-s, rightT-s));
			//leftS, rightT
			min = Math.min(min, (s-leftS) + (rightT-s) + Math.min((s-leftS), (rightT-s)));
			//leftT, rightS
			min = Math.min(min, (s-leftT) + (rightS-s) + Math.min((s-leftT), (rightS-s)));
			System.out.println(min);
			
		}
		
		//topcoders, codeforces, aiio(australian judges), atcoders, codechef
		
		
//		int n = sc.nextInt(), mp = 0;
//		int[] goals = new int[3];
//		for (int i=0; i<3; i++) goals[i] = sc.nextInt();
//
//		w = new int[n];
//		
//		for (int i=0; i<n; i++) {
//			w[i] = sc.nextInt();
//			
//		}
//	
//		
//		
//		for (int l=0; l<3; l++) {
//			int r = 1<<30;
//			for (int i=0; i<n; i++) {
//				r = Math.min(r, steps(w[i],goals[l]));
//			}
//			mp += r;
//		}
//		
//		System.out.println(mp);
		
		




		//		int[] w = new int[n];
		//		for (int i=0; i<n; i++) {
		//			w[i] = sc.nextInt();
		//			for (int l=0; l<3; l++) {
		//				if (w[i]==goals[l]) {
		//					goals[l] = -1;
		//					w[i] = 1<<30;
		//				}
		//			}
		//		}
		//
		//		for (int i=0; i<n; i++) {
		//			for (int l=0; l<3; l++) {
		//				if (goals[l]>0 && Math.abs(goals[l]-w[i])<=10) {
		//					goals[l] = -1;
		//					w[i] = 1<<30;
		//					mp += Math.abs(goals[l]-w[i]);
		//				}
		//			}
		//		}
		//
		//		for (int l=0; l<3; l++) {
		//			if (goals[l]==-1) continue;
		//			int min = 1<<30;
		//			int get = goals[l];
		//			for (int i=0; i<n-1; i++) {
		//				for (int q=i+1; q<n; q++) {
		//					int first = w[i], second = w[q];
		//					if (min > Math.abs(get - (first+second))) {
		//						min = Math.abs(get - (first+second));
		//					}
		//
		//				}
		//
		//			}
		//			mp += min;
		//		}
		//		System.out.println(mp);





	}
}