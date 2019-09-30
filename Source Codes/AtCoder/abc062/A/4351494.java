import java.util.*;


public class Main {
    public static void main(String[] args) {
      int []po=new int[]{0,2,0,1,0,1,0,0,1,0,1,0};
        Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();int m=sc.nextInt();
      if(po[n-1]==po[m-1])
      System.out.println("Yes");else System.out.println("No");
    }
}