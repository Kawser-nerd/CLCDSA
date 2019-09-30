import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int N = sc.nextInt();
		int K = sc.nextInt();
		char[] S = sc.next().toCharArray();

		boolean[] a = new boolean[N];
		for(int i=0; i<N; i++)
			a[i] = S[i]=='A';
		boolean flip = false;
		int idx = 0;
		
		int T = Math.min(2*N, K);
		for(int i=0; i<T; i++) {
			if(a[idx]^flip) {
				a[idx] = false^flip;
			} else {
				flip ^= true;
				a[idx] = true^flip;
				idx = (idx+1)%N;
			}
		}
		if(T<K && N%2==1)
			a[idx] ^= (K-T)%2==1;
		
		for(int i=0; i<N; i++)
			pw.print(a[(i+idx)%N] ^ flip ? 'A' : 'B');
		pw.println();
		
		
		sc.close();
		pw.close();
	}
}