import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
      int[]po=new int[]{1,4,8,16,32,64,128,256,512,9,27,81,243,729,25,125,100,625,36,216,49,343,1000,121,144,169,196,225,289,324,361,400,441,484,529,576,676,784,841,900,961,1001};
		Arrays.sort(po);
      int n=sc.nextInt();
      int i=0;
      for(i=0;po[i]<=n;i++){}
      System.out.println(po[i-1]);
    }
}