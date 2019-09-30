import java.awt.*;
import java.util.*;

public class Main {
    private static int R;
    private static int C;
    private static int D;
    private static int table[][];
    private static boolean flag = true;
    private static ArrayList<Integer> even = new ArrayList<>();
    private static ArrayList<Integer> odd = new ArrayList<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);

        R = scan.nextInt();
        C = scan.nextInt();
        D = scan.nextInt();
        table = new int[R][C];

        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                table[i][j] = scan.nextInt();
            }
        }
    }

    public static void main(String args[]) {
        //??
        input();

        int max = 0;
        for(int i = 0 ;i < R;i++){
            for(int j = 0;j < C;j++){
                if((i + j) <= D && (i+j) % 2 == D % 2){
                    max = Math.max(max,table[i][j]);
                }
            }
        }

        System.out.println(max);
    }
}