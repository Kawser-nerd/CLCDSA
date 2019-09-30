import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	final static String takahashikun = "takahashikun";
	final static String TAKAHASHIKUN  = "TAKAHASHIKUN";
	final static String Takahashikun = "Takahashikun";

	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		int number = Integer.parseInt(br.readLine());
		String inputSentence = br.readLine();
		String[] words = inputSentence.split(" ");
		int count = 0;
		for(int i=0;i<number;i++) {
			if(i==number-1) {
				words[i]=words[i].substring(0, words[i].length()-1);
			}
			if(words[i].equals(takahashikun) || words[i].equals(Takahashikun) || words[i].equals(TAKAHASHIKUN)){
				count++;
			}
		}
		System.out.println(count);
	}
}