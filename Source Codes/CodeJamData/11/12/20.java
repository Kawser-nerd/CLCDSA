import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collection.*;
public class B implements Comparable<B>{
	boolean contains;
	int points;
	char[] compare;
	LinkedList<char[]> words;
	public B(int length) {
		compare = new char[length];
		fill(compare, '*');
		points = 0;
		words = new LinkedList<char[]>();
		contains = false;
	}
	public B(B template, char[] word, char letter) {
		contains = false;
		points = template.points;
		compare = new char[template.compare.length];
		arraycopy(template.compare, 0, compare, 0, compare.length);
		for(int i = 0; i < word.length; i++)
			if(word[i] == letter)
				contains = (compare[i] = letter) == letter;
		words = new LinkedList<char[]>();
		words.add(word);
	}
	public TreeSet<B> split(char c)
	{
		TreeSet<B> ts = new TreeSet<B>();
		for(char[] word : words) {
			B child = new B(this, word, c);
			if(!ts.add(child))
				ts.floor(child).words.addAll(child.words);
		}
		return ts;
	}
	public int compareTo(B b) {
		if(compare.length != b.compare.length)
			return compare.length - b.compare.length;
		for(int i = 0; i < compare.length; i++)
			if(compare[i] != b.compare[i])
				return compare[i] - b.compare[i];
		return 0;
	}
	public static HashMap<String, Integer> recurse(TreeSet<B> start, char[] alphabet) {
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		for(char a : alphabet) {
			TreeSet<B> next = new TreeSet<B>();
			for(B b : start) {
				TreeSet<B> split = b.split(a);
				B first = split.first();
				if(!first.contains && split.size() != 1)
					first.points++;
				for(B b2 : split) {
					if(b2.words.size() == 1) {
						hm.put(new String(b2.words.peek()), b2.points);
					} else if(!next.add(b2))
						err.println("Problem");
				}
			}
			start = next;
		}
		return hm;
	}
	public String toString() {
		String out = "[ " + new String(compare) + " : " + contains + " "  + points + " -> [ ";
		for(char[] c : words)
			out += new String(c) + ", ";
		out = out.substring(0, out.length() - 2);
		return out + "]]";
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		int T = parseInt(br.readLine());
		for(int t = 0; t++ < T;) {
			String[] line = br.readLine().split(" ");
			int N = parseInt(line[0]),
				M = parseInt(line[1]);
			String out = "";
			LinkedList<String> dictionary = new LinkedList<String>();
			B[] bs = new B[11];
			for(int i = 0; i < 11; i++)
				bs[i] = new B(i);
			for(int n = 0; n < N; n++) {
				String s = br.readLine();
				dictionary.offer(s);
				bs[s.length()].words.add(s.toCharArray());
			}
			TreeSet<B> start = new TreeSet<B>();
			for(B b : bs)
				if(b.words.size() != 0)
					start.add(b);
			for(int m = 0; m < M; m++) {
				String alphabet = br.readLine();
				HashMap<String, Integer> hm = recurse(start, alphabet.toCharArray());
				String best = "";
				int max = -1;
				for(String d : dictionary) {
					if(hm.get(d) > max) {
						max = hm.get(d);
						best = d;
					}
				}
				out += " " + best;
			}
			System.out.println("Case #" + t + ":" + out);
		}
	}
}
