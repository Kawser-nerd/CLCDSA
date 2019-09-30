import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class ProblemB {
	
	public static void main(String[] args) throws Exception {
		
		try (Scanner sc = new Scanner(System.in)) 
		{
			int cases = sc.nextInt();
			
			for (int caseNum=1; caseNum<=cases; caseNum++)
			{
				solve(sc, caseNum);
			}
		}
	}
	
	static void solve(Scanner sc, int caseNum) throws Exception
	{
		int AC = sc.nextInt();
		int AJ = sc.nextInt();
		
		if (AC+AJ==0) {
			System.out.printf("Case #%d: 2\n", caseNum);
			return;
		}
		
		int totalC = 0, totalJ = 0;
		Act[] acts = new Act[AC+AJ];
		for (int i=0; i<AC; i++) {
			acts[i] = new Act(sc.nextInt(), sc.nextInt(), true);
			totalC += acts[i].t-acts[i].s;
		}
		for (int i=AC; i<AC+AJ; i++) {
			acts[i] = new Act(sc.nextInt(), sc.nextInt(), false);
			totalJ += acts[i].t-acts[i].s;
		}
		Arrays.sort(acts, (a1,a2)->a1.s-a2.s);
		
		
		ArrayList<Integer> cSlots = new ArrayList<>();
		ArrayList<Integer> jSlots = new ArrayList<>();
		ArrayList<Integer> cfSlots = new ArrayList<>();
		ArrayList<Integer> jfSlots = new ArrayList<>();
		for (int i=0; i<AC+AJ-1; i++) {
			int dur = acts[i+1].s-acts[i].t;
			if (acts[i].cam==acts[i+1].cam) {
				if (acts[i].cam) {
					cSlots.add(dur);
				} else {
					jSlots.add(dur);
				}
			} else {
				if (acts[i].cam) {
					cfSlots.add(dur);
				} else {
					jfSlots.add(dur);
				}
			}
		}
		int dur = acts[0].s-acts[AC+AJ-1].t + 1440;
		if (acts[AC+AJ-1].cam==acts[0].cam) {
			if (acts[AC+AJ-1].cam) {
				cSlots.add(dur);
			} else {
				jSlots.add(dur);
			}
		} else {
			if (acts[AC+AJ-1].cam) {
				cfSlots.add(dur);
			} else {
				jfSlots.add(dur);
			}
		}
		Collections.sort(cSlots);
		Collections.sort(jSlots);
		
		int i=0;
		for (; i<cSlots.size(); i ++) {
			if (cSlots.get(i) <= 720-totalC) {
				totalC += cSlots.get(i);
			} else {
				break;
			}
		}
		int j=0;
		for (; j<jSlots.size(); j++) {
			if (jSlots.get(j) <= 720-totalJ) {
				totalJ += jSlots.get(j);
			} else {
				break;
			}
		}
		
		if (i<cSlots.size() && j<jSlots.size()) throw new Exception();
		
		int total = cfSlots.size() + jfSlots.size() + 
				2* (cSlots.size()-i + jSlots.size()-j);
		
		System.out.printf("Case #%d: %d\n", caseNum, total);
	}

	static class Act {
		int s,t;
		boolean cam;
		public Act(int s, int t, boolean cam) {
			super();
			this.s = s;
			this.t = t;
			this.cam = cam;
		}
		
	}
	
//	static class Slot {
//		int l;
//		public Slot(int l) {
//			super();
//			this.l = l;
//		}
//		
//	}
}
