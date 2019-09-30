import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	PrintWriter out;
	
	static final String problem = "C-small";
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	
	void solveOne() {
		int nPlayers = in.nextInt();
		int low = in.nextInt();
		int high = in.nextInt();
		
		int freq[] = new int[nPlayers];
		for (int i = 0; i < freq.length; i++) {
			freq[i] = in.nextInt();
		}
		
		for (int f = low; f <= high; f++) {
			// divides
			boolean fail = false;
			for (int other : freq) {
				if (other % f != 0 && f % other != 0) {
					fail = true;
					break;
				}
			}
			if (!fail) {
				out.println(f);
				return;
			}
		}
		out.println("NO");
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 0; i < nTests; i++) {
			out.print("Case #"+(i+1)+": ");
			solveOne();
		}
	}
	
	void run() {
		try {
			in = new Scanner(new FileReader("C:\\roundC\\" + problem + ".in"));
			out = new PrintWriter(new FileWriter("C:\\roundC\\" + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}