import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int ar[]=new int[3];
		ar[0]=sc.nextInt();
		ar[1]=sc.nextInt();
		ar[2]=sc.nextInt();
		Arrays.sort(ar);
		if(ar[0]==5&&ar[1]==5&&ar[2]==7)
		System.out.println("YES");
		else
		System.out.println("NO");
	}
}