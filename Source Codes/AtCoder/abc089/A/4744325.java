import java.util.Scanner;

public class Main {

		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int N = sc.nextInt();
			int sum = 0; 		
			if(1 <= N && N <= 1000)
			sum = N / 3;
			System.out.println(sum);}}