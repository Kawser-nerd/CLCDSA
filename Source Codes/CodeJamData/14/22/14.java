import javax.swing.*;
import java.io.*;

public class Lottery {
	private final File inputFile;
	private final File outputFile;
	private final LineNumberReader reader;
	private final StringBuilder result;

	public Lottery(File inputFile) throws FileNotFoundException {
		this.inputFile = inputFile;
		this.outputFile = new File(inputFile.getParentFile(), inputFile.getName() + ".out");
		this.reader = new LineNumberReader(new FileReader(inputFile));
		this.result = new StringBuilder();
	}

	long result(int A, int B, int K) {
		long result = 0;

		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++)
				if ((a & b) < K)
					result++;
		
		return result;
	}



	void process() throws IOException {
		int nCases = readInt();
		for (int c = 1; c <= nCases; c++) {
			int[] data = readInts();
			long result = result(data[0], data[1], data[2]);
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
            new Lottery(jfc.getSelectedFile()).process();
        }
    }
}
