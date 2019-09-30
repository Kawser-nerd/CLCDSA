import java.util.Scanner;
public class Main {
	static int N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		int a=N/3600;
		int b=N%3600/60;
		int c=N%60;
		System.out.printf("%02d:%02d:%02d",a,b,c);
		System.out.println();
	}
}