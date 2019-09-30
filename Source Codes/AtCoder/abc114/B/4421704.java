import java.util.Scanner;
public class Main {
	//static int N;
	static String s;
	static int min=1000;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		s=sc.next();
		for(int i=0;i<s.length()-2;i++) {
			min=Math.min(min,Math.abs(753-Integer.parseInt(s.substring(i, i+3))));
		}
		System.out.println(min);
	}
}