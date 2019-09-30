import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int f=s.nextInt(),t=s.nextInt();
		if(f<=0&&0<=t) t--;
		System.out.println(t-f);
	}
}