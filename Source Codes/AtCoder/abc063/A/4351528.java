import java.util.*;


public class Main {
    public static void main(String[] args) {
      int []po=new int[]{0,2,0,1,0,1,0,0,1,0,1,0};
        Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int m=sc.nextInt();
      System.out.println((n+m<10)?n+m:"error");
    }
}