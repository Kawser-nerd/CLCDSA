import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
      	int N = sc.nextInt();
      	String ans = "NO"; 
		if(N == 3 || N % 3 == 0) ans = "YES";
      	System.out.println(ans);
	}
}