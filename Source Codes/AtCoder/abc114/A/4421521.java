import java.util.Scanner;
public class Main {
	static int N;
	static String ans="NO";
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		if(N==7||N==5||N==3)ans="YES";
		System.out.println(ans);
	}
}