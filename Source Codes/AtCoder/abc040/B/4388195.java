import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int ans=n;
      for(int i=1;i*i<=n;i++){
      	ans=Math.min(ans,Math.abs(n/i-i)+n%i);
      }
      System.out.println(ans);
    }
}