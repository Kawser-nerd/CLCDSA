import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int k = scanner.nextInt();
				int l = scanner.nextInt();
				int s = scanner.nextInt();
				scanner.nextLine();
				String letters = scanner.nextLine();
				String word = scanner.nextLine();
				Map<Character, Integer> lettersCount = new HashMap<Character, Integer>();
				for (int j = 0; j < letters.length(); j++) {
					Character ch = letters.charAt(j);
					if (lettersCount.containsKey(ch)) {
						lettersCount.put(ch, lettersCount.get(ch) + 1);
					}
					else {
						lettersCount.put(ch, 1);
					}
				}
				int wordMaxOffset = l;
				for (int j = 1; j < word.length(); j++) {
					boolean match = true;
					for (int j2 = 0; j2 < word.length() - j; j2++) {
						if (word.charAt(j2) != word.charAt(j + j2)) {
							match = false;
							break;
						}
					}
					if (match) {
						wordMaxOffset = j;
						break;
					}
				}
				int maxPossible = 1 + (s - l) / wordMaxOffset;
				double expected = s + 1 - l;
				for (int j = 0; j < word.length(); j++) {
					char ch = word.charAt(j);
					if (!lettersCount.containsKey(ch)) {
						expected = 0;
						maxPossible = 0;
						break;
					}
					expected *= lettersCount.get(ch)*1.0/k;
				}
				double result = maxPossible - expected;
				out.write("Case #" + (i + 1) + ": " + String.format("%.7f", result).replace(",", ".") + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}