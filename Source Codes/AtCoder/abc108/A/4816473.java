import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		if(n%2==0){
			System.out.println(n*n/4);
		}else{
			n=n+1;
			System.out.println(n*(n-2)/4);

		}

	}}