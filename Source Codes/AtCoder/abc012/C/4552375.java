import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int ans=2025;
        ans-=sc.nextInt();
      for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(i*j==ans)System.out.println(i+" x "+j);
    }
}