import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static final int MAX_TYPE = 100000;
	public void solve() {
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		int count = 0;
		
		// ???????????
		boolean types[] = new boolean[MAX_TYPE+1];
		Arrays.fill(types, false);
		for (int i=0; i<n; i++) {
			int t = in.nextInt();
			if (types[t]) {
				// ?????????????
				count++;
			} else {
				// ????????????
				types[t] = true;
			}
		}
		
		in.close();
		
		System.out.println(count);
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}
}