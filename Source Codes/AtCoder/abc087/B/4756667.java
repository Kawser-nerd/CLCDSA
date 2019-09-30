import java.util.*;

/**
 * @author fujino0429
 *
 */
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 500??100??50??????????????
		int pieceNumOf500yen = sc.nextInt() + 1;
		int pieceNumOf100yen = sc.nextInt() + 1;
		int pieceNumOf50yen = sc.nextInt() + 1;
		// ????X????????
		int totalX = sc.nextInt();

		//
		int[][][] resultSet = new int[pieceNumOf500yen][pieceNumOf100yen][pieceNumOf50yen];
		int count = 0;

		for (int i = 0; i < resultSet.length; i++) {
			for (int j = 0; j < resultSet[i].length; j++) {
				for (int k = 0; k < resultSet[i][j].length; k++) {
					if (totalX == 500 * i + 100 * j + 50 * k) {
						count++;
					}
				}

			}

		}
		System.out.println(count);

		sc.close();
	}
}