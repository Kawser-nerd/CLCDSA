import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
 
 
public class Main {
	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		List<String> inputs = new ArrayList<String>();
		for(int i = 0; i < N; i++) {
			inputs.add(sc.next());
		}
		Collections.sort(inputs);
		String output = String.join("", inputs);
		System.out.println(output);
	}
}