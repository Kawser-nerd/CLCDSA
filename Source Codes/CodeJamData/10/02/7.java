import java.util.*;
import java.math.*;
import java.io.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int T = sc.nextInt();
		for (int t=0; t<T; t++) {
			int N = sc.nextInt();
			BigInteger[] A = new BigInteger[N];
			for (int i=0; i<N; i++)
				A[i] = new BigInteger(sc.next());
			Arrays.sort(A);
			BigInteger res = A[1].subtract(A[0]);
			for (int i=2; i < N; i++)
				res = res.gcd(A[i].subtract(A[i-1]));
			BigInteger add = res.subtract(A[0].remainder(res)).remainder(res);
			pw.println("Case #" + (t+1) + ": " + add);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}
