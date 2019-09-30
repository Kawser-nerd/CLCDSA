import java.util.Scanner;

public class Main {
static int ans,N;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       int n=sc.nextInt();
       if(n%2==0)System.out.println(n/2*n/2);
       else System.out.println(n/2*(n-n/2));
        }
    }