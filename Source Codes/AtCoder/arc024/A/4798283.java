import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		List<Integer>l=new ArrayList<>();
		int L=sc.nextInt();
		int R=sc.nextInt();
		int ans=0;
		for(int i=0;i<L;i++) {
			l.add(sc.nextInt());
		}
		for(int i=0;i<R;i++) {
			Integer r=sc.nextInt();
			if(l.remove(r))
				ans++;
		}
		System.out.println(ans);
	}
}