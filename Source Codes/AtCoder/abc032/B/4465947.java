import java.util.ArrayList;
import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		int k=sc.nextInt();
		ArrayList<String> p=new ArrayList<>();
		for(int i=0;i<s.length()-k+1;i++) {
			if(!p.contains(s.substring(i, i+k))) {
				p.add(s.substring(i, i+k));
			}
		}
		System.out.println(p.size());
		}
}