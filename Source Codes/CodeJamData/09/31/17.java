import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class P1 {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream("A-large.in"));

		int cnt = s.nextInt();

		for (int cases = 0; cases < cnt; cases++) {
			String buf = s.next();
			long num = 0;
			int bb = -1;

			int[] ar = new int[buf.length()];
			HashMap<String, Integer> set = new HashMap<String, Integer>();
			set.put(buf.substring(0, 1), 1);

			for (int i = 0; i < buf.length(); i++) {
				if (set.containsKey(buf.substring(i, i + 1))) {
					ar[i] = set.get(buf.substring(i, i + 1));
				} else {
					bb++;
					if (bb == 1) {
						bb = 2;
					}
					set.put(buf.substring(i, i + 1), bb);
					ar[i] = bb;
				}
			}

			bb++;
			if (bb < 2) {
				bb = 2;
			}
			for (int i = 0; i < buf.length(); i++) {
				long temp = 1;
				for (int j = 0; j < buf.length() - i - 1; j++) {
					temp = temp * (long) bb;
				}
				num += (long) ar[i] * temp;
			}

			System.out.println("Case #" + (cases + 1) + ": " + num);
		}
	}
}
