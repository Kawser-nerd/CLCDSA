import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
      int m=0;
        for(int i=1;i<=n;i++) {
         m+=i*10000;
      }
        System.out.println(m/n);
    }
}