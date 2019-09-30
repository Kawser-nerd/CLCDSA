import java.util.Scanner;


public class Main {
	static int N;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 N = sc.nextInt();
		 sc.close();

		 int p = (int)(Math.pow(10,9)+7);


		 long ans = 1 ;
		 for(int i = 1 ; i < N+1 ; i++){
			 ans = (ans*i)%p;
		 }

		 System.out.println(ans);

	}
}