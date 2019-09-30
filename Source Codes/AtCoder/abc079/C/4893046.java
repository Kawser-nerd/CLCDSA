import java.util.*;
public class Main {

	public static void main(String[] args) {
		int ABCD = (new Scanner(System.in)).nextInt();
		int[] A = {ABCD /1000, ABCD % 1000 / 100, ABCD % 100 /10, ABCD % 10};
		boolean[] plus = new boolean[3];
		for(int i = 0; i < 1 << 3; i++) {
			int sum = A[0];
			for(int j = 0; j < 3; j++)
				plus[j] = false;
			for(int j = 0; j < 3; j++) {
				if((1 & (i >> j)) == 1) {
					sum += A[j+1];
					plus[j] = true;
				}
				else 
					sum -= A[j+1];
			}
			if(sum == 7)
				break;
		}
		System.out.print(A[0]);
		for(int i = 0; i < 3; i++) {
			System.out.print(plus[i] ? "+" : "-");
			System.out.print(A[i+1]);		
		}
		System.out.println("=" + 7);
	}

}