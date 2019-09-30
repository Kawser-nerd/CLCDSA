import java.util.*;

public class DSmall {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int C = sc.nextInt();
		for(int caseID = 1; caseID <= C; caseID++){
			int N = sc.nextInt();
			boolean[][] adjL = new boolean[N][N];
			for(int i = 0; i < N - 1; i++){
				int v1 = sc.nextInt() - 1;
				int v2 = sc.nextInt() - 1;
				adjL[v1][v2] = adjL[v2][v1] = true;
			}
			int M = sc.nextInt();
			boolean[][] adjS = new boolean[M][M];
			for(int i = 0; i < M - 1; i++){
				int v1 = sc.nextInt() - 1;
				int v2 = sc.nextInt() - 1;
				adjS[v1][v2] = adjS[v2][v1] = true;
			}

			int[] xs = new int[N];
			for(int i = 0; i < N; i++) xs[i] = i;

			boolean ans = false;
			while(true){
				boolean subisomorph = true;
				for(int i = 0; i < M; i++){
					for(int j = 0; j < M; j++){
						if(adjS[i][j] != adjL[xs[i]][xs[j]]){
							subisomorph = false;
						}
					}
				}

				if(subisomorph) ans = true;

				if(!nextPermutation(xs, 0, N)) break;
			}
			if(ans){
				System.out.printf("Case #%d: YES%n", caseID);
			}
			else{
				System.out.printf("Case #%d: NO%n", caseID);
			}
		}
	}

	static boolean nextPermutation(int[] a, int b, int e) {
		if ((e - b) < 2)
			return false;
		int p = e;
		e--;
		while (b != e) {
			int q = e;
			e--;
			if (a[e] < a[q]) {
				int r = p;
				while (!(a[e] < a[--r]))
					;
				swap(a, e, r);
				reverse(a, q, p);
				return true;
			}
		}
		reverse(a, b, p);
		return false;
	}

	private static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	private static void reverse(int[] a, int b, int e) {
		while (b < e) {
			e--;
			swap(a, b, e);
			b++;
		}
	}
}
