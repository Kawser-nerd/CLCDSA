import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	Scanner sc;
	PrintWriter pw;
	int caseCnt, caseNum;
	
	int globalId = 0;
	
	int res;
	
	Map<Triangle, Integer> memo;
	
	class Triangle {
		int id;
		
		int a, b, c, d, e, f;
		boolean prim1, prim2, prim3;
		
		List<Triangle> aa;
		List<Triangle> bb;
		List<Triangle> cc;
		
		public Triangle(int a, int b, int c, int d, int e, int f, boolean prim1, boolean prim2, boolean prim3) {
			this.id = globalId++;
			
			this.a = a;
			this.b = b;
			this.c = c;
			this.d = d;
			this.e = e;
			this.f = f;
			
			this.prim1 = prim1;
			this.prim2 = prim2;
			this.prim3 = prim3;
			
			this.aa = new ArrayList<Triangle>();
			this.bb = new ArrayList<Triangle>();
			this.cc = new ArrayList<Triangle>();
			
			all.add(this);
		}
		
		public boolean equals(Object other) {
			return this.id == ((Triangle)other).id;
		}
		
		public int hashCode() {
			return id * 1000000007;
		}
	}
	
	List<Triangle> all;
	
	int N;
	
	void inputData() throws Exception  {
		all = new ArrayList<Triangle>();
		
		new Triangle(1, 2, 1, 3, 2, 3, true, true, true);
		
		N = sc.nextInt();
		for (int i=4; i<=N; i++) {
			int x = sc.nextInt(), y = sc.nextInt();
			if (x>y) {int tmp = x; x = y; y = tmp;}
			
			Triangle next = new Triangle(x, y, x, i, y, i, false, true, true);
			
			for (Triangle tt : all) {
				if (tt.equals(next)) continue;
				if (tt.a == x && tt.b == y /* && tt.prim1*/) {
					tt.aa.add(next);
					next.aa.add(tt);
				} else if (tt.c == x && tt.d == y /*&& tt.prim2*/) {
					tt.bb.add(next);
					next.aa.add(tt);
				} else if (tt.e == x && tt.f == y /*&& tt.prim3*/) {
					tt.cc.add(next);
					next.aa.add(tt);
				}
			}
		}
	}
	
	int rec1(Triangle t, int x, int y) {
		int ca = 2, cb = 2, cc = 2;
		
		if (t.a == x && t.b == y) ca = 0; else
		for (Triangle tt : t.aa)
			ca = Math.max(ca, rec1(tt, t.a, t.b));
		
		if (t.c == x && t.d == y) cb = 0; else
		for (Triangle tt : t.bb)
			cb = Math.max(cb, rec1(tt, t.c, t.d));
		
		if (t.e == x && t.f == y) cc = 0; else
		for (Triangle tt : t.cc)
			cc = Math.max(cc, rec1(tt, t.e, t.f));
		
		return ca + cb + cc - 1;
	}
	
	int rec(Triangle t) {
		int ca = 2, cb = 2, cc = 2;
		
		for (Triangle tt : t.aa)
			ca = Math.max(ca, rec1(tt, t.a, t.b));
		
		for (Triangle tt : t.bb)
			cb = Math.max(cb, rec1(tt, t.c, t.d));
		
		for (Triangle tt : t.cc)
			cc = Math.max(cc, rec1(tt, t.e, t.f));
		
		return ca + cb + cc - 3;
	}
	
	void solveProblem() {
		res = 0;
		for (Triangle tt : all) {
			//System.out.println(tt.a + " " + tt.b + " " + tt.c + " " + tt.d + " " + tt.e + " " + tt.f + " " + rec(tt));
			res = Math.max(res, rec(tt));
		}
	}
	
	void outputData() {
		pw.print("Case #" + caseNum + ": ");
		
		pw.print(res);
		
		pw.println();
	}
	
	public void go() throws Exception {
		sc = new Scanner(new FileReader("input.txt"));
		pw = new PrintWriter(new FileWriter("output.txt"));
		
		caseCnt = sc.nextInt();
		for (caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			inputData();
			solveProblem();
			outputData();
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}