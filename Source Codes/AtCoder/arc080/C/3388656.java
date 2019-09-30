import java.util.*;
import java.io.*;

import static java.lang.System.in;
class Main {
    static int[] idx;
    static int[] A;
    static ST even;
    static ST odd;
    static ST all;
    public static void main(String[] args) throws IOException{
        //Scanner sc = new Scanner(System.in);
        //int n = sc.nextInt();
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        String temp;
        String[] buf;
        temp = reader.readLine();
        int n = Integer.parseInt(temp);
        temp = reader.readLine();
        buf = temp.split(" ");

        A = new int[n];
        idx = new int[n+1];
        for(int i=0;i<n;i++){
            A[i] = Integer.parseInt(buf[i]);
            idx[A[i]] = i;
        }
        even = new ST(n/2);
        odd = new ST(n/2);

        for(int i=0;i<n;i+=2) even.update(i/2,A[i]);
        for(int i=1;i<n;i+=2) odd.update(i/2,A[i]);
        myComparator mc = new myComparator();
        PriorityQueue<int[]> pq = new PriorityQueue<>(10,mc);
        pq.add(new int[]{0,n});
        //ArrayList<Integer> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for(int i=1;i<n;i+=2){
            int[] cur = pq.poll();
            int left = cur[0];
            int right = cur[1];
            int now,next;
            if(left%2==0){
                now = even.find(left/2,right/2);
                next = odd.find((idx[now]+1)/2,(right+1)/2);
            }else{
                now = odd.find(left/2,right/2);
                next = even.find((idx[now]+1)/2,(right+1)/2);
            }
            //res.add(now);
            //res.add(next);
            sb.append(now);
            sb.append(" ");
            sb.append(next);
            sb.append(" ");
            if(left<idx[now]) pq.add(new int[]{left,idx[now]});
            if(idx[now]<idx[next]-1) pq.add(new int[]{idx[now]+1,idx[next]});
            if(idx[next]<right-1) pq.add(new int[]{idx[next]+1,right});
        }
        /*for(int i=0;i<res.size();i++){
            System.out.print(Integer.toString(res.get(i))+" ");
        }*/
        System.out.println(sb.toString());
    }

    static class ST{
        int n=1;
        int[] dat;
        public ST(int n_){
            while(n<n_) n*=2;
            dat = new int[2*n-1];
            for(int i=0;i<2*n-1;i++) dat[i] = Integer.MAX_VALUE/2;
        }
        public void update(int idx, int val){
            idx += n-1;
            dat[idx] = val;
            while(idx>0){
                idx = (idx-1)/2;
                dat[idx] = Math.min(dat[idx*2+1],dat[idx*2+2]);
            }
        }
        public int find(int a, int b){
            return query(a,b,0,0,n);
        }
        private int query(int a, int b, int k, int left, int right){
            if(b<=left||right<=a) return Integer.MAX_VALUE;
            if(a<=left&&right<=b) return dat[k];
            int v1 = query(a,b,2*k+1,left,(left+right)/2);
            int v2 = query(a,b,2*k+2,(left+right)/2,right);
            return Math.min(v1,v2);
        }
    }
    static class myComparator implements Comparator<int[]>{
        public int compare(int[] o1, int[] o2){
            int[][] dic = new int[][]{o1,o2};
            int[] res = new int[2];
            for(int i=0;i<2;i++){
                int[] cur = dic[i];
                int left = cur[0];
                int right = cur[1];
                int p = left%2==0?even.find(left/2,right/2):odd.find(left/2,right/2);
                res[i]=p;
            }
            return res[0]-res[1];
        }
    }
}