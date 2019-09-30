import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int taskCnt = sc.nextInt();
		int total = 0;

		for (int idx = 1; idx <= taskCnt; idx++) {
			total += idx;
		}

		System.out.println((total * 10000) / taskCnt);
		sc.close();
	}
}