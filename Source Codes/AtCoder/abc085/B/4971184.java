import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		List<Integer>l=new ArrayList<>();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int d=sc.nextInt();
			if(!l.contains(d))l.add(d);
		}
		System.out.println(l.size());
	}
}