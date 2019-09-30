import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Collectors;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		String word1 = stdin.readLine();
		String word2 = stdin.readLine();
		String sorted1 = Arrays.stream(word1.split("")).sorted().collect(Collectors.joining());
		String sorted2 = Arrays.stream(word2.split("")).sorted(Comparator.reverseOrder()).collect(Collectors.joining());
		String answer = sorted2.compareTo(sorted1) > 0 ? "Yes" : "No" ;
		System.out.println(answer);
	}

}