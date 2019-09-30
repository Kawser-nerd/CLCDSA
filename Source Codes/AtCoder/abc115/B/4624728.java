import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int p[] = new int[N];
		int val = 0;
		for(int i = 0;i < N;i++) {
			p[i]  = sc.nextInt();
			
		}
		Arrays.sort(p);	
		p[N-1] = p[N-1] / 2;
		for(int i = 0;i < N;i++) {
			val = val + p[i];
		}
		System.out.println(val);
		sc.close();
	}
}