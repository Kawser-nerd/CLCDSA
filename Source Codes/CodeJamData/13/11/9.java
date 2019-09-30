import java.util.*;
import java.io.*;
import java.math.*;

public class a{
	static InputReader in;
	static PrintWriter out;
	
	public static void main(String args[]){
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
		int n = Integer.valueOf(in.next());
		for (int i = 1; i <= n; i++){
			out.printf("Case #%d: %s\n", i, solve());
		}
		out.close();
	}
	static BigInteger solve(){
		BigInteger r = new BigInteger(in.next());
		BigInteger t = new BigInteger(in.next());
		BigInteger x = new BigInteger("0");
		BigInteger y = new BigInteger("2000000000000000000");
		BigInteger ans = new BigInteger("0");
		while (x.compareTo(y) != 1){
			BigInteger m = x.add(y).shiftRight(1);
			BigInteger tmp = m.multiply(r).shiftLeft(1).add( m.multiply(m.multiply(m).shiftLeft(2).subtract(BigInteger.ONE)).divide(new BigInteger("3")) ).
					subtract( m.subtract(BigInteger.ONE).shiftLeft(1).multiply(m).multiply(m.shiftLeft(1).subtract(BigInteger.ONE)).divide(new BigInteger("3")) );
			if (tmp.compareTo(t) != 1){
				ans = m;
				x = m.add(BigInteger.ONE);
			}
			else
				y = m.subtract(BigInteger.ONE);
		}
		return ans;
	}
}

class InputReader{
	StringTokenizer tokenizer;
	BufferedReader reader;
	public InputReader(InputStream stream){
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(stream));
	}
	public String next(){
		while (tokenizer == null || !tokenizer.hasMoreTokens()){
			try{
				tokenizer = new StringTokenizer(reader.readLine());
			} catch(IOException E){
				throw new RuntimeException(E);
			}
		}
		return tokenizer.nextToken();
	}
}
