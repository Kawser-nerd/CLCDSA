import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// ????
		Scanner sc = new Scanner(System.in);

		String line = sc.nextLine();
		List<String> lines = Arrays.asList(line.split(" "));

		/*
		List<String> lines1 = Arrays.asList(line1.split(" "));
		List<String> lines2 = Arrays.asList(line2.split(" "));
		*/

		Long x = Long.parseLong(lines.get(0));
		Long y = Long.parseLong(lines.get(1));

		Long ans = (long) 0;

		while (x <= y) {
			ans++;
			x = x * 2;

		}

		System.out.println(ans);
	}

}