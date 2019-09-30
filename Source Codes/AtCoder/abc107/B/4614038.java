import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String a[][] = new String[h][w];
        for(int i=0; i<h; i++){
            String s = sc.next();
            String b[] = s.split("");
            for(int j=0; j<w; j++){
                a[i][j] = b[j];
            }
        }
        boolean row[] = new boolean[h];
        boolean col[] = new boolean[w];
        for(int i=0; i<h; i++){
            int cnt = 0;
            for(int j=0; j<w; j++){
                if(a[i][j].equals(".")) cnt++;
            }
            if(cnt == w) row[i] = true;
        }
        for(int i=0; i<w; i++){
            int cnt = 0;
            for(int j=0; j<h; j++){
                if(a[j][i].equals(".")) cnt++;
            }
            if(cnt == h) col[i] = true;
        }
        for(int i=0; i<h; i++){
            if(row[i]) continue;
            for(int j=0; j<w; j++){
                if(col[j]) continue;
                System.out.print(a[i][j]);
            }
            System.out.println();
        }
    }
}