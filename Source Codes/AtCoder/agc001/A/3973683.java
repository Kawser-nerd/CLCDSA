import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int spitCount = Integer.valueOf(scanner.nextLine()) * 2;

		int spits[] = new int[spitCount];
		for (int i = 0; i < spitCount; i++) {
			spits[i] = scanner.nextInt();
		}
		Arrays.sort(spits);
		int dishSum = 0;
		for (int i = 0; i < spitCount; i++) {
			if (i % 2 == 0) {
				dishSum += spits[i];
			}
		}
		System.out.println(dishSum);
	}

}