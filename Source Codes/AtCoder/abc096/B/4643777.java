import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();
		sc.close();
		int[] Array = {A,B,C};
		Arrays.sort(Array);
		for(int i = 0;i < K;i++) {
			Array[2] *= 2;
		}
		System.out.println(Array[0] + Array[1] + Array[2]);	
	}

}