import java.util.Scanner;


public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int d = sc.nextInt();
			
			int a = d%2;
			int b = d/2;
			if(a==0) {
				System.out.println(b);
			}else {
				int c = b+1;
				System.out.println(c);
			}
		}
}