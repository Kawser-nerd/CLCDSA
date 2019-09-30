import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/D-large.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();
			
			if (s*c<k) {
				output += "Case #" + i + ": IMPOSSIBLE\n";
				continue;
			}
			
			ArrayList<Long> nums = new ArrayList<Long>();
			
			for (int j = 0; j < s; j++) {
				if (j*c >= k)
					break;
				long next = 0;
				long mult = 1;
				for (int m = 0; m < c; m++) {
					if (j*c+m >= k)
						break;
					next += (j*c+m)*mult;
					mult *= k;
				}
				next++;
				
				nums.add(next);
			}
			
			String toAdd = "";
			for (int j = 0; j < nums.size(); j++) {
				toAdd += " "+nums.get(j);
			}
			
			output += "Case #" + i + ":" + toAdd + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/D-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}