import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Word[] words = new Word[n];
		for (int i = 0; i < n; i++) {
			words[i] = new Word(sc.next());
		}
		Arrays.sort(words, new Comparator<Word>() {
		public int compare(Word w1, Word w2) {
			return w1.reverse.compareTo(w2.reverse);
		}
		});
		StringBuilder sb = new StringBuilder();
		for (Word w : words) {
			sb.append(w).append("\n");
		}
		System.out.print(sb);
	}
	
	static class Word {
		String s;
		String reverse;
		public Word(String s) {
			this.s = s;
			reverse = new StringBuilder(s).reverse().toString();
		}
		
		public String toString() {
			return s;
		}
	}
}