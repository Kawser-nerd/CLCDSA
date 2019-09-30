import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[]po=new int[5];
      for(int i=0;i<5;i++)po[i]=sc.nextInt();
      int ans[]=new int[]{po[0]+po[1]+po[2],po[0]+po[1]+po[3],po[0]+po[1]+po[4],po[0]+po[2]+po[3],po[0]+po[2]+po[4],po[0]+po[3]+po[4],po[1]+po[2]+po[3],po[1]+po[2]+po[4],po[1]+po[3]+po[4],po[2]+po[3]+po[4]};
    Arrays.sort(ans);
      System.out.println(ans[7]);
    }
}