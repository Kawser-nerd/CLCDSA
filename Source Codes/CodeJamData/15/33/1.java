import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output1.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				long c = scanner.nextLong();
				int d = scanner.nextInt();
				long v = scanner.nextLong();
				long[] values = new long[d];
				for (int j = 0; j < d; j++) {
					values[j] = scanner.nextLong();
				}
				long result = 0;
				long netWorth = 0;
				int j = 0;
				while(netWorth < v) {
					if (j < values.length && values[j] <= netWorth + 1) {
						netWorth += c*values[j];
						j++;
					}
					else {
						netWorth += c*(netWorth + 1);
						result++;
					}
				}
				out.write("Case #" + (i + 1) + ": " + result + "\n");
				out.flush();
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}