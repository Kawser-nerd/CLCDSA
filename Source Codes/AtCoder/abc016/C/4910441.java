import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		boolean[][] fri = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			fri[a][b] = true;
			fri[b][a] = true;
		}
		sc.close();

		for (int i = 0; i < n; i++) {
			Set<Integer> frifri = new HashSet<Integer>();
			for (int j = 0; j < n; j++) {
				if (fri[i][j]) {
					for (int k = 0; k < n; k++) {
						if (fri[j][k] && i != k && !fri[i][k]) {
							frifri.add(k);
						}
					}
				}
				
			}
			System.out.println(frifri.size());
		}
	}
}