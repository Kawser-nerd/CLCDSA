import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int l=sc.nextInt()+sc.nextInt();
		int r=sc.nextInt()+sc.nextInt();
		System.out.println(l>r?"Left":l<r?"Right":"Balanced");
	}
}