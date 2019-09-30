import java.util.*;
import java.io.*;

public class TrainTimetable {
	class Event implements Comparable<Event> {
		int st, fn, ind;
		
		public Event(int st, int fn, int ind) {
			this.st = st;
			this.fn = fn;
			this.ind = ind;
		}
		
		public int compareTo(Event other) {
			return this.st - other.st;
		}
	}
	
	int parseTime(String s) {
		int h = 10 * (s.charAt(0) - '0') + (s.charAt(1) - '0');
		int m = 10 * (s.charAt(3) - '0') + (s.charAt(4) - '0');
		return 60 * h + m;
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int cases = sc.nextInt();
		for (int caseNum=0; caseNum<cases; caseNum++) {
			pw.print("Case #" + (caseNum+1) + ": ");
			int tt = sc.nextInt();
			int nA = sc.nextInt(), nB = sc.nextInt();
			Event[] events = new Event[nA+nB];
			int pos = 0;
			for (int i=0; i < nA; i++)
				events[pos++] = new Event(parseTime(sc.next()), parseTime(sc.next()), 0);
			for (int i=0; i < nB; i++)
				events[pos++] = new Event(parseTime(sc.next()), parseTime(sc.next()), 1);
			Arrays.sort(events);
			List<Integer> tA = new ArrayList<Integer>();
			List<Integer> tB = new ArrayList<Integer>();
			int cA = 0, cB = 0;
			for (int i=0; i < events.length; i++)
				if (events[i].ind == 0) {
					boolean find = false;
					for (int j=0; j < tA.size(); j++)
						if (tA.get(j) <= events[i].st - tt) {
							tA.remove(j);
							find = true;
							break;
						}
					tB.add(events[i].fn);
					if (!find) cA++;
				} else {
					boolean find = false;
					for (int j=0; j < tB.size(); j++)
						if (tB.get(j) <= events[i].st - tt) {
							tB.remove(j);
							find = true;
							break;
						}
					tA.add(events[i].fn);
					if (!find) cB++;
				}
			pw.println(cA + " " + cB);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new TrainTimetable()).doMain();
	}
}
