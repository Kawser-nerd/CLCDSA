import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		for(int i=0; i<N; i++)
			a[i] = sc.nextInt();
		
		if(firstWin(N, a))
			System.out.println("First");
		else
			System.out.println("Second");
		sc.close();
	}
	
	static boolean firstWin(int N, int[] a) {
		Arrays.sort(a);
		for(int i=0; i<N; i++) {
			if(N-i<=a[i]) {
				boolean win = (a[i]-(N-i))%2==1;
				int sameSize=0;
				for(int j=i-1; j>=0 && a[j]==N-i; j--)
					sameSize++;
				win |= sameSize%2==1;
				return win;
			}
		}
		//never reach
		return false;
	}
	
}