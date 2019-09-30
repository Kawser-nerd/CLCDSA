import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class CodeJamC {

	public static void main(String[] args) {
	
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String line = in.readLine();
			int total = Integer.valueOf(line);
			for (int n=1; n <= total; n++) {
				line = in.readLine();
				StringTokenizer st = new StringTokenizer(line);
				int p = Integer.valueOf(st.nextToken());
				int q = Integer.valueOf(st.nextToken());
				List<Integer> a = new ArrayList<Integer>(q);
				line = in.readLine();
				st = new StringTokenizer(line);
				for (int i=0; i<q; i++) {
					a.add(Integer.valueOf(st.nextToken()));
				}
				a.add(0);
				a.add(p+1);
				Collections.sort(a);
				
				int[][] b = new int[a.size()][];
				for (int i=0; i<a.size(); i++) {
					b[i] = new int[a.size()];
				}
				
				for (int len=1; len <= a.size() -2; len++) {
					for (int start=1; start + len < a.size(); start++) {
						if (len == 1) {
							b[len][start] = a.get(start+1) - a.get(start-1) - 2;  
						} else {
							int min = Integer.MAX_VALUE;
							for (int left=0; left<=len-1; left++) {
								min = Math.min(min, b[left][start] + b[len-left-1][start+left+1]);
							}
							b[len][start] = min + (a.get(start+len) - a.get(start-1) - 2);
						}
					}
				}
				
				System.out.println("Case #" + n + ": " + b[a.size()-2][1]);
			}
		} catch (Throwable e) {
			e.printStackTrace();
		}
		
	}
	
}
