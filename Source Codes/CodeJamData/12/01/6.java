import java.util.Scanner;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Arrays;
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
			inputStream = new FileInputStream("gcj1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("gcj1.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GCJ1 solver = new GCJ1();
		solver.solve(1, in, out);
		out.close();
	}
}

class GCJ1 {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        char[] map = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
        int cases = in.nextInt();
        in.nextLine();
        for(int i=0;i<cases;i++) {
            String input = in.nextLine();
            char[] output = new char[input.length()];
            for(int j=0;j<output.length;j++) {
                if(input.charAt(j)==' ')output[j]=' ';
                else output[j] = map[input.charAt(j)-'a'];
            }
            //debug(output);
           out.println("Case #"+(i+1)+": "+new String(output));
        }
	}
    }

