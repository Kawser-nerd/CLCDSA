import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		long A = sc.nextInt();
		long B = sc.nextInt();
		long C = sc.nextInt();
		long time = 0;
		if(A == B&& B == C) {
			time = A%2-1;
		}else {
			while(A%2 == 0 && B%2 == 0 && C%2 == 0) {
				time++;
				long newA = (B+C)/2;
				long newB = (A+C)/2;
				long newC = (B+A)/2;
				A = newA;
				B = newB;
				C = newC;
			}
		}
		System.out.println(time);
	}
}