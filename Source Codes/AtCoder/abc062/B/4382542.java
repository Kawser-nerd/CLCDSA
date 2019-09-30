import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        
        int H = sc.nextInt();
        int W = sc.nextInt();
        String[] S = new String[H];
        for(int i = 0; i < H; i++) S[i] = sc.next();

        for(int i = 0; i < W + 2; i++){
            System.out.print("#");
        }
        System.out.println("");
        for(int i = 0; i < H; i++){
            System.out.println("#" + S[i] + "#");
        }
        for(int i = 0; i < W + 2; i++){
            System.out.print("#");
        }
    }
}