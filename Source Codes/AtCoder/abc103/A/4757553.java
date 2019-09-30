import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int A1 = sc.nextInt();
        int A2 = sc.nextInt();
        int A3 = sc.nextInt();
		int mic = Math.abs(Math.max(Math.max(A1, A2), A3) - Math.min(Math.min(A1,A2), A3));
		System.out.println(mic);
	}
}