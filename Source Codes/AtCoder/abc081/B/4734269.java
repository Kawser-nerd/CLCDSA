import java.util.*;

/**
 * @author fujino0429
 *
 */
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// ?????
		int num = sc.nextInt();
		// 2??????????????????????????????????
		int result = 500000;
		// ????????
		for (int i = 0; i < num; i++) {
			int nextNum = sc.nextInt();
			int count = 0;
			while (nextNum % 2 == 0) {
				count++;
				nextNum /= 2;
			}
			result = Math.min(result, count);
		}
		System.out.println(result);

		sc.close();
	}
}