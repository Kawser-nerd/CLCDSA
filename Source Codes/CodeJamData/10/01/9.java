/*
 * Abstract class that reads either the standard input, a named file, or prompts at the terminal.
 * Implement "process" for each CodeJam problem.
 * Reads input through a ReadWrapper, wrapping a BufferedReader.
 */

import java.io.*;
import java.util.StringTokenizer;
import java.text.*;

public abstract class CodeJammer {

	protected ReadWrapper reader;
	private int caseNum = 1;
	
	//Processes one case
	public abstract void process() throws IOException;
	
	//Process all cases... usually just read the number of them and then run process on each.
	//Override if necessary.
	public void processAll() throws IOException {
		int numTrials = reader.readInt();
		for (int i=0; i<numTrials; i++) {
			process();
		}
	}
	
	public void output(String s) {
		if (s == null) System.out.println("Case #" + (caseNum++) + ":"); //no space
		else System.out.println("Case #" + (caseNum++) + ": " + s);
	}
	
	public void output(int n) {
		output(Integer.toString(n));
	}
	
	public void output(long n) {
		output(Long.toString(n));
	}
	
	//Prints a double with the specified number of digits after the decimal.
	public void output(double d, int digits) {
		String s = "0.";
		for (int i=0; i<digits; i++) s += "0";
		DecimalFormat f = new DecimalFormat(s);
		output(f.format(d));
	}
	
	public void output(double d) {
		output(Double.toString(d));
	}
	
	public void output(int[] array) {
		String s = "";
		for (int i=0; i<array.length; i++)
			s += " " + array[i];
		output(s.substring(1));
	}
	
	public void output(char[] array) {
		String s = "";
		for (int i=0; i<array.length; i++)
			s += " " + array[i];
		output(s.substring(1));
	}
	
	public void run(String[] args) {
		BufferedReader buff;
		if (args.length == 0) {
			buff = new BufferedReader(new InputStreamReader(System.in));
		} else {
			String filename = args[0];
			try {
				buff = new BufferedReader(new FileReader(filename));
			} catch (FileNotFoundException ex) {
				System.out.println("File not found.");
				return;
			}
		}
		reader = new ReadWrapper(buff);
		try {
			processAll();
		} catch (IOException ex) {
			System.out.println(ex.getMessage());
		}
	}
	
	public static class ReadWrapper {
		
		private BufferedReader in;
		
		public ReadWrapper(BufferedReader in) {
			this.in = in;
		}
		
		public String readString() throws IOException {
			return in.readLine();
		}
		
		public int readInt() throws IOException {
			String line = in.readLine();
			try {
				return Integer.parseInt(line);
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected an int and read " + line));
			}
		}
		
		public int[] readArray() throws IOException {
			String line = in.readLine();
			try {
				StringTokenizer t = new StringTokenizer(line);
				int[] result = new int[t.countTokens()];
				for (int i=0; t.hasMoreTokens(); i++) {
					result[i] = Integer.parseInt(t.nextToken());
				}
				return result;
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected an int array and read " + line));
			}
		}
		
		public long readLong() throws IOException {
			String line = in.readLine();
			try {
				return Long.parseLong(line);
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected a long and read " + line));
			}
		}
		
		public long[] readLongArray() throws IOException {
			String line = in.readLine();
			try {
				StringTokenizer t = new StringTokenizer(line);
				long[] result = new long[t.countTokens()];
				for (int i=0; t.hasMoreTokens(); i++) {
					result[i] = Long.parseLong(t.nextToken());
				}
				return result;
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected a long array and read " + line));
			}
		}
		
		public double readDouble() throws IOException {
			String line = in.readLine();
			try {
				return Double.parseDouble(line);
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected a double and read " + line));
			}
		}
		
		public double[] readDoubleArray() throws IOException {
			String line = in.readLine();
			try {
				StringTokenizer t = new StringTokenizer(line);
				double[] result = new double[t.countTokens()];
				for (int i=0; t.hasMoreTokens(); i++) {
					result[i] = Double.parseDouble(t.nextToken());
				}
				return result;
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected a double array and read " + line));
			}
		}
		
		public String[] readStringArray() throws IOException {
			String line = in.readLine();
			try {
				StringTokenizer t = new StringTokenizer(line);
				String[] result = new String[t.countTokens()];
				for (int i=0; t.hasMoreTokens(); i++) {
					result[i] = t.nextToken();
				}
				return result;
			} catch (NumberFormatException ex) {
				throw (new IOException("ReadWrapper expected a String array and read " + line));
			}
		}
		
		//Methods to read a single token at a time... for cases where input goes over multiple lines
		private StringTokenizer t = null;
		private String delims = null;
		private boolean returnDelims = false;
		
		public void setDelims(String delims, boolean returnThem) {
			this.delims = delims;
			returnDelims = returnThem;
		}
		
		public String getToken() throws IOException {
			while (t==null || !t.hasMoreTokens()) {
				if (delims == null) {
					t = new StringTokenizer(readString());
				} else {
					t = new StringTokenizer(readString(), delims, returnDelims);
				}
			}
			return t.nextToken();
		}
		
		public int getInt() throws IOException {
			String s = getToken();
			try {
				return Integer.parseInt(s);
			} catch (NumberFormatException e) {
				throw (new IOException("ReadWrapper expected an int and read " + s));
			}
		}
		
		public long getLong() throws IOException {
			String s = getToken();
			try {
				return Long.parseLong(s);
			} catch (NumberFormatException e) {
				throw (new IOException("ReadWrapper expected a long and read " + s));
			}
		}
		
		public double getDouble() throws IOException {
			String s = getToken();
			try {
				return Double.parseDouble(s);
			} catch (NumberFormatException e) {
				throw (new IOException("ReadWrapper expected a double and read " + s));
			}
		}
		
	}
	
}
