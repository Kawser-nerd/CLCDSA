import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;


public class InputFileParser implements Iterable<String[]> {
	
	private final int linesPerCase;
	private final int totalCases;
	private BufferedReader reader;
	
	private int casesExtracted = 0;

	public InputFileParser(int linesPerCase, String fileName) {
		this.linesPerCase = linesPerCase;
		try {
			FileReader fileReader = new FileReader(fileName);
	
			this.reader = new BufferedReader(fileReader);
			String line = this.reader.readLine();
			this.totalCases = Integer.parseInt(line);
		} catch (IOException e) {
			throw new IllegalStateException(e);
		}
	}
	
	private String readLine() {
		try {
			return this.reader.readLine();
		} catch (IOException e) {
			throw new IllegalStateException(e);
		}
	}

	@Override
	public Iterator<String[]> iterator() {
		return new Iterator<String[]>() {

			@Override
			public boolean hasNext() {
				return casesExtracted < totalCases;
			}

			@Override
			public String[] next() {
				String[] caseLines = new String[linesPerCase];
				for (int i = 0; i < linesPerCase; i++ ) {
					caseLines[i] = readLine();
				}
				casesExtracted++;
				return caseLines;
			}

			@Override
			public void remove() {
				// TODO Auto-generated method stub
				
			}
			
		};
	}
	


}
