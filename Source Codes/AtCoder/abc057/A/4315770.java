import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		if(a+b<24) {
			System.out.println(a+b);
		}else if(a + b > 24){
			System.out.println(a+b-24);
		}else {
			System.out.println(0);
		}
	}

}