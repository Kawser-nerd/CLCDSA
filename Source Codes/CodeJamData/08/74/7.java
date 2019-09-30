import java.io.*;
import java.util.*;

// Library collections-generic: http://larvalabs.com/collections/
// Library colt: http://dsd.lbl.gov/~hoschek/colt/
// Library jung: http://jung.sourceforge.net/
// Library glpk: http://www.gnu.org/software/glpk/


public class JamD {

	public static void main(String[] args) throws Exception {
		String stem = "c:/jam/D-small-attempt0";
//		String stem = "c:/jam/testD";
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

	static int r, c;

	private static String solve(Scanner scan) throws Exception {
		r = scan.nextInt();
		c = scan.nextInt();
		scan.nextLine();
		int kx = 0, ky = 0;
		int mask = 0;
		for(int i = 0; i < r; i++) {
			String l = scan.nextLine();
			for(int j = 0; j < c; j++) {
				switch(l.charAt(j)) {
				case 'K':
					kx = j; ky = i;
					break;
				case '#':
					mask += getBit(j,i);
					break;
				case '.':
					break;
				default: throw new Exception();
				}
			}
		}
//		System.out.println(mask);
		int ret = negM(mask, kx, ky);
		return (ret > 0) ? "A" : "B";
	}

	static int [] dx = new int [] {-1, -1, -1, 0, 0, +1, +1, +1};
	static int [] dy = new int [] {-1, 0, +1, -1, +1, -1, 0, +1};

	private static int negM(int mask, int kx, int ky) {
//		System.out.println(mask + " "+  kx + " " + ky);

		int val = -1;

		for(int d = 0; d < 8; d++) {
			int nx = kx + dx[d], ny = ky + dy[d];
			if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
			if ((getBit(nx,ny) & mask) > 0) continue;

			val = Math.max(val, -negM(mask + getBit(kx,ky),nx,ny));
		}


		return val;
	}

	static int getBit(int x, int y) {
		return 1 << (x * 4 + y);
	}
}
