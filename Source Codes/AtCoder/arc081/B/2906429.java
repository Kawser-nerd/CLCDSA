import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



/** Class for buffered reading int and double values */
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                     new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                   reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
	
    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}
public class Main {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Reader.init(System.in);
		int n = Reader.nextInt();
		String s1 = Reader.next();
		String s2 = Reader.next();
		
		if(n == 1) {
			System.out.println(3);
		}else {
			String d;
			int i = 1;
			long a = 1;
			if(s1.charAt(0)== s2.charAt(0)) {
				d = "single";
				a = 3;
			}else {
				d = "double";
				i = 2;
				a = 6;
			}
			while(i<n) {
				if(s1.charAt(i) != s2.charAt(i)) {
					if(d.compareTo("single") == 0) {
						a = ((a%1000000007)*2)%1000000007;
					}else {
						a = ((a%1000000007)*3)%1000000007;
					}
					i+=2;
					d = "double";
				}else {
					if(d.compareTo("single") == 0) {
						a = ((a%1000000007)*2)%1000000007;
					}
					d = "single";
					i++;
				}
			}
			System.out.println(a);
		}
		
		

	}

}