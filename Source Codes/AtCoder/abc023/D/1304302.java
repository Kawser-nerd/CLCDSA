import java.util.*;

public class Main{
        public static void main(String[] args){
                try(Scanner sc = new Scanner(System.in)){
                        int N = sc.nextInt();
                        long[] H = new long[N];
                        long[] S = new long[N];
                        long ansmin = 0, ansmax = Long.MAX_VALUE >> 2;
                        for(int i = 0; i < N; i++){
                                H[i] = sc.nextLong();
                                S[i] = sc.nextLong();
                                ansmin = Math.max(ansmin, H[i]);
                        }
                        long[] time = new long[N];
                        for(int idx = 0; idx < 100; idx++){
                                long ansmid = (ansmax + ansmin) / 2;
                                boolean f = true;
                                for(int i = 0; i < N; i++){
                                        time[i] = (ansmid - H[i]-1) / S[i];
                                }
                                Arrays.sort(time);

                                for(int i = 0; f && i < N; i++){
                                        if(time[i] < (long)i){
                                                f = false;
                                        }
                                }

                                if(f){
                                        ansmax = ansmid;
                                } else {
                                        ansmin = ansmid;
                                }
                        }
                        System.out.println(ansmin);
                }
        }
}