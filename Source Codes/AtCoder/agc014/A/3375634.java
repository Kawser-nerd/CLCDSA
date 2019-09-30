import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader ( new InputStreamReader(System.in));
		String [] input = br.readLine().split(" ");
		long A = Long.parseLong(input[0]);
		long B = Long.parseLong(input[1]);
		long C = Long.parseLong(input[2]);
		long defineA= A;
		long defineB = B;
		long defineC = C;
		long result = 0;
		/*if(Even(A,B,C)){
			result = -1;
		}else if(A+B+C == 3) {
			result = 0;
		}else {*/
			while(true) {
				if(Even(A) || Even(B) || Even(C)) {
					break;
				}
				long A2 = A/2;
				long B2 = B/2;
				long C2 = C/2;
				A = B2 + C2;
				B = A2 + C2;
				C = A2 + B2;
				result++;
				if(defineA == A && defineB == B && defineC == C) {
					result = -1;
					break;
				}
			}
		//}
		System.out.println(result);
	}
	private static boolean Even(long A,long B,long C) {
		return (A % 2!=0) && (B % 2!=0) && (C % 2!=0);
	}
	private static boolean Even(long var) {
		return (var % 2!=0);
	}

}