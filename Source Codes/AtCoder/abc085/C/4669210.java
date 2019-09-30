import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {

		// --- input ---
		String[] vals = in.readLine().split(" ");
		int num = Integer.parseInt(vals[0]);
		int price = Integer.parseInt(vals[1]);
		in.close();

		// --- resolv ---
		for(int sen=0; sen <= num; sen++) {
			for(int gosen=0; gosen <= num - sen; gosen++) {
				int man = num - sen - gosen;
				if(price == 10000 * man + 5000 * gosen + 1000 * sen) {
					System.out.println(man + " " + gosen + " " + sen);
					return;
				}
			}
		}
		System.out.println("-1 -1 -1");
	}
}