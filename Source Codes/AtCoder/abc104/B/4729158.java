import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		String s = (new Scanner(System.in)).next();
		String ans = s.matches("^A[a-z]+C[a-z]+$") ? "AC" : "WA";
		System.out.println(ans);
	}
}