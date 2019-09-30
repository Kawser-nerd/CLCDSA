import java.util.*;

public class C {
	static int K;
	static int[] P;
	
	static int N;
	static int M;
	static int[] best_array = null;
	static int best_score = 0;
	static void f(int[] A, int i) {
		if(i==N) {
			int score = 1;
			int[] freq = new int[126];
			for(int set=0; set<(1<<N); set++) {
				int product = 1;
				for(int j=0; j<N; j++)
					if(bit_set(set, j))
						product *= A[j];
				freq[product]++;
			}
			for(int j=0; j<K; j++) {
			//	System.out.println(P[j]+" "+freq[P[j]]);
				score *= freq[P[j]];
			}
			//System.out.println(score+" "+Arrays.toString(A)+" "+Arrays.toString(P));
			if(score > best_score) {
				best_score = score;
				for(int j=0; j<N; j++)
					best_array[j] = A[j];
			}
		} else {
			for(int d=2; d<=M; d++) {
				A[i] = d;
				f(A, i+1);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int R = in.nextInt();
		N = in.nextInt();
		M = in.nextInt();
		K = in.nextInt();
		
		System.out.printf("Case #1:\n");
		for(int t=0; t<R; t++) {
			P = new int[K];
			for(int j=0; j<K; j++)
				P[j] = in.nextInt();
			best_score = 0;
			best_array = new int[N];
			for(int i=0; i<N; i++) best_array[i] = 2;
			
			f(new int[N], 0);
			for(int i=0; i<N; i++)
				System.out.print(best_array[i]);
			System.out.println();
		}
	}
	static boolean bit_set(int set, int bit) {
		return ((set>>bit)&1)==1;
	}
}
