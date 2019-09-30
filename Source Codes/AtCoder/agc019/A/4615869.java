import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long price[] = {sc.nextLong(), sc.nextLong(), sc.nextLong(), sc.nextLong()};
		int pow[] = {8, 4, 2, 1};
		long best[] = new long[2];
		for(int i = 0; i < 2; i ++) {
			best[i] = price[0] * pow[i];
			for(int j = 0; i + j < 4; j ++) {
				best[i] = Math.min(best[i], price[j] * pow[i + j]);
			}
		}
		long need = sc.nextLong();
		System.out.println(need / 2 * best[0] + need % 2 * best[1]);
	}
}