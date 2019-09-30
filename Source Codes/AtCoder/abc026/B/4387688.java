import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int ans[]=new int[n];
      for(int i=0;i<n;i++)ans[i]=sc.nextInt();
      Arrays.sort(ans);
      double aa=0;
      for(int i=0;i<n;i++){
          if(i%2==0)aa+=Math.pow(ans[n-1-i],2);
          else aa-=Math.pow(ans[n-1-i],2);
      }
      System.out.println(aa*Math.PI);
    }
}