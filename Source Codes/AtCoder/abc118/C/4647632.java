import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int currentGCF = 0;
		for (int i = 0; i < N; i++) {
			if (currentGCF == 0) {
				currentGCF = sc.nextInt();
			} else {
				currentGCF = GCF(currentGCF, sc.nextInt());
			}
			if (currentGCF == 1) {
				break;
			}
		}
		System.out.println(currentGCF);
	}
	
	public static int GCF(int a, int b) {
		if (a > b) {
			return GCF(b, a);
		}
		if (b%a == 0) {
			return a;
		}
		return GCF(b%a, a);
	}  
}