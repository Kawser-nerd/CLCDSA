import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        String banmen[][] = new String[4][4];

        for(int i = 0; i < 4;i++){
            for (int j = 0; j < 4; j++){
                banmen[i][j] = sc.next();
            }
        }

        for(int i = 0; i < 4;i++){
            for (int j = 0; j < 4; j++){
                System.out.print((j==0)?banmen[3-i][3-j]:" " + banmen[3-i][3-j]);
            }
            System.out.println();
        }
    }
}