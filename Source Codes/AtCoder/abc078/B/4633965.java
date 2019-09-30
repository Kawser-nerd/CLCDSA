import java.util.Scanner;

public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x=sc.nextInt();
		int y=sc.nextInt();
		int z=sc.nextInt();
		int semians=x/(y+z);
		if(x%(y+z)<z)semians-=1;
		System.out.println(semians);
	}
}