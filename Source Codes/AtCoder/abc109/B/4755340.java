import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] w = new String[N];
		
		String W = sc.next();
		w[0] = W;
		char next = W.charAt(W.length()-1);
		
		for(int i = 1 ; i < N ; i++) {
			W = sc.next();
			if(W.charAt(0) != next) {
				System.out.println("No");
				return;
			}
			
			for(int j = 0 ; j < i ; j++) {
				if(W.equals(w[j])) {
					System.out.println("No");
					return;
				}
			}
			
			w[i] = W;
			next = W.charAt(W.length() - 1);
		}
		
		System.out.println("Yes");

	}

}