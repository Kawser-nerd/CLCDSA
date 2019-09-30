import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int n = scanner.nextInt();
				int l = scanner.nextInt();
				long[] devices = new long[n];
				long[] sources = new long[n];
				for (int j = 0; j < n; j++) {
					sources[j] = scanner.nextLong(2);
				}
				
				Set<Long> resultSet = new HashSet<Long>();
				for (int j = 0; j < n; j++) {
					devices[j] = scanner.nextLong(2);
					resultSet.add(devices[j]);
				}

				int lowest = 1000;
				for (int j = 0; j < sources.length; j++) {
					long diff = sources[j] ^ devices[0];
					Set<Long> currentSet = new HashSet<Long>();
					for (int k = 0; k < sources.length; k++) {
						currentSet.add(sources[k] ^ diff);
					}
					if (currentSet.equals(resultSet)) {
						lowest = Math.min(lowest, calculateSwitches(diff));
					}
				}

				out.write("Case #" + (i + 1) + ": " + (lowest == 1000 ? "NOT POSSIBLE" : lowest) + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}

	private static int calculateSwitches(long diff) {
		if (diff < 0) {
			throw new IllegalStateException();
		} 
		int result = 0;
		while (diff > 0) {
			if (diff % 2 == 1) {
				result++;
			}
			diff = diff/2;
		}
		return result;
	}
}