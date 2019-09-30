import java.io.PrintWriter;
import java.util.*;

import static java.lang.Math.max;

/**
 * Created by shoya on 2017/04/30.
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int N = sc.nextInt();
        long W = sc.nextLong();
        HashMap<Long, ArrayList<Long>> hash = new HashMap<Long, ArrayList<Long>>();

        long min_w = -1;
        for (int i = 0; i < N; i++){
            long w = sc.nextInt();
            if (min_w == -1){
                min_w = w;
            }
            if (hash.get(w) == null) {
                hash.put(w, new ArrayList<Long>());
            }
            hash.get(w).add(sc.nextLong());
        }

        for (long i = min_w; i <= min_w + 3; i++){
            if (hash.get(i) != null) {
                Collections.sort(hash.get(i));
                Collections.reverse(hash.get(i));
                //System.out.println(hash.get(i));
            }
        }

        long ans = 0;
        for (int i = 0; i <= N; i++){
            if ( i * min_w > W){
                continue;
            }

            for (int j = 0; j <= N; j++) {
                if (i + j > N){
                    continue;
                }
                if ( i * min_w + j * (min_w + 1) > W){
                    continue;
                }

                for (int k = 0; k <= N; k++) {
                    if (i + j + k > N){
                        continue;
                    }
                    if ( i * min_w + j * (min_w + 1) + k * (min_w + 2) > W){
                        continue;
                    }

                    for (int l = 0; l <= N; l++) {
                        if (i + j + k + l > N){
                            continue;
                        }
                        if ( i * min_w + j * (min_w + 1) + k * (min_w + 2) + l * (min_w + 3) > W){
                            continue;
                        }

                        long sum = 0;
                        if (hash.get(min_w) != null) {
                            //sum += hash.get(min_w).stream().limit(i).mapToLong(x -> x.longValue()).sum();
                            for (int tmp = 0; tmp < i && tmp < hash.get(min_w).size(); tmp++){
                                sum += hash.get(min_w).get(tmp);
                            }
                        }
                        if (hash.get(min_w + 1) != null) {
                            //sum += hash.get(min_w + 1).stream().limit(j).mapToLong(x -> x.longValue()).sum();
                            for (int tmp = 0; tmp < j && tmp < hash.get(min_w + 1).size(); tmp++){
                                sum += hash.get(min_w + 1).get(tmp);
                            }
                        }
                        if (hash.get(min_w + 2) != null) {
                            //sum += hash.get(min_w + 2).stream().limit(k).mapToLong(x -> x.longValue()).sum();
                            for (int tmp = 0; tmp < k && tmp < hash.get(min_w + 2).size(); tmp++){
                                sum += hash.get(min_w + 2).get(tmp);
                            }
                        }
                        if (hash.get(min_w + 3) != null) {
                            //sum += hash.get(min_w + 3).stream().limit(l).mapToLong(x -> x.longValue()).sum();
                            for (int tmp = 0; tmp < l && tmp < hash.get(min_w + 3).size(); tmp++){
                                sum += hash.get(min_w + 3).get(tmp);
                            }
                        }
                        ans = max(ans, sum);
                    }
                }
            }
        }


        pw.println(ans);
        pw.flush();
        return;
    }
}