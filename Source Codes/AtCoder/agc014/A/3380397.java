import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader ( new InputStreamReader(System.in));
		String [] input = br.readLine().split(" ");
		long a = Long.parseLong(input[0]);
		long b = Long.parseLong(input[1]);
		long c = Long.parseLong(input[2]);
		long formerA = a;
		long formerB = b;
		long formerC = c;
		long result = 0;
		while(true) {
			if(unEven(a) || unEven(b) || unEven(c)) {
				break;
			}
			long a2 = a/2;
			long b2 = b/2;
			long c2 = c/2;
			a = b2 + c2;
			b = a2 + c2;
			c = a2 + b2;
			result++;
			if(formerA == a && formerB == b && formerC == c) {
				result = -1;
				break;
			}
		}
		System.out.println(result);
	}
	private static boolean unEven(long var) {
		return (var % 2!=0);
	}
}