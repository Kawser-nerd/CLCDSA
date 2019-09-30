import java.util.*;
public class Main{
  public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int m=sc.nextInt();
    if(m>n*4||m<n*2){
      System.out.println("-1 -1 -1");
      return;
    }
    int a=n;
    int o=0;
    int c=0;
    o+=Math.min(n,m-n*2);
    a-=o;
    c+=(m-a*2-o*3);
    o-=c;
    System.out.println(a+" "+o+" "+c);
    

	}
}