import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int times = Integer.valueOf(s.nextLine());
		
		ArrayList<String> list = new ArrayList<String>();
		String word = s.nextLine();
		for(int x=0;x<word.length();x++) {
			list.add(""+word.charAt(x));
		}
		
		for(int x=1;x<times;x++) {
			ArrayList<String> temp = new ArrayList<String>();
			word = s.nextLine();
			for(int y=0;y<word.length();y++) {
				String a = ""+word.charAt(y);
				if(list.contains(a)) {
					list.remove(list.indexOf(a));
					temp.add(a);
				}
			}
			list = temp;
		}
		
		Collections.sort(list);
		String build = "";
		for(String thing : list)
			build+= thing;
		
		System.out.println(build);
	}
}