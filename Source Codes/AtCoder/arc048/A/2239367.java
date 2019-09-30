import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		long a=sc.nextLong(),b=sc.nextLong();
		a=a<0?a+1:a;b=b<0?b+1:b;
		System.out.println(b-a);
	}
}