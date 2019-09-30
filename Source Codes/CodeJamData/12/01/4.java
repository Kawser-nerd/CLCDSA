package pl.helman.codejam.speaking;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Speaking {

	private static char[] tab = new char[255];

	static {
		tab['y'] = 'a';
		tab['n'] = 'b';
		tab['f'] = 'c';
		tab['i'] = 'd';
		tab['c'] = 'e';
		tab['w'] = 'f';
		tab['l'] = 'g';
		tab['b'] = 'h';
		tab['k'] = 'i';
		tab['u'] = 'j';
		tab['o'] = 'k';
		tab['m'] = 'l';
		tab['x'] = 'm';
		tab['s'] = 'n';
		tab['e'] = 'o';
		tab['v'] = 'p';
		tab['z'] = 'q';
		tab['p'] = 'r';
		tab['d'] = 's';
		tab['r'] = 't';
		tab['j'] = 'u';
		tab['t'] = 'w';
		tab['g'] = 'v';
		tab['h'] = 'x';
		tab['a'] = 'y';
		tab['q'] = 'z';
		tab[' '] = ' ';
	}

	private static String transform(String in) {
		StringBuilder sb = new StringBuilder();
		for (char ch : in.toCharArray()) {
			sb.append(tab[ch]);
		}

		return sb.toString();
	}

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\speaking.in");
		BufferedReader br = new BufferedReader(fr);
		String s = br.readLine();

		FileWriter f0 = new FileWriter("d:\\speaking.out"); 
		
		int n = Integer.parseInt(s.trim());

		for (int i = 1; i <= n; i++) {
			s = br.readLine();
			System.out.println("Case #" + i + ": " + transform(s));
			f0.write("Case #" + i + ": " + transform(s)+"\r\n");
		}

		fr.close();
		f0.close();
		
	}

}
