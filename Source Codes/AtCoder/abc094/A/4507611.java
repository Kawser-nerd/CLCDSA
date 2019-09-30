import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       int n=sc.nextInt();
       int m=sc.nextInt();
       int l=sc.nextInt();
       if(n<=l&&n+m>=l)System.out.println("YES");
       else System.out.println("NO");
    }
    }