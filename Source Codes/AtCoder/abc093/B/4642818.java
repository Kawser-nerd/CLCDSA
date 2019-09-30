import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		sc.close();
		for(int i = A;i < A + K;i++) {
			if(i <= B) System.out.println(i);
		}
		for(int i = B - K + 1;i <= B;i++) {
			if(i >= A + K) System.out.println(i);
		}	
	}

}