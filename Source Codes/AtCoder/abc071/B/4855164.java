import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String inputText = sc.nextLine();
		HashSet<String> set = new HashSet<>();
		for(int i = 0; i < inputText.length(); i++) {
			set.add(String.valueOf(inputText.charAt(i)));
		}
		if(set.size() == 26) {
			System.out.println("None");
		}else {
			char c = 'a';
			for(int i = 0; i < 26; i++) {
				if(set.contains(String.valueOf(c))) {
					c++;
					continue;
				}
				System.out.println(c);
				break;
			}			
		}

		
		
		
		
		
	}	

}