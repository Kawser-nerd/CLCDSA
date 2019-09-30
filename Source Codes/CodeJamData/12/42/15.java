

import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class GCJ_R2_B {

	static boolean test = true;

	private void solve() throws Throwable {
		int t = iread();
		for (int i = 0; i < t; i++) {
			solveIt(i+1);
		}
	}
	
	class Person {
		int pos, width;

		public Person(int pos, int width) {
			super();
			this.pos = pos;
			this.width = width;
		}

		@Override
		public String toString() {
			return "Person [pos=" + pos + ", width=" + width + "]";
		}
		
	}
	
	private void solveIt(int casenr) throws Throwable {
		String ans = "";
		
		int w = iread();
		long m = lread(), n = lread();
		double[][] position = new double[w][2];
		
		List<Person> widths = new ArrayList<Person>(w);
		for (int i = 0; i < w; i++) {
			Person p = new Person(i, iread());
			widths.add(p);
		}
		Collections.sort(widths, new Comparator<Person>() {

			@Override
			public int compare(Person o1, Person o2) {
				return o2.width - o1.width;
			}
		});
		
		Person firstPerson = widths.get(0);
		double curY = 0, curX = -1*firstPerson.width;
		double lastSize = firstPerson.width;
		
		for (int i = 0; i < widths.size() ; i++) {
			Person person = widths.get(i);
			curX += person.width;
			
			if(curX > m){
				curX = 0;
				curY += lastSize + person.width;
				lastSize = person.width;
			}
			
			position[person.pos][0] = curX;
			position[person.pos][1] = curY;
			curX += person.width;
		}
		
		for (int i = 0; i < w; i++) {
			ans += position[i][0] + " " + position[i][1];
			if(i< w -1 ){
				ans += " ";
			}
		}
				
		String answerString = "Case #" + casenr + ": " + ans;
		out.write(answerString + "\n");
		System.out.println(answerString);
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		new GCJ_R2_B().solve();
		out.close();
	}

	public GCJ_R2_B() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
			out = new BufferedWriter(new FileWriter(getClass().getCanonicalName() + "-out.txt"));
		} else {
			new BufferedReader(inp);
		}
	}

	static InputStreamReader inp = new InputStreamReader(System.in);
	static BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
//	static BufferedWriter out;// = new BufferedWriter(new FileWriter("out.txt"));

	static String testDataFile = "B-large.in";
}