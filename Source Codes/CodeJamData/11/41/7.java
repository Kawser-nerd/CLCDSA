import java.io.*;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	class Segment implements Comparable<Segment> {
		int length;
		int speed;

		public Segment(int length, int speed) {
			this.length = length;
			this.speed = speed;
		}

		@Override
		public int compareTo(Segment o) {
			return speed - o.speed;
		}
	}
	
	private void solve() {
		int x = in.nextInt();
		int walk = in.nextInt();
		int run = in.nextInt() - walk;
		double runTime = in.nextInt();
		int n = in.nextInt();
		int endPrev = 0;
		ArrayList<Segment> segments = new ArrayList<Segment>();
		for (int i = 0; i < n; i++) {
			int begin = in.nextInt();
			int end = in.nextInt();
			int move = in.nextInt();
			segments.add(new Segment(begin - endPrev, walk));
			segments.add(new Segment(end - begin, walk + move));
			endPrev = end;
		}
		segments.add(new Segment(x - endPrev, walk));
		Collections.sort(segments);
		double ans = 0;
		for (Segment s : segments) {
			if (s.length == 0) {
				continue;
			}
			double d = s.length;
			double tIdeal = d / (s.speed + run);
			double t = Math.min(runTime, tIdeal);
			runTime -= t;
			ans += t + (d - (s.speed + run) * t) / s.speed;
		}
		out.println(ans);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
