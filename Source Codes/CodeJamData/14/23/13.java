import javax.swing.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Travel {
	private final File inputFile;
	private final File outputFile;
	private final LineNumberReader reader;
	private final StringBuilder result;

	static class City implements Comparable<City> {
		final int zip;
		City[] conns = { };
		boolean reachable;
		public int index;
		public State state;
		final boolean[] direct;

		City(int zip, int nAll) {
			this.zip = zip;
			this.direct = new boolean[nAll];
			this.state = State.INITIAL;
		}

		void add(City other) {
			direct[other.index] = true;

			City[] n = new City[conns.length + 1];
			System.arraycopy(conns, 0, n, 0, conns.length);
			n[conns.length] = other;
			conns = n;
			Arrays.sort(n);
		}

		boolean direct(City other) {
			return direct[other.index];
		}

		@Override
		public int compareTo(City o) {
			return Integer.compare(zip, o.zip);
		}
	}

	public Travel(File inputFile) throws FileNotFoundException {
		this.inputFile = inputFile;
		this.outputFile = new File(inputFile.getParentFile(), inputFile.getName() + ".out");
		this.reader = new LineNumberReader(new FileReader(inputFile));
		this.result = new StringBuilder();
	}

	enum State {
		INITIAL, OPEN, DONE
	}

	String result(City[] cities) {
		StringBuilder res = new StringBuilder();
		ArrayList<City> open = new ArrayList<>();
		open(cities[0], open, res);

		nextStep:
		while (!open.isEmpty()) {
			City[] candidates = candidates(cities);
			if (candidates.length < 1) {
				open.remove(open.size() - 1);
				continue;
			}

			Arrays.sort(candidates);
			for (int a = 0; a < candidates.length; a++) {
				City cand = candidates[a];
				int reachableFrom = open.size() - 1;
				while (!cand.direct(open.get(reachableFrom)))
					reachableFrom--;

				cand.state = State.OPEN;
				for (int b = reachableFrom + 1; b < open.size(); b++)
					open.get(b).state = State.DONE;

				if (allReachable(cities)) {
					while (open.size() > reachableFrom + 1)
						open.remove(open.size() - 1);
					open.add(cand);
					res.append(cand.zip);
					continue nextStep;
				} else {
					cand.state = State.INITIAL;
					for (int b = reachableFrom + 1; b < open.size(); b++)
						open.get(b).state = State.OPEN;
				}
			}
		}
		return res.toString();
	}

	boolean allReachable(City[] cities) {
		ArrayList<City> open = new ArrayList<>();
		for (City city : cities) {
			switch (city.state) {
				case DONE:
					city.reachable = true;
					break;
				case OPEN:
					city.reachable = true;
					open.add(city);
					break;
				case INITIAL:
					city.reachable = false;
					break;
			}
		}
		while (!open.isEmpty()) {
			City last = open.remove(open.size() - 1);
			for (City conn : last.conns) {
				if (conn.state == State.INITIAL && !conn.reachable) {
					conn.reachable = true;
					open.add(conn);
				}
			}
		}
		for (City city : cities)
			if (!city.reachable)
				return false;
		return true;
	}

	City[] candidates(City[] all) {
		ArrayList<City> res = new ArrayList<>();
		nextCity:
		for (City c : all) {
			if (c.state != State.INITIAL)
				continue;
			for (City from: c.conns) {
				if (from.state == State.OPEN) {
					res.add(c);
					continue nextCity;
				}
			}
		}
		return res.toArray(new City[res.size()]);
	}

	private void open(City city, ArrayList<City> open, StringBuilder res) {
		if (city.state != State.INITIAL)
			throw new IllegalStateException();

		city.state = State.OPEN;
		open.add(city);
		res.append(city.zip);
	}

	void process() throws IOException {
		int nCases = readInt();
		for (int c = 1; c <= nCases; c++) {
			int[] data = readInts();
			int nCities = data[0];
			int nRoutes = data[1];
			City[] cities = new City[nCities];
			for (int a = 0; a < nCities; a++) {
				cities[a] = new City(readInt(), nCities);
			}
			for (int a = 0; a < nCities; a++)
				cities[a].index = a;
			for (int a = 0; a < nRoutes; a++) {
				data = readInts();
				int from = data[0] - 1;
				int to = data[1] - 1;
				cities[from].add(cities[to]);
				cities[to].add(cities[from]);
			}
			Arrays.sort(cities);


			String result = result(cities);
			writeln("Case #" + c + ": " + result);
		}

		done();
	}

	int readInt() throws IOException {
		return readInts()[0];
	}

	int[] readInts() throws IOException {
		String l = reader.readLine().trim();
		String[] parts = l.split(" ");
		int[] res = new int[parts.length];
		for (int a = 0; a < res.length; a++)
			res[a] = Integer.parseInt(parts[a]);
		return res;
	}

	void writeln(String s) {
		write(s + "\n");
	}

	void write(String s) {
		System.out.print(s);
		result.append(s);
	}

	void done() throws IOException {
		FileOutputStream fos = new FileOutputStream(outputFile);
		fos.write(result.toString().getBytes("UTF-8"));
		fos.close();

		System.out.println(inputFile + " => " + outputFile);
	}

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("/home/mitja/codejam"));
        if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
            new Travel(jfc.getSelectedFile()).process();
        }
    }
}
