import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int[][] b = new int[2][3];
        int[][] c = new int[3][2];
        
        int sum = 0;
        
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                int tmp = sc.nextInt();
                b[i][j] = tmp;
                sum += tmp;
            }
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++){
                int tmp = sc.nextInt();
                c[i][j] = tmp;
                sum += tmp;
            }
        }
        
        int[][] grd = new int[3][3];
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                grd[i][j] = -1;
            }
        }
        
        int chokuScore = dfs(grd, b, c, 0);
        System.out.println(chokuScore + "\n" + (sum - chokuScore));
        
    }
    
    public static int dfs(int[][] grd, int[][] b, int[][] c, int k){
        if(k==9) return calcScore(grd, b, c);
        
        int teban = k%2;
        
        int score;
        if(teban == 0){
            //???????
            score = 0;
        }else{
            //???????
            score = 1_000_000;
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grd[i][j] == -1){
                    grd[i][j] = teban;
                    int result = dfs(grd, b, c, k+1);
                    if(teban == 0){
                        //???????
                        if(score < result) score = result;
                    }else{
                        //???????
                        if(score > result) score = result;
                    }
                    grd[i][j] = -1;
                }
            }
        }
        
        return score;
    }
    
    public static int calcScore(int[][] grd, int[][] b, int[][] c){
        int score = 0;
        
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                if(grd[i][j] == grd[i+1][j]){
                    score += b[i][j];
                }
            }
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++){
                if(grd[i][j] == grd[i][j+1]){
                    score += c[i][j];
                }
            }
        }
        
        return score;
    }
}