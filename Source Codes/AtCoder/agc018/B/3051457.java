import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList[] a = new ArrayList[n];
        for(int i=0; i<n; i++){
            a[i] = new ArrayList<Integer>();
            for(int j=0; j<m; j++){
                a[i].add(sc.nextInt() - 1);                
            }
        }

        int min = n;

        for(int i=0; i<m; i++){
            int[] mnum = new int[m];
            for(int j=0; j<n; j++){
                mnum[(int)(a[j].get(0))]++;
            }
            int max = 0, maxpos = 0;
            for(int j=0; j<m; j++){
                if(mnum[j] > max){
                    max = mnum[j];
                    maxpos = j;
                }
            }
            if(max < min) min = max;
            for(int j=0; j<n; j++){
                a[j].removeAll(Arrays.asList(new Integer[]{maxpos}));
            }
        }
        System.out.println(min);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.