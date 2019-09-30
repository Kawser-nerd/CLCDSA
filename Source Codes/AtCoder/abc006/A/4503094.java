import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
      if(n%3==0)        System.out.println("YES");
      if(n%3!=0)        System.out.println("NO");
    }
}