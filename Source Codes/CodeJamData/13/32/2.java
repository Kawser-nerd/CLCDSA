import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;


public class B {
	static String result(int x, int y) {
		StringBuilder sb = new StringBuilder();
		
		while (x < 0) {
			x++;
			sb.append("EW");
		}
		while (x > 0) {
			x--;
			sb.append("WE");
		}
		while (y < 0) {
			y++;
			sb.append("NS");
		}
		while (y > 0) {
			y--;
			sb.append("SN");
		}
		return sb.toString();
	}
	
	static void go(String inputFile) throws Exception {
		LineNumberReader in = new LineNumberReader(new FileReader(inputFile));
		FileWriter out = new FileWriter(inputFile + ".out");
		
		int nCases = Integer.parseInt(in.readLine());
		for (int c = 1; c <= nCases; c++) {
			int[] dims = toInts(in.readLine());
			
			String res = result(dims[0], dims[1]);
			String line = "Case #" + c + ": " + res;
			System.out.println(line);
			out.write(line + "\n");
		}
		out.close();
	}
	
	static int[] toInts(String s) {
		String[] tmp = s.trim().split(" ");
		int n = tmp.length;
		int[] res = new int[n];
		for (int a = 0; a < n; a++)
			res[a] = Integer.parseInt(tmp[a]);
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		LineNumberReader sysIn = new LineNumberReader(new InputStreamReader(System.in));
		String line;
		while ((line = sysIn.readLine()) != null) {
			go(line.trim());
		}
	}
}
