import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
      
      if(n%2==0){
        int a=n/2;
      	System.out.println(a);
        for(int i=0;i<a;i++)System.out.println(2);
      }
      else{
          int a=n/2;
      	System.out.println(a+1);
        System.out.println(1);
        for(int i=0;i<a;i++)System.out.println(2);
      }
	}
}