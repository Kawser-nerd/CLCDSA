import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> S = new ArrayList<>();
		if(n == 0)
			S.add(0);
		while(n != 0) {
			int a = Math.abs(n % 2);
			S.add(a);
			n = (n - a) / -2;
		}
		Collections.reverse(S);
		for(int i = 0; i < S.size(); i++) {
			System.out.print(S.get(i));
		}
		System.out.println();
	}

}