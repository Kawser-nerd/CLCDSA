import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get a integer
		int N = sc.nextInt();
		int L = sc.nextInt();
		
		List<String> inputs = new ArrayList<String>();
		
		for (int i = 0; i < N; i++) {
			//get strings
			inputs.add(sc.next());
		}
		
		Collections.sort(inputs);
		
		String output = String.join("", inputs);
		// output
		System.out.println(output);
	}
}