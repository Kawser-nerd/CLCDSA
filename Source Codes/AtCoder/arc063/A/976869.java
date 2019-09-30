import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int total = 0;
		char c = line.charAt(0);
		for (int i = 1; i < line.length(); i++) {
			if (c != line.charAt(i)) {
				c = line.charAt(i);
				total++;
			}
		}
		System.out.println(total);
	}
}