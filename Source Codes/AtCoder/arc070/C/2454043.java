import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long lbase = 0;
        long rbase = 0;
        PriorityQueue<Long> lindex = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Long> rindex = new PriorityQueue<>();
        long[] l = new long[N];
        long[] w = new long[N];
        for(int i=0;i<N;++i){
            l[i] = scan.nextLong();
            w[i] = scan.nextLong()-l[i];
        }
        lindex.add(l[0]);rindex.add(l[0]);
        long ans = 0;
        for(int i=1;i<N;++i){
            lbase += w[i];
            rbase += w[i-1];
            if(lindex.peek() >= (l[i]+lbase)){
                lindex.add(l[i]+lbase);
                lindex.add(l[i]+lbase);
                ans += Math.abs(lindex.peek()-(l[i]+lbase));
                rindex.add(lindex.poll()-lbase-rbase);
            }else if(rindex.peek() <= (l[i]-rbase)){
                rindex.add(l[i]-rbase);
                rindex.add(l[i]-rbase);
                ans += Math.abs(rindex.peek()-(l[i]-rbase));
                lindex.add(rindex.poll()+lbase+rbase);
            }else{
                lindex.add(l[i]+lbase);
                rindex.add(l[i]-rbase);
            }
        }
        System.out.println(ans);
    }
}