import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		String X = sc.next();
		int L = X.length();
		int S = 0;
		for(int i=0;i<L;i++) {
			if(X.charAt(i) == 'S') {
				S++;
			}else {
				if(S>=1) {
					S--;
				}
			}
		}
		System.out.println(2 * S);
	}
}