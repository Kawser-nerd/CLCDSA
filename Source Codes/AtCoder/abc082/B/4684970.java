import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		String w1 = b.readLine();
		String w2 = b.readLine();
		String s1 = Arrays.stream(w1.split("")).sorted().collect(Collectors.joining());
		String s2 = Arrays.stream(w2.split("")).sorted(Comparator.reverseOrder()).collect(Collectors.joining());
		String a = s2.compareTo(s1) > 0 ? "Yes" : "No" ;
		System.out.println(a);
	}
}