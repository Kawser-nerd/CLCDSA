import java.util.Locale;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.Reader;
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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    // 689^*(
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int len = in.nextInt();
        long x = in.nextLong();
        String s = in.next();
        Complex[] a = new Complex[len];
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == 'i') a[i] = new Complex(new int[]{1, 0, 0}, 0);
            if (s.charAt(i) == 'j') a[i] = new Complex(new int[]{0, 1, 0}, 0);
            if (s.charAt(i) == 'k') a[i] = new Complex(new int[]{0, 0, 1}, 0);

        }
        Complex fin= new Complex(new int[]{0, 0, 0}, 1);
        for (int i = 0; i < len; i++) {
            fin= fin.multiply(a[i]);
          //  System.out.println(fin.toString()+" iii "+i);
        }
        long pow=  x%4;
        //if (pow==0)pow+=4;
        Complex lp= new Complex(new int[]{0, 0, 0}, 1);

        for (int i = 0; i < pow; i++) {
            lp= lp.multiply(fin);
          //  System.out.println(fin.toString()+" pppp "+i);
        }

        if (lp.a_1!=-1){
        out.println("Case #" + testNumber + ": NO");
        System.out.println("Case #" + testNumber + ": NO");
        return;
        }
        x=Math.min(12,x);
        int size= (int) ((x)*len);
        int xx= (int) x;
        Complex[] ff= new Complex[size];
        for (int i = 0; i < xx; i++) {
            for (int j = 0; j < len; j++) {
                if (s.charAt(j) == 'i')  ff[i*len+j] = new Complex(new int[]{1, 0, 0}, 0);
                if (s.charAt(j) == 'j')  ff[i*len+j]= new Complex(new int[]{0, 1, 0}, 0);
                if (s.charAt(j) == 'k')  ff[i*len+j]= new Complex(new int[]{0, 0, 1}, 0);


            }
        }
        fin= new Complex(new int[]{0, 0, 0}, 1);
        int ipos=0;
        while (ipos<size&&fin.ijk[0]!=1){
            fin=fin.multiply(ff[ipos]);
         //   System.out.println(fin.toString()+" iniii "+ipos);
           ipos++;
        }
        fin= new Complex(new int[]{0, 0, 0}, 1);
        while (ipos<size&&fin.ijk[1]!=1){
            fin=fin.multiply(ff[ipos]);
         //   System.out.println(fin.toString()+" injjj "+ipos);
            ipos++;
        }
        if (ipos<size){
            out.println("Case #" + testNumber + ": YES");
            System.out.println("Case #" + testNumber + ": YES");
        }
        else{
            out.println("Case #" + testNumber + ": NO");
            System.out.println("Case #" + testNumber + ": NO");
        }

    }   }

class Complex {
        int[] ijk = new int[3];
        int a_1 = 0;

        Complex(int[] ijk, int a_1) {
            this.ijk = ijk;
            this.a_1 = a_1;
        }

        public String toString() {
            return "Complex{" +
                    "ijk=" + Arrays.toString(ijk) +
                    ", a_1=" + a_1 +
                    '}';
        }

        Complex multiply(Complex a1) {
            Complex ret = new Complex(new int[3], 0);
            for (int i = 0; i < 3; i++) {
                ret.a_1 -= this.ijk[i] * a1.ijk[i];
                ret.ijk[i] += this.ijk[i] * a1.a_1;
                ret.ijk[i] += a1.ijk[i] * this.a_1;
            }
            for (int i = 0; i < 3; i++) {
                ret.ijk[(i + 2) % 3] += this.ijk[i] * a1.ijk[(i + 1) % 3];
                ret.ijk[(i + 2) % 3] -= a1.ijk[i] * this.ijk[(i + 1) % 3];

            }
            ret.a_1 += this.a_1 * a1.a_1;

          return ret;
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

    public long nextLong() {
        return Long.parseLong(next());
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

