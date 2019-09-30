import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int r = scanner.nextInt();
				int c = scanner.nextInt();
				int w = scanner.nextInt();
				int perRow = c / w;
				int result = r*perRow;
				if (c % w == 0) {
					result--;
				}
				result += w;
				out.write("Case #" + (i + 1) + ": " + result + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}