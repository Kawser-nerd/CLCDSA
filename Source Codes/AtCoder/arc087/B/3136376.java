import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int x = sc.nextInt();
        int y = sc.nextInt();
        sc.close();

        ArrayList h = new ArrayList<Integer>();
        ArrayList w = new ArrayList<Integer>();

        char pc = 'F';
        int cont = 0;
        boolean dir = true;        // t:x, f:y
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == 'F'){
                if(pc == 'F'){
                    cont++;
                }else{
                    if(cont%2 != 0) dir = !dir;
                    cont = 1;
                    pc = 'F';
                }
            }else{
                if(pc == 'F'){
                    if(dir){
                        w.add(cont);
                    }else{
                        h.add(cont);
                    }
                    cont = 1;
                    pc = 'T';
                }else{
                    cont++;
                }
            }
        }
        if(pc == 'F'){
            if(dir){
                w.add(cont);
            }else{
                h.add(cont);
            }
        }
        if(s.charAt(0) == 'F'){
            x -= (int)w.remove(0);
        }
        if(canReach(Math.abs(x), w) && canReach(Math.abs(y), h)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }

    public static boolean canReach(int len, ArrayList<Integer> move){
        int sum = 0;
        for (int oneMove : move) {
            sum += oneMove;
        }
        if(((sum-len) % 2 != 0) || sum < len) return false;
        int target = (sum - len) / 2;
        boolean[][] dp = new boolean[move.size()+1][target+1];
        for(int i=0; i<move.size()+1; i++){
            for(int j=0; j<target+1; j++){
                dp[i][j] = j == 0 ? true : false;
            }
        }
        for(int i=0; i<move.size(); i++){
            for(int j=0; j<target+1; j++){
                if(j >= move.get(i)){
                    if(dp[i][j] || dp[i][j-move.get(i)]) dp[i+1][j] = true;
                }else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        return dp[move.size()][target];
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.