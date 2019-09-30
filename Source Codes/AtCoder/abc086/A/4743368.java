import java.util.Scanner;

public class Main {

		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int a = sc.nextInt();
			int b = sc.nextInt();
			if((1 <= a && b <= 10000) && (a * b % 2 == 1)) {
				System.out.println("Odd");}
			else if((1 <= a && b <= 10000) && (a * b % 2 == 0)) {
				System.out.println("Even");
			}}}