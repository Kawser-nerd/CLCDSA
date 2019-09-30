import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A implements Runnable {

	final String FILENAME = "A-large";
//	final String FILENAME = "A-small";

	
	public void solve() throws IOException {
		Scanner in = new Scanner(new File(FILENAME + ".in"));
		PrintWriter out = new PrintWriter(new File(FILENAME + ".out"));

		int testn = in.nextInt();
		for (int test = 0; test < testn; test++) {
			int R = in.nextInt();
			int C = in.nextInt();
			
			String[] arr = new String[R];
			boolean impossible = false;
			
			for (int i=0; i<arr.length; i++) {
				arr[i] = in.next();
			}
			
			for (int i=0; i<arr.length; i++) {
				if (impossible) {
					break;
				}
				for (int j=0; j<C; j++) {
					String curRow = arr[i];
					char ch = arr[i].charAt(j);
					if (ch == '#') {
						int nH = j+1;
						int nV = i+1;
						if (nH != curRow.length() && nV != arr.length) {
							String nRow = arr[nV];
							if (curRow.charAt(nH) == '#' &&
									nRow.charAt(j) == '#' && nRow.charAt(nH) == '#') {
								StringBuilder newCur = new StringBuilder(curRow);
								StringBuilder newNext = new StringBuilder(nRow);
								newCur.setCharAt(j, '/');
								newCur.setCharAt(j+1, '\\');
								newNext.setCharAt(j, '\\');
								newNext.setCharAt(j+1, '/');
								arr[i] = newCur.toString();
								arr[i+1] = newNext.toString();
							}
							else {
//								System.out.println(nH+ " : "+nV);
								impossible = true;
								break;
							}
						}
						else {
//							System.out.println(nH+ " : "+nV);
							impossible = true;
							break;
						}
					}
				}
			}
			
			out.println("Case #" + (test + 1) + ":");
			if (impossible) {
				out.println("Impossible");
			}
			else {
				for (int i=0; i<arr.length; i++) {
					out.println(arr[i]);
				}
			}
		}

		in.close();
		out.close();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			throw new AssertionError();
		}
	}

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

}