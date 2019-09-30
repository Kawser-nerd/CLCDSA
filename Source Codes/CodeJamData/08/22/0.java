import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemB {
	int[] p = new int[1000001], rank = new int[1000001];
	
	int root(int x) {
		if (p[x] != x)
			p[x] = root(p[x]);
		return p[x];
	}
	
	void union(int a, int b) {
		a = root(a);
		b = root(b);
		if (rank[a] < rank[b])
			p[a] = b;
		else {
			p[b] = a;
			if (rank[a] == rank[b])
				rank[a]++;
		}
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		boolean[] isPrime = new boolean[1000001];
		Arrays.fill(isPrime, true);
		for (int i=2; i<=1000000; i++)
			for (int j=2*i; j<=1000000; j+=i)
				isPrime[j] = false;
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			long A = sc.nextLong();
			long B = sc.nextLong();
			int P = sc.nextInt();
			for (int i=0; i < B - A + 1; i++) {
				p[i] = i;
				rank[i] = 0;
			}
			int res = (int)(B - A + 1);
			for (int i=P; i<=1000000; i++) {
				if (!isPrime[i]) continue;
				long x = A / i * i;
				if (x < A) x += i;
				x -= A;
				for (int y=(int)x; y < B - A + 1; y += i)
					if (root((int)x) != root(y)) {
						res--;
						union((int)x, y);
					}
			}
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemB()).doMain();
	}
}