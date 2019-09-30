import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	long pw(long A, long B, long P) {
		if (B==0) return 1 % P;
		long res = pw(A, B/2, P);
		res = (res * res) % P;
		if (B%2==1) res = (res*A) % P;
		return res;
	}
	long inv(long A, long P) {
		A = ((A % P) + P) % P;
		return pw(A, P-2, P);
	}
	public void doMain() throws Exception {
		boolean[] isPrime = new boolean[1000001];
		Arrays.fill(isPrime, true);
		for (int i=2; i<=1000000; i++)
			if (isPrime[i])
				for (int j=i+i; j<=1000000; j+=i)
					isPrime[j] = false;
			
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {			
			pw.print("Case #" + caseNum + ": ");
			
			int D = sc.nextInt();
			int K = sc.nextInt();
			long[] A = new long[K];
			for (int i=0; i<K; i++)
				A[i] = sc.nextLong();
						
			if (K == 1) {
				pw.println("I don't know.");
			} else if (K == 2) {
				pw.println(A[0] == A[1] ? A[0] : "I don't know.");
			} else {
				if (A[0] == A[1]) {
					boolean ok = true;
					for (int i=2; i < K; i++)
						if (A[i] != A[0]) ok = false;
					pw.println(ok ? A[0] : "I don't know.");
				} else {
					long next = -1;
					
					int bnd = 1;
					for (int i=0; i<D; i++) bnd*=10;
					for (int P=2; P<=bnd; P++) {
						if (!isPrime[P]) continue;
						
						boolean find = false;
						for (int i=0; i<K; i++)
							if (A[i] >= P) find = true;
						if (find) continue;
						
						long AA = ((A[2] - A[1]) % P + P) % P;
						AA = (AA * inv(A[1] - A[0], P)) % P;
						
						long BB = ((A[1] - A[0] * AA) % P + P) % P;
						
						//System.out.println(P + " " + AA + " " + BB);
						
						boolean ok = true;
						for (int i=1; i<K; i++) {
							long val = (A[i-1] * AA + BB) % P;
							if (val != A[i]) {
								ok = false;
								if (i <= 2) System.out.println("Something is done wrong");
							}
						}
						
						if (ok) {
							long tmp = (A[K-1] * AA + BB) % P;
							if (next==-1) next = tmp;
							else if (next!=tmp) next = -2;
						}
					}
					
					if (next==-1) System.out.println("The sequence is bad");
					
					
					pw.println(next>=0 ? next : "I don't know.");
				}
			}
		
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}