import java.io.*;
import java.util.*;

// Library collections-generic: http://larvalabs.com/collections/
// Library colt: http://dsd.lbl.gov/~hoschek/colt/
// Library jung: http://jung.sourceforge.net/
// Library glpk: http://www.gnu.org/software/glpk/


public class JamA {

	public static void main(String[] args) throws FileNotFoundException {
		String stem = "c:/jam/A-large";
//		String stem = "c:/jam/testA";
		Scanner scan = new Scanner(new File(stem+".in"));

		int np = scan.nextInt();

		PrintWriter pw = new PrintWriter(new FileOutputStream(stem+".out"));
		for(int i = 1; i <= np; i++) {
			String ret = solve(scan);
			pw.println("Case #" + i + ": " + ret);
			System.out.println("Case #" + i + ": " + ret);
		}
		pw.close();
	}

	@SuppressWarnings("unchecked")
	private static String solve(Scanner scan) {
		int n = scan.nextInt();
		scan.nextLine();
		Map<String, List<String>> ings = new HashMap();
		String root = "";
		for(int i = 0; i < n; i++) {
			String l = scan.nextLine();
//			System.out.println(l);
			String [] tks = l.split(" ");
			if (i == 0) root = tks[0];

			List<String> it = new ArrayList();
			for(int j = 2; j < tks.length; j++) {
				it.add(tks[j]);
			}
			ings.put(tks[0],it);
		}

		return ""+dos(ings, root);
	}

	private static int dos(Map<String, List<String>> ings, String root) {
		List<String> it = ings.get(root);
//		int mi = 0;
//		int ni = 0;
		List<Integer> nis = new ArrayList();
		for(String ing : it) {
			if (Character.isUpperCase(ing.charAt(0))) {
				nis.add(dos(ings,ing));
//				ni++;
//				int rec = dos(ings, ing);
//				mi = Math.max(rec, mi);
			}
		}

		int mx = 0;
		Collections.sort(nis);
		for(int i = 0; i < nis.size(); i++) {
			mx = Math.max(mx, nis.get(i) + nis.size() - 1 - i);
		}

//		System.out.println(root + " " + mx);
		return Math.max(mx, nis.size() + 1);
	}

}
