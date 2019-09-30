import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int sum = 0;
		int t = N;
		while(t>0) {
			sum += t%10;
			t=t/10;
		}
		if(N%sum == 0) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
		}
		sc.close();
	}
}