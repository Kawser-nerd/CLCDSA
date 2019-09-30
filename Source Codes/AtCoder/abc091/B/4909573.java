import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		List<String>call=new ArrayList<>();
		List<String>blue=new ArrayList<>();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			String s=sc.next();
			if(!blue.contains(s))
				call.add(s);
			blue.add(s);
		}
		int m=sc.nextInt();
		for(int i=0;i<m;i++) {
			blue.remove(sc.next());
		}
		int max=0;
		for(int i=0;i<call.size();i++) {
			int cnt=0;
			for(int j=0;j<blue.size();j++) {
				if(blue.get(j).equals(call.get(i)))
					cnt++;
			}
			max=Math.max(max, cnt);
		}
		System.out.println(max);
	}
}