import java.io.*;
import java.util.*;

public class B implements Runnable {
	private static String fileName = "b";
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";

    private Scanner in;
	private PrintWriter out;

    private B() throws FileNotFoundException {
        in = new Scanner(new File(inputFileName));
        out = new PrintWriter(outputFileName);
    }

    private void nextPermutation(int[] permutation) {
        List<Integer> free = new ArrayList<Integer>();
        for (int i = permutation.length - 1; i >= 0; i--) {
            int current = permutation[i];
            for (int j = 0; j < free.size(); j++) {
                if (free.get(j) > current) {
                    permutation[i] = free.get(j);
                    free.set(j, current);
                    Collections.sort(free);

                    for (int k = i + 1; k < permutation.length; k++) {
                        permutation[k] = free.get(k - i - 1);
                    }
                    return;
                }
            }
            free.add(current);
            Collections.sort(free);
        }
    }



    private void solve() {
        String t = in.next();
        int[] perm = new int[t.length() + 1];
        for (int i = 0; i < t.length(); i++) {
            perm[i + 1] = t.charAt(i) - '0';
        }
        nextPermutation(perm);
        StringBuilder buf = new StringBuilder();
        for (int i : perm) {
            buf.append(i);
        }
        String res = buf.toString();
        if (res.startsWith("0")) {
            res = res.substring(1);
        }
        out.println(res);
    }

	public void run() {
		try {
            int tests = in.nextInt();
            in.nextLine();
            for (int t = 1; t <= tests; t++) {
                out.print("Case #" + t + ": ");
                solve();
            }
        } finally {
            in.close();
            out.close();
        }
    }

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.US);
		new Thread(new B()).start();
	}
}