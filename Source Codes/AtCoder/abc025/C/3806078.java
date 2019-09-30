import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int[][] b = new int[2][3];
    static int [][] c = new int[3][2];
    static int[][] ban = new int[3][3];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<2; ++i) {
            for(int j=0; j<3; ++j) {
                b[i][j] = sc.nextInt();
            }
        }
        for(int i=0; i<3; ++i) {
            for(int j=0; j<2; ++j) {
                c[i][j] = sc.nextInt();
            }
        }
        int[] res = saiki(0);
        System.out.println(res[0]);
        System.out.println(res[1]);
    }
    
    static int[] saiki(int turn) {
        if(turn == 9) {
            int tak = 0;
            int imo = 0;
            for(int i=0; i<2; ++i) {
                for(int j=0; j<3; ++j) {
                    if(ban[i][j] == ban[i+1][j]) tak += b[i][j];
                    else imo += b[i][j];
                }
            }
            for(int i=0; i<3; ++i) {
                for(int j=0; j<2; ++j) {
                    if(ban[i][j] == ban[i][j+1]) tak += c[i][j];
                    else imo += c[i][j];
                }
            }
            return new int[] {tak, imo};
        }
        
        boolean dai = turn % 2 == 0;
        List<int[]> scores = new ArrayList<>();
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if(ban[i][j] != 0) continue;
                if(dai) ban[i][j] = 1;
                else ban[i][j] = -1;
                scores.add(saiki(turn+1));
                ban[i][j] = 0;
            }
        }
        if(dai) {
            return scores.stream().max(Comparator.comparing(x -> x[0])).get();
        }
        else {
            return scores.stream().max(Comparator.comparing(x -> x[1])).get();
        }
    }
}