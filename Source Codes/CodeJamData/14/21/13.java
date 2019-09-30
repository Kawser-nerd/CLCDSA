import javax.swing.*;
import java.io.*;
import java.util.Arrays;

public class Repeater {
	private final File inputFile;
	private final File outputFile;
	private final LineNumberReader reader;
	private final StringBuilder result;

	public Repeater(File inputFile) throws FileNotFoundException {
		this.inputFile = inputFile;
		this.outputFile = new File(inputFile.getParentFile(), inputFile.getName() + ".out");
		this.reader = new LineNumberReader(new FileReader(inputFile));
		this.result = new StringBuilder();
	}

	int result(String[] inputs) {
		int n = inputs.length;
		String[] norms = new String[n];
		for (int a = 0; a < n; a++) {
			norms[a] = normalize(inputs[a]);
		}
		Arrays.sort(norms);
		if (!norms[0].equals(norms[n - 1]))
			return -1;

		int[] pos = new int[n];
		int[] len = new int[n];
		int result = 0;
		while (pos[0] < inputs[0].length()) {
			int min = 1000, max = 0;

			for (int a = 0; a < n; a++) {
				String s = inputs[a];
				len[a] = 1;
				while (pos[a] + len[a] < s.length() && s.charAt(pos[a] + len[a]) == s.charAt(pos[a]))
					len[a]++;
				min = Math.min(min, len[a]);
				max = Math.max(max, len[a]);
			}

			int best = Integer.MAX_VALUE;
			for (int t = min; t <= max; t++) {
				int sum = 0;
				for (int a = 0; a < n; a++)
					sum += Math.abs(len[a] - t);
				if (sum < best)
					best = sum;
			}
			result += best;

			for (int a = 0; a < n; a++)
				pos[a] += len[a];
		}
		
		return result;
	}

	String normalize(String s) {
		StringBuilder res = new StringBuilder();
		char last = 0;
		for (char c : s.toCharArray()) {
			if (c != last)
				res.append(c);
			last = c;
		}
		return res.toString();
	}

	void process() throws IOException {
		int nCases = readInt();
		for (int c = 1; c <= nCases; c++) {
			int nString = readInt();
			String[] strings = new String[nString];
			for (int a = 0; a < nString; a++)
				strings[a] = reader.readLine().trim();

			int result = result(strings);
			writeln("Case #" + c + ": " + (result < 0 ? "Fegla Won" : "" + result));
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
            new Repeater(jfc.getSelectedFile()).process();
        }
    }
}
