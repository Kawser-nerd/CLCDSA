import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		List<String>word=new ArrayList<>();
		int n=sc.nextInt();
		sc.nextLine();
		word.add(sc.nextLine());
		for(int i=1;i<n;i++) {
			String bef=word.get(i-1);
			String now=sc.nextLine();
			if(bef.charAt(bef.length()-1)!=now.charAt(0)||word.contains(now)) {
				System.out.println("No");
				return;
			}
			word.add(now);
		}
		System.out.println("Yes");
	}
}