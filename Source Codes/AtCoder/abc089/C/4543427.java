import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] cnt = new long[5];
        for(int i = 0; i<N; i++) {
            char c = sc.next().charAt(0);
            if(c=='M') cnt[0]++;
            if(c=='A') cnt[1]++;
            if(c=='R') cnt[2]++;
            if(c=='C') cnt[3]++;
            if(c=='H') cnt[4]++;
        }

        long sum = 0;
        for(int i = 0; i<3; i++) {
            for(int j = i+1; j<4; j++) {
                for(int k = j+1; k<5; k++) {
                    sum +=  cnt[i]*cnt[j]*cnt[k];
                }
            }
        }
        System.out.println(sum);
    }
}