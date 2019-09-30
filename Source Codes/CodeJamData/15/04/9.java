import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Nipuna Samarasekara
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "D-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    // 689^*(
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
      int x=in.nextInt(),r=in.nextInt(),c=in.nextInt();
        if (c>r){
            int t=r;
            r=c;
            c=t;
        }
        int sqrt=  (x+1)/2;
        int rem=r*c  ;
        rem%=x;
        if (r<x||c<sqrt||x>=7||rem!=0){
            out.println("Case #" + testNumber + ": RICHARD");
            System.out.println("Case #" + testNumber + ": RICHARD");
            return;
        }
        if (x<4){
        out.println("Case #" + testNumber + ": GABRIEL");
        System.out.println("Case #" + testNumber + ": GABRIEL");
        return;
        }
        if (x==4){
            if (c>2){
                out.println("Case #" + testNumber + ": GABRIEL");
                System.out.println("Case #" + testNumber + ": GABRIEL");
                return;
            }
            else {
                out.println("Case #" + testNumber + ": RICHARD");
                System.out.println("Case #" + testNumber + ": RICHARD");
                return;
            }



        }
        if (x==5){
            if (c>3){
                out.println("Case #" + testNumber + ": GABRIEL");
                System.out.println("Case #" + testNumber + ": GABRIEL");
                return;
            }
            else if(c==3&&r>=10){
                out.println("Case #" + testNumber + ": GABRIEL");
                System.out.println("Case #" + testNumber + ": GABRIEL");
                return;
            }
            else {
                out.println("Case #" + testNumber + ": RICHARD");
                System.out.println("Case #" + testNumber + ": RICHARD");
                return;
            }



        }

        if (x==6){
            if (c>3){
                out.println("Case #" + testNumber + ": GABRIEL");
                System.out.println("Case #" + testNumber + ": GABRIEL");
                return;
            }
            else {
                out.println("Case #" + testNumber + ": RICHARD");
                System.out.println("Case #" + testNumber + ": RICHARD");
                return;
            }



        }

    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

