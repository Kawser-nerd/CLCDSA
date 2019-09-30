import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String n=sc.nextLine();
      String po[]=n.split("",0);
      int m=sc.nextInt()-1;
      System.out.println(po[m/5]+po[m%5]);
	}
}