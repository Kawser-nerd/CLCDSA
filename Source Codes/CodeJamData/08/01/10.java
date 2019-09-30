package emm.cj08;

import java.io.*;
import java.util.*;

public class Search {
	private static final File IN = new File("/home/eric/cj/search-in.txt"), OUT = new File("/home/eric/cj/search-out.txt");
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(IN));
		PrintStream ps = new PrintStream(OUT);
		
		int trials = Integer.parseInt(br.readLine());
		for(int trial = 0; trial < trials; trial++) {
			HashMap<String,Integer> map = new HashMap<String,Integer>();
			
			int engines = Integer.parseInt(br.readLine());
			for(int engine = 0; engine < engines; engine++)
				map.put(br.readLine(), engine);
			
			int availCnt = engines;
			boolean[] avail = getAvail(engines, -1);
			int changes = 0;
			
			int queries = Integer.parseInt(br.readLine());
			for(int query = 0; query < queries; query++) {
				int pos = map.get(br.readLine());
				
				if(avail[pos]) {
					avail[pos] = false;
					availCnt--;
					
					if(availCnt <= 0) {
						availCnt = engines - 1;
						avail = getAvail(engines, pos);
						changes++;
					}
				}
			}
			
			ps.println("Case #" + (trial + 1) + ": " + changes);
		}
		
		br.close();
		ps.close();
	}
	
	private static boolean[] getAvail(int engines, int cur) {
		boolean[] result = new boolean[engines];
		
		for(int i = 0; i < engines; i++)
			result[i] = i != cur;
		
		return result;
	}
}
