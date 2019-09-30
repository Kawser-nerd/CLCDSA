import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/A-large.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			if (n==0) {
				output += "Case #" + i + ": INSOMNIA\n";
				continue;
			}
			boolean[] seen = new boolean[10];
			int num = 0;
			int count = 0;
			while (count < 10) {
				num += n;
				for (char c : (""+num).toCharArray()) {
					int d = c-'0';
					if (!seen[d]) {
						seen[d] = true;
						count++;
					}
				}
			}
			
			output += "Case #" + i + ": " + num + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/A-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}