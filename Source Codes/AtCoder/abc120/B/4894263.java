import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		int max= Math.max(a, b);
		List<Integer> result = new ArrayList<Integer>();
		for(int i =1 ; i <=max; i++) {
			if(a%i ==0 && b%i ==0) {
				result.add(i);
			}
		}
		System.out.println(result.get(result.size()-c));
		sc.close();
	}
}