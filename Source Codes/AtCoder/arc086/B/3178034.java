import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        int max = 0;
        int maxpos = 0;
        for (int i = 0; i < n; i++) {
            if (Math.abs(a[i]) > max) {
                max = Math.abs(a[i]);
                maxpos = i;
            }
        }

        int moveNum = 0;
        ArrayList<Integer[]> move = new ArrayList<Integer[]>();

        if (max == 0) {
            System.out.println(0);
            return;
        } else if (a[maxpos] > 0) {
            for (int i = 0; i < n; i++) {
                if(i ==  maxpos) continue;
                a[i] += max;
                moveNum++;
                move.add(new Integer[] { maxpos + 1, i + 1 });
            }
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i - 1]) {
                    int dif = a[i - 1] - a[i];
                    int min = Integer.MAX_VALUE;
                    int minpos = 0;
                    for (int j = 0; j < n; j++) {
                        if (a[j] < min && a[j] >= dif) {
                            min = a[j];
                            minpos = j;
                        }
                    }
                    a[i] += min;
                    moveNum++;
                    move.add(new Integer[] { minpos + 1, i + 1 });
                }
            }
        }else{
            for(int i=0; i<n; i++){
                if(i == maxpos) continue;
                a[i] -= max;
                moveNum++;
                move.add(new Integer[]{maxpos+1, i+1});
            }
            for(int i=n-2; i>=0; i--){
                if(a[i] > a[i+1]){
                    int dif = a[i+1] - a[i];
                    int mmax = Integer.MIN_VALUE;
                    int mmaxpos = 0;
                    for(int j=0; j<n; j++){
                        if(a[j] > mmax && a[j] <= dif){
                            mmax = a[j];
                            mmaxpos = j;
                        }
                    }
                    a[i] += a[mmaxpos];
                    moveNum++;
                    move.add(new Integer[]{mmaxpos+1, i+1});
                }
            }
        }

        System.out.println(moveNum);
        for(int i=0; i<moveNum; i++){
            Integer[] mans = move.get(i);
            System.out.println(mans[0] + " " + mans[1]);
        }

        // int moveNum = 0;
        // ArrayList<Integer[]> move = new ArrayList<Integer[]>();
        // for(int i=1; i<n; i++){
        // if(a[i] < a[i-1]){
        // int dif = a[i-1] - a[i];
        // int min = Integer.MAX_VALUE;
        // int minpos = 0;
        // for(int j=0; j<n; j++){
        // if(a[j] < min && a[j] >= dif){
        // min = a[j];
        // minpos = j;
        // }
        // }
        // a[i] += min;
        // moveNum++;
        // move.add(new Integer[]{minpos+1, i+1});
        // }
        // }

    }
}