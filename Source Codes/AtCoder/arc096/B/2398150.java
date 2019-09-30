import java.util.*;

// ARC 96-D
// https://beta.atcoder.jp/contests/arc096/tasks/arc096_b

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		long N = in.nextLong();
		long C = in.nextLong();
		
		long[] positions = new long[(int) N + 1];
		long[] values = new long[(int) N + 1];
		
		for (int i = 1; i<= N; i++) {
			positions[i] = in.nextLong();
			values[i] = in.nextLong();
		}
		
		long[] hidari = new long[(int) N + 1];
		long[] migi = new long[(int) N + 1];
		long[] hidariMax = new long[(int) N + 1];
		long[] migiMax = new long[(int) N + 1];
		
		for (int i = 1; i < N + 1; i++) {
			hidari[i] = hidari[i - 1] - (positions[i] - positions[i - 1]) + values[i];
			hidariMax[i] = Math.max(hidariMax[i - 1], hidari[i]);
		}
		for (int i = (int) N ; i > 0; i--) {
			int index = i == N ? 0 : i + 1;
			long pre = i == N ? C : positions[i + 1];
			migi[i] = migi[index] - (pre - positions[i]) + values[i];
			migiMax[i] = Math.max(migiMax[index], migi[i]);
		}
		
//		print("hidari", hidari);
//		print("hidariMax", hidariMax);
//		print("migi", migi);
//		print("migiMax", migiMax);
		
		long answer = 0;
		
		// i?????????i + 1????????
		for (int i = 1; i < N + 1; i++) {
			long newAnswer = hidariMax[i];
//			System.out.printf("%d?????: %d\n", i, newAnswer);
			answer = Math.max(answer, newAnswer);
			
			// ???????
			newAnswer -= positions[i];
			
			int index = i == N ? 0 : i + 1;
			newAnswer += migiMax[index];
//			System.out.printf("%d?????: %d\n\n", i + 1, newAnswer);
			answer = Math.max(answer, newAnswer);
		}
		
		// i?????????i - 1????????
		for (int i = (int) N; i > 0; i--) {
			long newAnswer = migiMax[i];
//			System.out.printf("%d?????: %d\n", i, newAnswer);
			answer = Math.max(answer, newAnswer);
			
			// ???????
			newAnswer -= C - positions[i];
			
			newAnswer += hidariMax[i - 1];
//			System.out.printf("%d?????: %d\n\n", i - 1, newAnswer);
			answer = Math.max(answer, newAnswer);
		}
		System.out.println(answer);
	}
	
	public static void print(String s, long[] arr) {
		System.out.println(s);
		for (int i = 0; i < arr.length; i++) {
			System.out.printf("%d ", arr[i]);
		}
		System.out.println();
	}
}