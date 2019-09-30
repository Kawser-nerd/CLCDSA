import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.TreeSet;

class Attack implements Comparable<Attack> {
	public Attack(int[] tmp) {
		this.nextAttackDay = tmp[0];
		this.attacksRemain = tmp[1];
		this.minX = tmp[2];
		this.maxX = tmp[3] - 1;
		this.strength = tmp[4];
		this.deltaDays = tmp[5];
		this.deltaX = tmp[6];
		this.deltaStr = tmp[7];
	}
	
	void next() {
		attacksRemain--;
		nextAttackDay += deltaDays;
		minX += deltaX;
		maxX += deltaX;
		strength += deltaStr;
	}
	
	@Override
	public int compareTo(Attack o) {
		if (nextAttackDay < o.nextAttackDay)
			return -1;
		if (nextAttackDay > o.nextAttackDay)
			return 1;
		return 0;
	}
	
	int nextAttackDay;
	int attacksRemain;
	int minX, maxX;
	int strength;
	
	int deltaDays;
	int deltaX;
	int deltaStr;
}

class Span {
	long minX, maxX;
	long height;
}

public class C {
	static String result(Attack[] atts) {
		int nAtts = atts.length;
		
		ArrayList<Span> spans = new ArrayList<Span>();
		Span init = new Span();
		init.minX = -1000000000000L;
		init.maxX =  1000000000000L;
		init.height = 0;
		spans.add(init);
		
		ArrayList<Attack> succ = new ArrayList<>();
		int res = 0;
		while (nAtts > 0) {
			succ.clear();
			Arrays.sort(atts, 0, nAtts);
			int nToday = 1;
			while (nToday < nAtts && atts[nToday].nextAttackDay == atts[0].nextAttackDay)
				nToday++;
			
			for (int a = 0; a < nToday; a++) {
				if (succeed(atts[a], spans)) {
					res++;
					succ.add(atts[a]);
				}
			}
			
			int nSucc = succ.size();
			for (int a = 0; a < nSucc; a++)
				raise(spans, succ.get(a));
			
			for (int a = nToday - 1; a >= 0; a--) {
				atts[a].next();
				if (atts[a].attacksRemain < 1) {
					atts[a] = atts[--nAtts];
				}
			}
		}
		return String.valueOf(res);
	}
	
	private static void raise(ArrayList<Span> spans, Attack attack) {
		long minX = attack.minX;
		long maxX = attack.maxX;
		long height = attack.strength;

		int nSpans = spans.size();
		int first = 0;
		int last = nSpans - 1;
		while (first < last) {
			int mid = first + (last - first) / 2;
			Span s = spans.get(mid);
			if (minX >= s.minX && minX <= s.maxX) {
				first = last = mid;
			} else
			if (minX > s.maxX) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}
		
		int pos = first;
		while (pos < spans.size()) {
			Span span = spans.get(pos);
			if (span.minX > maxX)
				break;
			
			if (span.height >= height) {
				pos++;
				continue;
			}
			
			if (minX > span.minX) {
				Span before = new Span();
				before.minX = span.minX;
				before.maxX = minX - 1;
				before.height = span.height;
				spans.add(pos++, before);
				span.minX = minX;
			}
			if (maxX < span.maxX) {
				Span after = new Span();
				after.minX = maxX + 1;
				after.maxX = span.maxX;
				after.height = span.height;
				spans.add(pos + 1, after);
				span.maxX = maxX;
			}
			span.height = height;
			pos++;
		}
	}

	private static boolean succeed(Attack attack, ArrayList<Span> spans) {
		long minX = attack.minX;
		long maxX = attack.maxX;
		long height = attack.strength;

		int nSpans = spans.size();
		int first = 0;
		int last = nSpans - 1;
		while (first < last) {
			int mid = first + (last - first) / 2;
			Span s = spans.get(mid);
			if (minX >= s.minX && minX <= s.maxX) {
				first = last = mid;
			} else
			if (minX > s.maxX) {
				first = mid + 1;
			} else {
				last = mid - 1;
			}
		}
		
		while (first < nSpans) {
			Span span = spans.get(first++);
			if (span.minX > maxX)
				break;
			if (span.height < height)
				return true;
		}
		return false;
	}

	static void go(String inputFile) throws Exception {
		LineNumberReader in = new LineNumberReader(new FileReader(inputFile));
		FileWriter out = new FileWriter(inputFile + ".out");
		
		int nCases = Integer.parseInt(in.readLine());
		for (int c = 1; c <= nCases; c++) {
			int nTribes = Integer.parseInt(in.readLine());
			Attack[] atts = new Attack[nTribes];
			for (int a = 0; a < nTribes; a++) {
				int[] tmp = toInts(in.readLine());
				Attack att = new Attack(tmp);
				atts[a] = att;
			}
			
			String res = result(atts);
			String line = "Case #" + c + ": " + res;
			System.out.println(line);
			out.write(line + "\n");
		}
		out.close();
	}
	
	static int[] toInts(String s) {
		String[] tmp = s.trim().split(" ");
		int n = tmp.length;
		int[] res = new int[n];
		for (int a = 0; a < n; a++)
			res[a] = Integer.parseInt(tmp[a]);
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		LineNumberReader sysIn = new LineNumberReader(new InputStreamReader(System.in));
		String line;
		while ((line = sysIn.readLine()) != null) {
			go(line.trim());
		}
	}
}
