import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemC {
	int K;
	int[] s;
	
	void setBusy(int pos) {
		int x = pos;
		while (x <= K) {
			s[x]++;
			x = (x | (x - 1)) + 1;
		}
	}
	
	int get(int pos) {
		int x = pos, res = pos;
		while (x > 0) {
			res -= s[x];
			x &= (x - 1);
		}
		return res;
	}
	
	// number of free places in [st, fn], cyclically
	int getFree(int st, int fn) {
		if (st <= fn) return get(fn) - get(st-1);
		else return get(K) - get(st-1) + get(fn);		
	}
	
	// find T-th free place, starting from st, inclusive	
	int getTthFree(int st, int T) {
		int totFree = get(K);
		if (T % totFree == 0) T = totFree;
		else T %= totFree;
		int l = 0, r = K;
		while (r - l > 1) {
			int c = (l + r) / 2;
			int fn = st + c - 1;
			if (fn > K) fn -= K;
			int have = getFree(st, fn);
			if (have < T) l = c; else r = c;
		}
		int res = st + r - 1;
		if (res > K) res -= K;
		return res;
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ":");
			K = sc.nextInt();
			s = new int[K+1];
			int[] a = new int[K];
			int pos = 1;
			for (int i=1; i<=K; i++) {
				pos = getTthFree(pos, i);
				a[pos - 1] = i;
				setBusy(pos);
				pos++;
				if (pos==K+1) pos = 1;
			}
			int n = sc.nextInt();
			for (int i=0; i < n; i++) {
				int x = sc.nextInt();
				pw.print(" "+a[x-1]);
			}
			pw.println();
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}