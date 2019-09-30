import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String sol = sc.next();
		sc.close();
		String[] sols = sol.split("");
		int one = 0;
		int two = 0;
		int three = 0;
		int four = 0;

		for (int i = 0; i < num; i++) {
			switch (sols[i]) {
			case "1":
				one++;
				break;
			case "2":
				two++;
				break;
			case "3":
				three++;
				break;
			case "4":
				four++;
				break;
			}
		}
		int[] arr = { one, two, three, four };
		Arrays.sort(arr);
		String result = arr[3] + " " + arr[0];
		System.out.println(result);
	}
}