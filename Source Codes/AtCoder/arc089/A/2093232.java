import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// ????
		Scanner sc = new Scanner(System.in);

		String stN = sc.nextLine();
		int n = Integer.parseInt(stN);

		/*
		List<String> lines1 = Arrays.asList(line1.split(" "));
		List<String> lines2 = Arrays.asList(line2.split(" "));
		*/
		String line = null;
		List<String> lines = null;

		int t = 0;
		int x = 0;
		int y = 0;

		int nT = 0;

		int nX = 0;
		int nY = 0;
		int abs = 0;
		while (sc.hasNext()) {
			line = sc.nextLine();
			lines = Arrays.asList(line.split(" "));
			nT = Integer.parseInt(lines.get(0));
			nX = Integer.parseInt(lines.get(1));
			nY = Integer.parseInt(lines.get(2));
			abs = Math.abs(nX - x) + Math.abs(nY - y);
			if (abs == (nT - t)) {

			} else if (abs < (nT - t) && ((nT - t) - abs) % 2 == 0) {

			} else {
				System.out.println("No");
				return;
			}
			t = nT;
			x = nX;
			y = nY;
		}

		System.out.println("Yes");
	}

}