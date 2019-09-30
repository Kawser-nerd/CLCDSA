import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;


public class A {
	static long result(String name, int n) {
		int len = name.length();
		boolean hasPrev = false;
		int curr = 0;
		int prevStart = 0;
		long res = 0;
		
		int pos = 0;
		while (pos < len) {
			boolean is = "aeiou".indexOf(name.charAt(pos++)) < 0;
			if (is) {
				curr++;
				if (curr >= n) {
					hasPrev = true;
					prevStart = pos - n;
					res += 1 + pos - n;
					continue;
				}
			} else {
				curr = 0;
			}
			if (hasPrev) {
				res += 1 + prevStart;
			}
		}
		return res;
	}
	
	static void go(String inputFile) throws Exception {
		LineNumberReader in = new LineNumberReader(new FileReader(inputFile));
		FileWriter out = new FileWriter(inputFile + ".out");
		
		int nCases = Integer.parseInt(in.readLine());
		for (int c = 1; c <= nCases; c++) {
			String[] tmp = in.readLine().split(" ");
			long res = result(tmp[0], Integer.parseInt(tmp[1]));
			String line = "Case #" + c + ": " + res;
			System.out.println(line);
			out.write(line + "\n");
		}
		out.close();
	}
	
	public static void main(String[] args) throws Exception {
		LineNumberReader sysIn = new LineNumberReader(new InputStreamReader(System.in));
		String line;
		while ((line = sysIn.readLine()) != null) {
			go(line.trim());
		}
	}
}
