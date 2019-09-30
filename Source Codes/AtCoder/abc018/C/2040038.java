import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int r = sc.nextInt();
        int c = sc.nextInt();
        int k = sc.nextInt();
        
        String[] ss = new String[r];
        for(int i=0; i<r; i++){
            ss[i] = sc.next();
        }
        
        int len = 0;
        ArrayList<Integer> liy = new ArrayList<>();
        ArrayList<Integer> lix = new ArrayList<>();
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(ss[i].charAt(j)=='x'){
                    liy.add(i);
                    lix.add(j);
                    len++;
                }
            }
        }
        
        int[][] grd = new int[r][c];
        for(int idx=0; idx<len; idx++){
            int y = liy.get(idx);
            int x = lix.get(idx);
            for(int i=y-k+1; i<=y+k-1; i++){
                if(i<0 || i>=r) continue;
                for(int j=x-k+1; j<=x+k-1; j++){
                    if(j<0 || j>=c) continue;
                    if(Math.abs(i-y)+Math.abs(j-x) >= k) continue;
                    //System.out.println(Math.abs(i-y)+Math.abs(j-x));
                    grd[i][j] = 1;
                }
            }
        }
        
        int ans = 0;
        for(int i=k-1; i<r-k+1; i++){
            for(int j=k-1; j<c-k+1; j++){
                if(grd[i][j] == 0){
                    ans++;
                }
            }
        }
        
        System.out.println(ans);
    }
}