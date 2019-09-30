import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Number {

	private Scanner fin;
	private PrintStream fout;

	public Number(String in, String out) {
		try {
			fin = new Scanner(new FileInputStream(in));
			fout = new PrintStream(out);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void run() {
		int cas = fin.nextInt();
		for (int t = 1; t <= cas; ++t) {
			fout.println("Case #" + t + ": " + process());
		}
	}
	
	private int startpos[];

	private long process() {
		int a1, a2, b1, b2;
		a1 = fin.nextInt();
		a2 = fin.nextInt();
		b1 = fin.nextInt();
		b2 = fin.nextInt();
		startpos = new int[a2+1];
		if (a2 >= 1) startpos[1] = 1;
		if (a2 >= 2) startpos[2] = 2;
		int k = 1;
		for (int i = 3; i <= a2; ++i) {
			while (i >= startpos[k] + k) k++;
			startpos[i] = k;
		}
		long res = 0;
		for (int i = a1; i <= a2; ++i) {
			res += count(i, b1, b2);
		}
		return res;
	}

	private long count(int id, int b1, int b2) {
		long res = b2 - b1 + 1;
		if (b1 < startpos[id]) {
			if (b2 < startpos[id]) return res;
			else if (b2 < startpos[id] + id) {
				return res - (b2 - startpos[id] + 1);
			} else {
				return res - id;
			}
		} else if (b1 < startpos[id] + id) {
			if (b2 < startpos[id] + id) {
				return 0;
			} else {
				return b2 - (startpos[id] + id) + 1;
			}
		} else {
			return res;
		}
	}

	public static void main(String[] args) {
		new Number("c.in", "c.out").run();
	}

}
