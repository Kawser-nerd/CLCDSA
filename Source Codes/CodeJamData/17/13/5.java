import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class C {
	
	static class Solver extends Thread {
		Object result;
		private int Hd;
		private int Ad;
		private int Hk;
		private int Ak;
		private int B;
		private int D;
		
		void read(Scanner sc) {
			Hd = sc.nextInt();
			Ad = sc.nextInt();
			Hk = sc.nextInt();
			Ak = sc.nextInt();
			B = sc.nextInt();
			D = sc.nextInt();
		}
		
		Object solve() {
			HashSet<State> vis = new HashSet<>();
			
//			boolean[][][][] vis = new boolean[Hd+1][Ad+1][Hk+1][Ak+1];
//			int[][][][] dist = new int[Hd+1][Ad+1][Hk+1][Ak+1];
//			for (int[][][] ddd : dist)
//				for (int[][] dd : ddd)
//					for (int [] d : dd)
//						Arrays.fill(d, -1);
			
			Queue<State> q = new LinkedList<>();
			q.add(new State(Hd, Ad, Hk, Ak, 0));
			
			while (!q.isEmpty()) {
				State s = q.poll();
				
				if (s.Hk == 0)
					return s.n;
//					return dist[s.Hd][s.Ad][s.Hk][s.Ak];
				
				if (vis.contains(s))
					continue;
				
				vis.add(s);
				
//				if (vis[s.Hd][s.Ad][s.Hk][s.Ak])
//					continue;
//				vis[s.Hd][s.Ad][s.Hk][s.Ak] = true;
				
				{
					int Hk = Math.max(0, s.Hk - s.Ad);
					add(q, s, s.Hd, s.Ad, Hk, s.Ak);
				}
				{
					add(q, s, s.Hd, s.Ad + B, s.Hk, s.Ak);
				}
				{
					add(q, s, Hd, s.Ad, s.Hk, s.Ak);
				}
				{
					int Ak = Math.max(0, s.Ak - D);
					add(q, s, s.Hd, s.Ad, s.Hk, Ak);
				}
			}
			
			return "IMPOSSIBLE";
		}

		private void add(Queue<State> q, State s, int hd, int ad, int hk, int ak) {
			if (hk > 0)
				hd = Math.max(0, hd - ak);
			if (hd > 0)
				q.add(new State(hd, ad, hk, ak, s.n+1));
		}
		
		static class State {
			int Hd;
			int Ad;
			int Hk;
			int Ak;
			int n;
			
			public State(int hd, int ad, int hk, int ak, int n) {
				Hd = hd;
				Ad = ad;
				Hk = hk;
				Ak = ak;
				this.n = n;
			}
			@Override
			public int hashCode() {
				final int prime = 31;
				int result = 1;
				result = prime * result + Ad;
				result = prime * result + Ak;
				result = prime * result + Hd;
				result = prime * result + Hk;
				return result;
			}
			@Override
			public boolean equals(Object obj) {
				if (this == obj)
					return true;
				if (obj == null)
					return false;
				if (getClass() != obj.getClass())
					return false;
				State other = (State) obj;
				if (Ad != other.Ad)
					return false;
				if (Ak != other.Ak)
					return false;
				if (Hd != other.Hd)
					return false;
				if (Hk != other.Hk)
					return false;
				return true;
			}
		}
		
		public void run() {
			result = solve();
			synchronized (sync) {
				remaining--; running--;
				startNextCase();
				System.out.println("Remaining: " + remaining + ", Running: " + running);
				if (finished())
					sync.notifyAll();
			}
		}
	}


	private static final int MAX_THREADS = 32;
	private static Object sync = new Object(); static int running, remaining, next; 
	private static ArrayList<Solver> cases = new ArrayList<Solver>(); 

	public static void main(String[] args) throws Exception {
		Scanner sc; PrintWriter fw; 
		String inFile = "input.txt", outFile = "output.txt";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false));
		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			Solver solver = new Solver();
			solver.read(sc);
			remaining++;
			cases.add(solver);
		}
		
		for (int i = 0; i < Math.min(N, MAX_THREADS); i++)
			startNextCase();
		System.out.println("Remaining: " + remaining + ", Running: " + running);
		
		while (!finished()) {
			synchronized (sync) {
				sync.wait(1000);
			}
		}
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
			Object res = cases.get(cas-1).result;
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

	static boolean finished() {
		synchronized (sync) {
			return remaining == 0;
		}
	}
	
	static void startNextCase() {
		synchronized (sync) {
			if (remaining > running) {
				cases.get(next++).start();
				running++;
			}
		}
	}
}
