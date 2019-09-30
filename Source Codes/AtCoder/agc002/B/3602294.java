import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int boxes = sc.nextInt();
        int operations = sc.nextInt();
        boolean[] redPossible = new boolean[boxes+1];
        redPossible[1]= true;
        int[] boxBalls = new int[boxes+1];
        int possibility = 0;
        for(int i = 1; i < boxBalls.length; i++){
                boxBalls[i] = 1;
            }
        for(int i = 0; i < operations; i++){
            int pick = sc.nextInt();
            int put = sc.nextInt();
            if(redPossible[pick]==true){
                    redPossible[put]=true;
            }
            boxBalls[pick] = boxBalls[pick]-1;
            boxBalls[put] = boxBalls[put]+1;
            if(boxBalls[pick]==0){
                    redPossible[pick]=false;
            }
            }
            for(int i = 0; i < redPossible.length; i++){
                if(redPossible[i]!=false){
                    possibility++;
                }
            }

            System.out.println(possibility);
    }
}