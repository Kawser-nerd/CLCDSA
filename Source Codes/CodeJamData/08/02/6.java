import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Timetable {
	
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		FileWriter w = new FileWriter("output.txt");
		int tests = Integer.parseInt(r.readLine());
		for (int i = 0; i < tests; i++) {
			int t = Integer.parseInt(r.readLine());
			String s = r.readLine();
			int na = Integer.parseInt(s.substring(0, s.indexOf(' ')));
			int nb = Integer.parseInt(s.substring(s.indexOf(' ') + 1));
			List<Entry> a2b = new ArrayList<Entry>();
			List<Entry> b2a = new ArrayList<Entry>();
			for (int j = 0; j < na; j++) {
				String[] ss = r.readLine().split(" |:");
				Entry e = new Entry();
				e.start = Integer.parseInt(ss[0]) * 60 + Integer.parseInt(ss[1]);
				e.end = Integer.parseInt(ss[2]) * 60 + Integer.parseInt(ss[3]);
				a2b.add(e);
			}
			for (int j = 0; j < nb; j++) {
				String[] ss = r.readLine().split(" |:");
				Entry e = new Entry();
				e.start = Integer.parseInt(ss[0]) * 60 + Integer.parseInt(ss[1]);
				e.end = Integer.parseInt(ss[2]) * 60 + Integer.parseInt(ss[3]);
				b2a.add(e);
			}
			
			Collections.sort(a2b);
			Collections.sort(b2a);

			int a = 0;
			int b = 0;
			
			while (a2b.size() > 0 || b2a.size() > 0) {
				Entry e1;
				boolean ab;
				if (b2a.size() == 0 || a2b.size() > 0 && a2b.get(0).start < b2a.get(0).start) {
					a++;
					e1 = a2b.remove(0);
					ab = true;
				} else {
					b++;
					e1 = b2a.remove(0);
					ab = false;
				}

				boolean found = true;
				while (found) {
					found = false;
					List<Entry> next = ab ? b2a : a2b;
					int ntime = e1.end + t;
					for (int j = 0; j < next.size(); j++) {
						Entry e = next.get(j);
						if (e.start >= ntime) {
							e1 = e;
							ab = !ab;
							next.remove(j);
							found = true;
							break;
						}
					}
				}
			}
			
			w.write("Case #" + (i + 1) + ": " + a + " " + b + "\n");
		}
		r.close();
		w.close();
	}
	
	static class Entry implements Comparable<Entry> {
		
		int start;
		int end;

		public int compareTo(Entry o) {
			if (start < o.start) return -1;
			if (start > o.start) return 1;
			return end - o.end;
		}
		
	}

}
