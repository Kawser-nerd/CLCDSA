package google.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SpeakingInTongues {
	
	private static String TRANSLATER = "yhesocvxduiglbkrztnwjpfmaq";
	
	private static char translate(char ch) {
		if ('a' <= ch & ch <= 'z')
			return TRANSLATER.charAt(ch - 'a');
		else
			return ch;
	}
	
	private static String translate(String s) {
		int l = s.length();
		StringBuilder translated = new StringBuilder(l);
		for (int i = 0; i < l; i++) {
			translated.append(translate(s.charAt(i)));
		}
		return translated.toString();
	}
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 64 << 10);
			int testsNumber = Integer.parseInt(br.readLine().trim());
			for (int test = 1; test <= testsNumber; test++) {
				System.out.println("Case #" + test + ":" + translate(br.readLine()));
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
