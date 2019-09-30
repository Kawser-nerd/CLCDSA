import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("B-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("gcj2.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GCJ2 solver = new GCJ2();
		solver.solve(1, in, out);
		out.close();
	}
}

class GCJ2 {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int cases = in.nextInt();
        for(int caseNum =0;caseNum<cases;caseNum++) {
            int res = 0;
            int N = in.nextInt();
            int S = in.nextInt();
            int p = in.nextInt();
            int normal = Math.max(p,p*3-2);
            int surprise = Math.max(p,p*3-4);
            for(int i=0;i<N;i++) {
                int score = in.nextInt();
                if(score>=normal)res++;
                else if(score>=surprise && S>0) {
                    res++;
                    S--;
                }
            }

            out.println("Case #"+(caseNum+1)+": "+res);
        }
	}
}

