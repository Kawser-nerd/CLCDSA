import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			int[] cList = init(scan);
			double ans = proc(cList);
			System.out.println(ans);

		}

	}

	public static int[] init(Scanner scan) {

		int n = scan.nextInt();
		int[] cList = new int[n];

		for (int i = 0; i < n; i++) {
			cList[i] = scan.nextInt();
		}
		return cList;
	}

	public static double proc(int[] cList) {

		double ans = 0;
		int size = cList.length;
		double temp = 0;

		for (int i = 0; i < size; i++) {
			temp = 0;
			for (int j = 0; j < size; j++) {
				if (cList[i] % cList[j] == 0 && i != j ) {
					temp++;
				}
			}

			if(temp == 0) {
				ans += 1.0;
			}else if ((temp) % 2.0 != 0) {
				ans += 0.5;
			} else {
				ans += (temp + 2.0) / (2.0 * temp + 2.0);
			}
		}

		return ans;
	}

}