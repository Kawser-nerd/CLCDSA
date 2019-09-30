import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        //System.out.println("n = " + n);
        int ans = 1;
        for(int i = 1; i * i <= n; i++) {
            ans = i * i;
        }
        System.out.println(ans);
    }
}