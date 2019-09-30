import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);

			int a = sc.nextInt();

			int b = sc.nextInt();

			int d = a%b;
			
			if(d>0) {
				System.out.println(b-d);
			}else {
				System.out.println("0");
			}
			
			
		}
}