import java.util.Scanner;

public class Main {

		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int A = sc.nextInt();
			int B = sc.nextInt();
			int X = sc.nextInt();
			if(1 <= A && A <= 100 && 1 <= B && B <= 100 && 1 <= X && X <= 200)
			{if(A + B >= X && A <= X) {
				System.out.println("YES");
			}
			else System.out.println("NO");
			}
			}}