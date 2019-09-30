import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		long A=scan.nextLong();
		long B=scan.nextLong();
		long C=scan.nextLong();
		long ans=B/C-A/C;
		System.out.println(A%C==0?ans+1:ans);
	}
}