import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] r = new int[n][2];
        int[][] b = new int[n][2];
        boolean[] buse = new boolean[n];
        for(int i=0; i<n; i++){
            r[i][0] = sc.nextInt();
            r[i][1] = sc.nextInt();            
        }
        for(int i=0; i<n; i++){
            b[i][0] = sc.nextInt();
            b[i][1] = sc.nextInt();       
            buse[i] = false;
        }
        sc.close();

        int ans = 0;

        MyComp comp = new MyComp();
        Arrays.sort(r, comp);

        for(int i=0; i<n; i++){
            int rx = r[n-i-1][0];
            int ry = r[n-i-1][1];
            int bymin = 1000;
            int byminpos = 0;
            for(int j=0; j<n; j++){
                if(b[j][0] > rx && b[j][1] > ry && b[j][1] < bymin && !buse[j]){
                    bymin = b[j][1];
                    byminpos = j;
                }
            }
            if(bymin != 1000){
                ans++;
                buse[byminpos] = true;
            }
        }

        System.out.println(ans);
    }
}

class MyComp implements Comparator{
    @Override
    public int compare(Object i1, Object i2){
        return ((int[])i1)[0] - ((int[])i2)[0];
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.