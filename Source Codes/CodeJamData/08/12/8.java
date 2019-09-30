import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;


public class p2big {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("p2.in"));
		int t = Integer.parseInt(br.readLine());
		FileWriter out = new FileWriter("p2.out");
		for (int i=0; i<t; i++) {
			int flav = Integer.parseInt(br.readLine());
			int cust = Integer.parseInt(br.readLine());

			Map<Integer, Integer> flavors = new HashMap<Integer, Integer>();
			Map<Integer, Map<Integer, Integer>> custFlavors = new HashMap<Integer, Map<Integer, Integer>>();
			for (int j=0; j<cust; j++) {
				String parts[] = br.readLine().split("\\s+");
				int tt = Integer.parseInt(parts[0]);
				Map<Integer, Integer> cf = new HashMap<Integer, Integer>();
				custFlavors.put(j, cf);
				for (int k=0; k<tt; k++) {
					int f = Integer.parseInt(parts[1+k*2])-1;
					int isM = Integer.parseInt(parts[2+k*2]);
					cf.put(f, isM);
				}
			}

			while (!custFlavors.isEmpty() && flavors!=null) {
				boolean modified = false;
				Iterator<Entry<Integer, Map<Integer, Integer>>> it = custFlavors.entrySet().iterator();
				while (it.hasNext()) {					
					Entry<Integer, Map<Integer, Integer>> cf = it.next();
					
					int res = solve1(flavors, cf);
					if (res == -1) {
						flavors = null;
						break;
					} else if (res == 1) {
						it.remove();
						modified = true;
					} 
				}
				if (!modified)
					break;
			}
			
			out.write("Case #" + (i+1) + ": ");
			if (flavors==null) {
				out.write("IMPOSSIBLE\n");
			} else {
				for (int c=0; c<flav; c++) 
					out.write(((flavors.containsKey(c) && flavors.get(c).equals(1))?"1":"0")+" ");
				out.write("\n");
			}
		}
		out.close();
		br.close();
	}

	private static int solve1(Map<Integer, Integer> flavors,
			Entry<Integer, Map<Integer, Integer>> cf) {
		Map<Integer, Integer> filtered = new HashMap<Integer, Integer>();
		boolean modified = false;
		
		for (Map.Entry<Integer, Integer> me : cf.getValue().entrySet()) {
			int cflav = me.getKey();
			int cmal = me.getValue();
			if (flavors.containsKey(cflav)) {
				if (flavors.get(cflav).equals(cmal)) {
					// satisfied client, eliminate
					return 1;
				} else {
					// can't fulfil this one, eliminate
					modified = true;
				}
			} else { // still undecided, keep
				filtered.put(cflav, cmal);
			}
		}
		
		if (filtered.size()==0) {
			return -1; 
		} else if (filtered.size()==1) {
			// one final wish :)
			Map.Entry<Integer, Integer> me = filtered.entrySet().iterator().next();
			flavors.put(me.getKey(), me.getValue());
			
			return 1;
		} else {
			if (modified)
				cf.setValue(filtered);
			return 0;
		}
	}
}
