import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int w = scan.nextInt();
        int a = scan.nextInt();
        int b = scan.nextInt();
        int ans = 0;
        if(b + w < a){
            ans = a - (b + w);
        }else if(a + w < b){
            ans = b - (a + w);
        }
        System.out.println(ans);
    }
}