import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// ???
		Scanner sc = new Scanner(System.in);
		String[] data = sc.nextLine().split(" ");
		int N = Integer.parseInt(data[0]);
		int M = Integer.parseInt(data[1]);
		int C = Integer.parseInt(data[2]);
		String[] B = sc.nextLine().split(" ");
		int value=0;
		int result=0;
		String line = "";
		
		for(int i=0;i<N;i++) {
			value=0;
			String[] A = sc.nextLine().split(" ");
			for(int j=0;j<M;j++) {
				value += Integer.parseInt(A[j]) * Integer.parseInt(B[j]);
			}
			if(value + C > 0) result++;
		}
		System.out.println(result);
	}
}