import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);

			int a = sc.nextInt();

			int b = 0;

			for(int i = 1; i<=a; i ++) {
				b += (i*10000);
			}

			System.out.println(b/a);
		}
}