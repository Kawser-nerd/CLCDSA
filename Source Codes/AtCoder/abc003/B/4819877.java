import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){

		String a = sc.next();
		String b = sc.next();
		String c = null;
		String[]list = new String[a.length()];
		String[]list2 = new String[a.length()];
		for (int i = 0;i < a.length();i++){
			list[i] = String.valueOf(a.charAt(i));
			list2[i] = String.valueOf(b.charAt(i));
		}
		String atc = "[a|t|c|o|d|e|r]";
		boolean bl = false;
		
//		int b = Integer.parseInt(sc.next());
		
		for(int i = 0; i < a.length();i++){
			if(bl == true || i == 0){
				if(list[i].equals(list2[i])){
					bl = true;
				}else if(list[i].equals("@")){
					bl = list2[i].matches(atc);
				}else if(list2[i].equals("@")){
					bl = list[i].matches(atc);
				}else{
					bl = false;
				}
			}else{
				break;
			}
		};
		
		if(bl == true){
			c = "You can win";
		}else{
			c = "You will lose";
		}
		
		System.out.println(c);
		System.out.flush();
		sc.close();
	}
}