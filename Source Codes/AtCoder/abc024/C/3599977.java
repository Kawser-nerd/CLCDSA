import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int D = sc.nextInt();
		int K = sc.nextInt();
		int L[] = new int[D];
		int R[] = new int[D];
		for(int i = 0; i < D; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		int S[] = new int[K];
		int T[] = new int[K];
		int now[] = new int[K];
		int ans[] = new int[K];
		for(int i = 0; i < K; i++) {
			S[i] = sc.nextInt();
			now[i] = S[i];
			T[i] = sc.nextInt();
		}
		
		for(int i = 0; i < D; i++) {
			for(int j = 0; j < K; j++) {
				if(S[j] < T[j]) {
					if(now[j] != T[j] && L[i] <= now[j] && now[j] <= R[i]) {
						if(T[j] <= R[i]) {
							now[j] = T[j];
							ans[j] = i;
						} else {
							now[j] = R[i];
						}
					}
				} else {
					if(now[j] != T[j] && L[i] <= now[j] && now[j] <= R[i]) {
						if(L[i] <= T[j]) {
							now[j] = T[j];
							ans[j] = i;
						} else {
							now[j] = L[i];
						}
					}
				}
			}
		}
		for(int i = 0; i < K; i++) {
			System.out.println(ans[i] + 1);
		}
	}
}