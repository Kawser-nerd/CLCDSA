import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		
		int[] abc = {111,222,333,444,555,666,777,888,999};
		
		for(int i : abc) {
			if(n <= i) {
				System.out.println(i);
				return;
			}
		}
		
	}
}