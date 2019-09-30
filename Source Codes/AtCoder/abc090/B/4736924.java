import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String strA = reader.next();
		int[] A = new int[5];
		String strB = reader.next();
		int[] B = new int[5];
		for (int i = 0; i < 5; i++) {
			A[i] = Character.getNumericValue(strA.charAt(i));
			B[i] = Character.getNumericValue(strB.charAt(i));
		}
		int ans = 0;
		int[] C = new int[5];
		C[0] = B[0] - A[0];
		if (C[0] == 0) {
			C[1] = B[1] - A[1]  - 1;
		} else {
			C[1] = 10;
		}
		if (C[1] == 0) {
			C[2] = B[2] - A[2]  - 1;
		} else {
			C[2] = 10;
		}
		ans = C[0] * C[1] * C[2];
		int intA = Integer.parseInt(strA);

		int below = 0;
		for (int i = A[0]*10000; i < intA; i++) {
			int n1 = i/10000;
			int n2 = i%10000/1000;
			int n4 = i%100/10;
			int n5 = i%10;
			if (n1 == n5 && n2 == n4) {
				below++;
			}
		}

		int intB = Integer.parseInt(strB);
		int above = 0;
		for (int i = B[0]*10000; i <= intB; i++) {
			int n1 = i/10000;
			int n2 = i%10000/1000;
			int n4 = i%100/10;
			int n5 = i%10;
			if (n1 == n5 && n2 == n4) {
				above++;
			}
		}

		System.out.println(ans - below + above);
		reader.close();
	}
}