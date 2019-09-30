import java.util.Scanner;

 
public class Main {
    void solve(Scanner sc) throws Throwable {
        int N = sc.nextInt();
        int[][] mans = new int[N][3];
        for (int i = 0; i < mans.length; i++) {
            mans[i][0] = sc.nextInt();
            mans[i][1] = sc.nextInt();
            mans[i][2] = sc.nextInt();
        }
        
        double ans = calcMax(mans, true);
        System.out.println(Math.max(ans, calcMax(mans, false)));
    }

    private double calcMax(int[][] mans, boolean isSearchWidth) {
        double maxTimeLeft = 0 ;
        double maxTimeRight = 0 ;
        double l = 1e5;
        double r = -1e5;
        
        int x = isSearchWidth ? 0 : 1;
        for(int i = 0 ; i < 100; i++) {
            double targetL = (l * 2 + r) / 3;
            double targetR = (l + r * 2) / 3;
            
            maxTimeLeft = 0;
            maxTimeRight = 0;
            for(int j = 0 ; j < mans.length; j++) {
                maxTimeLeft = Math.max(maxTimeLeft, (Math.abs(targetL - mans[j][x]) * mans[j][2]));
                maxTimeRight = Math.max(maxTimeRight, (Math.abs(targetR - mans[j][x]) * mans[j][2]));
            }
            
            if(maxTimeLeft > maxTimeRight) {
                l = targetL;
            } else {
                r = targetR;
            }

        }
        
        return Math.max(maxTimeLeft, maxTimeRight);
    }
    
    public static void main(String[] args) throws Throwable {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().solve(sc);
        }
    }

}