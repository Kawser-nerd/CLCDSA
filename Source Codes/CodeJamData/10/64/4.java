import java.util.*;
import java.io.*;
import java.math.*;

// to run with -Xmx1024m

public class Solution {
	Scanner sc;
	PrintWriter pw;
	int caseCnt, caseNum;
	
	long F;
	int N;
	long[] X;
	
	void inputData() throws Exception  {
		// some code here
		N = sc.nextInt();
		X = new long[N];
		for (int i=0; i<N; i++)
			X[i] = sc.nextLong();
		F = sc.nextLong();
		
		Arrays.sort(X);
	} 
	
	long res;
	
	char[] c;
	
	int border;
	
	List<List<Long>> left;
	List<List<Long>> right;
	
	void rec(int pos, int balance, long have) {
		if (pos == border) {
			left.get(balance).add(have);
			return;
		}
		
		rec(pos + 1, balance, have);
		rec(pos + 1, balance + 1, have - 2 * X[pos]);
		if (balance > 1) rec(pos + 1, balance - 1, have + 2 * X[pos]);
	}
	
	void rec1(int pos, int ini, int balance, long have) {
		if (pos == N) {
			if (balance == 0) right.get(ini).add(have);
			return;
		}
		
		if (pos == N-1) {
			if (balance > 0) rec1(pos+1, ini, balance-1, have + 2 * X[pos]);
			return;
		}
		
		rec1(pos+1, ini, balance, have);
		rec1(pos+1, ini, balance+1, have - 2*X[pos]);
		if (balance>1) rec1(pos+1, ini, balance-1, have + 2*X[pos]);
	}
	
	void solveProblem() {
		border = N/2;
		left = new ArrayList<List<Long>>();
		right = new ArrayList<List<Long>>();
		for (int i=0; i <= border; i++) {
			left.add(new ArrayList<Long>());
			right.add(new ArrayList<Long>());
		}
		
		rec(1, 1, -2 * X[0]);
		
		for (int b=0; b <= border; b++)
			rec1(border, b, b, 0);	
		
		res = 0;
		
		for (int i=0; i <= border; i++) {
			Collections.sort(left.get(i));
			Collections.sort(right.get(i));
			
			int l = 0, r = right.get(i).size() - 1;
			while (l < left.get(i).size() && r >= 0) {
				if (left.get(i).get(l) + right.get(i).get(r) <= F) {
					res = Math.max(res, left.get(i).get(l) + right.get(i).get(r));
					l++;
				} else r--;
			}
		}
	}
	
	void outputData() {
		pw.print("Case #" + caseNum + ": ");
		
		pw.print(res == 0 ? "NO SOLUTION" : res);		
		
		pw.println();
	}
	
	public void go() throws Exception {
		sc = new Scanner(new FileReader("input.txt"));
		pw = new PrintWriter(new FileWriter("output.txt"));
		
		caseCnt = sc.nextInt();
		for (caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("case " + caseNum);
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