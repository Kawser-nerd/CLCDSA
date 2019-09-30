import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
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
			inputStream = new FileInputStream("C-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("gcj3.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GCJ3 solver = new GCJ3();
		solver.solve(1, in, out);
		out.close();
	}
}

class GCJ3 {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int cases = in.nextInt();
        for(int caseNum =0;caseNum<cases;caseNum++) {
            int res = 0;
            long A = in.nextInt();
            long B = in.nextInt();
            int N = IntLib.numDigits(A,10);
            long[] pow = new long[N+1];
            pow[0]=1;
            for(int i=1;i<=N;i++)pow[i]=10*pow[i-1];
            long[] done = new long[N];
            for(long i=A;i<=B;i++) {
                inner: for(int j=1;j<=N-1;j++) {
                    long left = i;
                    long right = i;
                    left/=pow[N-j];
                    right%=pow[N-j];
                    right*=pow[j];
                    long nw = left+right;
                    done[j-1]=nw;
                    if(nw>i && nw>=A && nw<=B) {
                        for(int k=0;k<j-1;k++) {
                            if(done[k]==nw)continue inner;
                        }
                        res++;
                    }
                }
            }
            out.println("Case #"+(caseNum+1)+": "+res);
        }
	}
    }

class IntLib {
    public static int numDigits(long a, long base) {
        int res = 0;
        while(a>0) {
            a/=base;
            res++;
        }
        return res;
    }
}

