import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt(),b=scan.nextInt(),c=scan.nextInt();
		System.out.println(a*b*2+b*c*2+c*a*2);
	}
}