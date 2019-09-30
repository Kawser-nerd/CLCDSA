import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int h=sc.nextInt(),w=sc.nextInt();
		int froml,fromu=0;
		List<String>s=new ArrayList<>();
		for(int i=0;i<h;i++) {
			froml=0;
			for(int j=0;j<w;j++) {
				int a=sc.nextInt();
				a+=froml;
				if(j==w-1) {
					a+=fromu;
					fromu=a%2;
					if(fromu==1&&i+2<=h) {
						s.add((i+1)+" "+(j+1)+" "+(i+2)+" "+(j+1));
					}
					break;
				}
				froml=a%2;
				if(froml==1) {
					s.add((i+1)+" "+(j+1)+" "+(i+1)+" "+(j+2));
				}
			}
		}
		System.out.println(s.size());
		for(int i=0;i<s.size();i++) {
			System.out.println(s.get(i));
		}
	}
}