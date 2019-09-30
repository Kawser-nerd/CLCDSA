import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class B {

	public static final String FILE_NAME = "B-large";

	// public static final String FILE_NAME = "B-small-attempt1";
	// public static final String FILE_NAME = "test";

	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(FILE_NAME
				+ ".in"));
		BufferedWriter output = new BufferedWriter(new FileWriter(FILE_NAME
				+ ".out"));
		final int T = Integer.parseInt(input.readLine());
		for (int t = 0; t < T; t++) {
			output.append("Case #" + (t + 1) + ": ");
			char[] chars = input.readLine().trim().toCharArray();
			int k = chars.length - 1;
			while (k > 0 && chars[k] <= chars[k - 1])
				k--;
			if (k > 0) {
				int p = k;
				char min = '9' + 1;
				for (int q = k; q < chars.length; q++) {
					if (chars[q] > chars[k - 1] && chars[q] < min) {
						min = chars[q];
						p = q;
					}
				}
				char c = chars[p];
				chars[p] = chars[k - 1];
				chars[k - 1] = c;
				Arrays.sort(chars, k, chars.length);
				for (int x = 0; x < chars.length; x++)
					output.append(chars[x]);
			} else {
				Arrays.sort(chars);
				int j = 0;
				while (chars[j] == '0')
					j++;
				output.append(chars[j]);
				for (int x = 0; x < j + 1; x++)
					output.append('0');
				for (int x = j + 1; x < chars.length; x++)
					output.append(chars[x]);
			}
			output.append('\n');
		}
		output.close();
	}
}
