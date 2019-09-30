import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int x = scan.nextInt();
        int y = scan.nextInt();
        int sum = 0;

        for(int a = 0; a <= 9; a++){
            for(int b = 0; b <= 9; b++){
                for(int c = 0; c <= 9; c++){
                    for(int d = 0; d <= 9; d++){
                        for(int e = 0; e <= 9; e++){
                            if ((n >= 10000*a + 1000*b + 100*c + 10*d + e) && (x <= a+b+c+d+e) && (y >= a+b+c+d+e) ){
                                sum = sum + (10000*a + 1000*b + 100*c + 10*d + e);
                            }
                        }
                    }
                }
            }
        }
        System.out.println(sum);
    }
}