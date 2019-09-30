import java.util.Scanner;


public class Main {
	static int A,B;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 A = sc.nextInt();
		 B = sc.nextInt();

		sc.close();

		if(B%A == 0){
			System.out.println(B+A);
		}else{
			System.out.println(B-A);
		}
	}
}