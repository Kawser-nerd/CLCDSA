import java.util.*;
public class Main{
  public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int ans=101;
    for(int i=0;i<n;i++){
    ans=Math.min(sc.nextInt(),ans);
    }System.out.println(ans);
  }
}