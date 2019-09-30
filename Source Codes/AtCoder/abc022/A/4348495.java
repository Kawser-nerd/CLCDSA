import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
      int a=sc.nextInt();
      int b=sc.nextInt();
      int ans=0;
      int aa=0;
      for(int i=0;i<n;i++){
         ans+=sc.nextInt();
        if(ans<=b&&ans>=a)aa++;
      }
      System.out.println(aa);
	}
}