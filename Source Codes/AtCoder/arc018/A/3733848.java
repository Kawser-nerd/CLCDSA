import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
	    double n=sc.nextDouble();
	    double m=sc.nextDouble();
	    n/=100;
	    System.out.println(n*n*m);
	}
}