import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int N = sc.nextInt();
        int sum = N;
        int a = 0;
        int num = N;
        while(a >= m || num != 0 ){
            a += num;
            num = 0;
            if(a >= m){
                num += a / m * n;
                sum += num;
                a = a % m;
            }
        }
        System.out.println(sum);
    }
}