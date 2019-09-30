import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int acgtLength = 0;
		int acgtMaxLength = 0;
		String[] acgt = {"A", "C", "G", "T"};
		List<String> acgtList = Arrays.asList(acgt);
		for(int i = 0; i < s.length(); i++) {
			String tmpStr = s.substring(i, i+1);
			if(acgtList.contains(tmpStr)) {
				acgtLength++;
			} else {
				acgtLength = 0;
			}
			if(acgtLength > acgtMaxLength) {
				acgtMaxLength = acgtLength;
			}
		}
		System.out.println(acgtMaxLength);
	}
}