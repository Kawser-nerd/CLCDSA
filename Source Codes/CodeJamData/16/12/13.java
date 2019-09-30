import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int C = in.nextInt();
		for (int thisCase = 1; thisCase <= C; thisCase++) {
			int counts[] = new int[2500];
			int N = in.nextInt();
			for (int i = 0; i < 2*N-1; i++) {
				for (int j = 0; j < N; j++) {
					counts[in.nextInt()-1]++;
				}
			}
			System.out.printf("Case #%d:", thisCase);
			for (int i = 0; i < 2500; i++) {
				if (counts[i] %2 == 1) {
					System.out.printf(" %d", (i+1));
				}
			}
			System.out.println();
		}
	}
}