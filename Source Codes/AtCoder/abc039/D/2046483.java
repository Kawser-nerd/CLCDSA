import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int h = sc.nextInt();
        int w = sc.nextInt();
        
        int[][] imgTrd = new int[h][w];
        
        for(int i=0; i<h; i++){
            String line = sc.next();
            for(int j=0; j<w; j++){
                imgTrd[i][j] = (line.charAt(j)=='.')? 0 : 1;
            }
        }
        
        int[][] imgOrg = new int[h][w];
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                boolean isIgeta = true;
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        if(i+k>=0 && i+k<h && j+l>=0 && j+l<w 
                           && imgTrd[i+k][j+l]==0){
                            isIgeta = false;
                        }
                    }
                }
                if(isIgeta){
                    imgOrg[i][j] = 1;
                }
            }
        }
        
        int[][] imgRpd = new int[h][w];
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(imgOrg[i][j]==1){
                   for(int k=-1; k<=1; k++){
                        for(int l=-1; l<=1; l++){
                            if(i+k>=0 && i+k<h && j+l>=0 && j+l<w){
                                imgRpd[i+k][j+l] = 1;
                            }
                        }
                    }
                    
                }
            }
        }
        
        boolean isPossible = true;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(imgTrd[i][j] != imgRpd[i][j]){
                    isPossible = false;
                }
            }
        }
        
        if(isPossible){
            System.out.println("possible");
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    System.out.print((imgOrg[i][j]==0)? '.' : '#');
                }
                System.out.println("");
            }
        }else{
            System.out.println("impossible");
        }
    }
}