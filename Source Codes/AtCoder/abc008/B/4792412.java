import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		ArrayList<String> names = new ArrayList<String>();
		ArrayList<String> votes = new ArrayList<String>();
		for (int i = 0; i <= n; i++) {
			String name = scanner.nextLine();
			if (!names.contains(name)) {
				names.add(name);
			}
			votes.add(name);
		}
		scanner.close();

		String mostName = "";
		int mostNum = 0;
		for (String name : names) {
			int count = 0;
			for (String vote : votes) {
				if (vote.equals(name)) {
					count++;
				}
				if (count >= mostNum) {
					mostName = name;
					mostNum = count;
				}
			}
		}

		System.out.println(mostName);
	}

}