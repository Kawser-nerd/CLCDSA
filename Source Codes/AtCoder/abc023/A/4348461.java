import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String po=sc.nextLine();
      String []p=po.split("",0);
      int ans=0;
      for(int i=0;i<p.length;i++)ans+=Integer.parseInt(p[i]);
      System.out.println(ans);
	}
}