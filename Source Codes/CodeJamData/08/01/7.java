import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Universe {
	
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		FileWriter w = new FileWriter("output.txt");
		int tests = Integer.parseInt(r.readLine());
		for (int i = 0; i < tests; i++) {
			int engines = Integer.parseInt(r.readLine());
			String[] se = new String[engines];
			for (int j = 0; j < engines; j++) {
				se[j] = r.readLine();
			}
			int queries = Integer.parseInt(r.readLine());
			String[] q = new String[queries];
			for (int j = 0; j < queries; j++) {
				q[j] = r.readLine();
			}
			
			int min = 0;
			int pos = 0;
			while (pos < queries) {
				System.out.println("pos=" + pos);
				int best = 0;
				for (int j = 0; j < engines; j++) {
					String s = se[j];
					int cnt = 0;
					for (int k = pos; k < queries; k++) {
						if (s.equals(q[k])) break;
						cnt++;
					}
					
					System.out.println(s +"|" + cnt);
					best = Math.max(best, cnt);
				}
				
				System.out.println("best=" + best);
				pos += best;
				min++;
			}
			
			if (min > 0) min--;

			w.write("Case #" + (i + 1) + ": " + min + "\n");
		}
		r.close();
		w.close();
	}

}
