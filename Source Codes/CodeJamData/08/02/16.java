import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.ArrayList;

/**
 * @author Roman Elizarov
 */
public class B extends Thread {
	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		if (args.length == 0)
			args = new String[] { "B.in" };
		for (String infile : args)
			new B().go(infile);
	}

	private Scanner in;
	private PrintWriter out;

	private void go(String infile) throws FileNotFoundException, InterruptedException {
		open(infile);
		start();
		join();
		close();
	}

	private void open(String infile) throws FileNotFoundException {
		String outfile = infile.replaceFirst("(\\.in)?$", ".out");
		System.out.printf("Processing %s, writing %s...%n", infile, outfile);
		in = new Scanner(new File(infile));
		out = new PrintWriter(new File(outfile));
	}

	private void close() {
		if (in != null)
			in.close();
		if (out != null)
			out.close();
	}

	public void run() {
		int n = in.nextInt();
		for (int i = 1; i <= n; i++)
			doCase(i);
	}

	private static class Trip implements Comparable<Trip> {
		int f;
		int p;
		int q;

		private Trip(int f, int p, int q) {
			this.f = f;
			this.p = p;
			this.q = q;
		}

		public int compareTo(Trip o) {
			return p - o.p;
		}
	}

	private int nextTime() {
		String[] s = in.next().split(":");
		int hh = Integer.parseInt(s[0]);
		int mm = Integer.parseInt(s[1]);
		return hh * 60 + mm;
	}

	private void doCase(int caseNumber) {
		// read case
		int t = in.nextInt();
		int na = in.nextInt();
		int nb = in.nextInt();
		PriorityQueue<Trip> depart = new PriorityQueue<Trip>();
		for (int i = 0; i < na; i++) {
			depart.add(new Trip(0, nextTime(), nextTime()));
		}
		for (int i = 0; i < nb; i++) {
			depart.add(new Trip(1, nextTime(), nextTime()));
		}

		// solve case
		int[] s = new int[2];
		int[] rem = new int[2];

		ArrayList<PriorityQueue<Integer>> ready = new ArrayList<PriorityQueue<Integer>>();
		ready.add(new PriorityQueue<Integer>());
		ready.add(new PriorityQueue<Integer>());
		while (!depart.isEmpty()) {
			Trip trip = depart.remove();
			PriorityQueue<Integer> rq = ready.get(trip.f);
			while (!rq.isEmpty() && rq.peek() <= trip.p) {
				rq.remove();
				rem[trip.f]++;
			}
			if (rem[trip.f] == 0) {
				rem[trip.f]++;
				s[trip.f]++;
			}
			rem[trip.f]--;
			ready.get(1 - trip.f).add(trip.q + t);
		}

		// write case result
		out.printf("Case #%d: %d %d%n", caseNumber, s[0], s[1]);
	}
}