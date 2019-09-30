import java.util.*;

public class Main {
    private static int a[][] = new int[4][4];

    public static void input(){
        Scanner scan = new Scanner(System.in);

        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                a[i][j] = scan.nextInt();
            }
        }
    }

    public static void main(String args[]) {
        //??
        input();

        boolean flag = false;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                if (j != 3 && a[i][j] == a[i][j+1]){
                    flag = true;
                    break;
                }
                if (j != 3 && a[j][i] == a[j+1][i]){
                    flag = true;
                    break;
                }
            }
        }

        if (flag) System.out.println("CONTINUE");
        else System.out.println("GAMEOVER");
    }
}