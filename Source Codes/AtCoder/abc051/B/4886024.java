import java.util.Scanner;


public class Main {
	static int A,B;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 A = sc.nextInt();
		 B = sc.nextInt();
		 sc.close();


		 int ans = 0 ;

		 for(int i = 0 ; i < A+1 ; i++){
			 for(int j = 0 ; j < A+1 ; j++){
					 if(B-i-j<=A && B-i-j>=0){
						 ans+=1;
				 }
			 }
		 }

		 System.out.println(ans);
	}
}