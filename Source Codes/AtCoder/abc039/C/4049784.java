import java.util.*;

public class Main {
	static final String[] KEY = new String[]{"WBWBWWBWBWBW", "WBWWBWBWBWWB", "WWBWBWBWWBWB", "WBWBWBWWBWBW", "WBWBWWBWBWWB", "WBWWBWBWWBWB", "WWBWBWWBWBWB"};
	static final String[] VALUE = new String[]{"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		for (int i = 0; i < KEY.length; i++) {
			if (s.startsWith(KEY[i])) {
				System.out.println(VALUE[i]);
				return;
			}
		}
	}
}