import java.util.Scanner;
import java.util.HashSet;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		HashSet<Integer> d = new HashSet<Integer>();
		
		for(int i = 0; i < N; i++) {
			d.add(sc.nextInt());
		}
		sc.close();
		
		System.out.println(d.size());
	}
}