import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int a=0;
      for(int i=0;i<3;i++)
        a+=sc.nextInt()/10*sc.nextInt();
      System.out.println(a);
	}
}