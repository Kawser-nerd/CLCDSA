import java.util.*;

public class Main {
    private static int D[] = new int[7];
    private static int J[] = new int[7];

    public static void input(){
        Scanner scan = new Scanner(System.in);

        for (int i=0;i<7;i++){
            D[i] = scan.nextInt();
        }
        for (int i=0;i<7;i++){
            J[i] = scan.nextInt();
        }
    }

    public static void main(String args[]) {
        //??
        input();

        int ans = 0;
        for (int i=0;i<7;i++){
            if (D[i] >= J[i]) ans += D[i];
            else ans += J[i];
        }
        System.out.println(ans);
    }
}