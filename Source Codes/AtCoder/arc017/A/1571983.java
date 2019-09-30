import java.util.*;

public class Main {
    private static int n;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();

        boolean flag = true;
        for (int i=2;i<=n/2;i++){
            if(n % i == 0) {
                System.out.println("NO");
                flag = false;
                break;
            }
        }
        if (flag) System.out.println("YES");
    }
}