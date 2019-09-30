package zshao;

import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.HashMap;
import java.util.ArrayList;

public class CodeJamA {

	
	
	public static void main(String[] args) {
		
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String line = in.readLine();
			int total = Integer.valueOf(line);
			for (int n=1; n <= total; n++) {
				line = in.readLine();

				HashMap<Character, Integer> m = new HashMap<Character, Integer>();
				for (int i=0; i<line.length(); i++) {
					char c = line.charAt(i);
					if (m.get(c) == null) {
						if (m.size() == 0) {
							m.put(c, 1);
						} else if (m.size() == 1) {
							m.put(c, 0);
						} else {
							m.put(c, m.size());
						}
					}
				}
				
				long r = 0;
				for (int i=0; i<line.length(); i++) {
					r = r * Math.max(m.size(), 2) + m.get(line.charAt(i)); 
				}
				System.out.println("Case #" + n + ": " + r);
			}
		} catch (Throwable e) {
			e.printStackTrace();
		}

	}

}
