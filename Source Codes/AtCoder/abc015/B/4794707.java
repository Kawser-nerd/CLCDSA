import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = Integer.parseInt(scanner.nextLine());
		String[] a = scanner.nextLine().split(" ");
		scanner.close();

		double haveBug = 0;
		double sumBug = 0;
		for (String bugNumStr : a) {
			int bugNum = Integer.parseInt(bugNumStr);
			if (bugNum != 0) {
				haveBug++;
				sumBug += bugNum;
			}
		}

		double avg = sumBug / haveBug;
		int avgCeiled = (int)Math.ceil(avg);

		System.out.println(avgCeiled);
	}

}