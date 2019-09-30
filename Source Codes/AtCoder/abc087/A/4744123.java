import java.util.Scanner;

public class Main {

		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int X = sc.nextInt();
			int A = sc.nextInt();
			int B = sc.nextInt();
			int sum = X;
			if((1 <= A && B <= 1000) && (A + B <= X && X <= 10000)){
				sum = sum - A;
				sum = sum % B;
				System.out.println(sum);
			}}}