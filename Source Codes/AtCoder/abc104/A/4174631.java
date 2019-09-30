import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int rate = sc.nextInt();
		System.out.println(rate < 1200 ? "ABC" : rate < 2800 ? "ARC" : "AGC");
	}
}