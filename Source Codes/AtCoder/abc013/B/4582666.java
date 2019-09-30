import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);

			int a = sc.nextInt();

			int b = sc.nextInt();

			int answer = 0;

			int d = Math.abs(a-b);
			if(d<=5) {
				answer = d;
			}else {
				answer = 10-d;
			}

			System.out.println(answer);

		}
}