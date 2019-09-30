import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int Q = sc.nextInt();
				
		int[] map = new int[N+1];
		for (int i = 0; i < Q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			map[l-1]++;
			map[r]--;
		}
		
		int[] isumo = new int[N];
		isumo[0] = map[0];
		for (int i = 1; i < N; i++) {
			isumo[i] = map[i] + isumo[i-1];
		}
		
		for (int pos : isumo) {
			System.out.print(pos % 2);	
		}
		
		System.out.println();
	}

}