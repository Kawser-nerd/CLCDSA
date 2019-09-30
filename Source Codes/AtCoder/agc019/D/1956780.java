import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import javax.management.MXBean;

class Pair{
    int first,second;
    public Pair(int a,int b){
        first=a;
        second=b;
    }
}

class Main{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String A = scan.next();
        String B = scan.next();
        Pair[] range = new Pair[A.length()];
        int N = A.length();

        for(int i=0;i<N;++i){
            if(B.charAt(i)=='1')break;
            if(i==N-1){
                for(int j=0;j<N;++j){
                    if(A.charAt(j)=='1'){
                        System.out.println(-1);
                        return;
                    }
                }
                System.out.println(0);
                return;
            }
        }

        for(int i=0;i<N;++i){
            int left=N;
            for(int j=(i+1)%N;j!=i;j=(j+1)%N){
                if(B.charAt(j)=='1'){
                    left = (j+N -i)%N;
                    break;
                }
            }
            int right=N;
            for(int j=i;j!=i+1;j=(j-1+N)%N){
                if(B.charAt(j)=='1'){
                    right = (i+N-j)%N;
                    break;
                }
            }
            range[i] = new Pair(right, left);
        }

        int ans = Integer.MAX_VALUE;


        //????
        for(int i=0;i<N;++i){
            int value = i;
            List<Pair> list = new ArrayList<>();
            for(int j=0;j<N;++j){
                if(A.charAt((j-i+N)%N)!=B.charAt(j)){
                    list.add(range[(j-i+N)%N]);
                }
            }
            value += list.size();
            list.sort((a,b) -> 10000*(a.first - b.first) + a.second - b.second);
            int maxValue = Integer.MAX_VALUE;
            int rightmax = 0;
            for(int j=list.size()-1;j>=0;--j){
                maxValue = Math.min(maxValue, list.get(j).first*2 + rightmax*2);
                rightmax = Math.max(rightmax, list.get(j).second);
            }
            maxValue = Math.min(maxValue, rightmax*2);

            value += maxValue;
            ans = Math.min(ans, value);
            //???????
            for(int j=0;j<N;++j){
                range[j].second =Math.max(0, range[j].second -1);
            }
//            A = A.charAt(N-1) + A.substring(0,N-1);
        }

        for(int i=0;i<N;++i){
            int left=N;
            for(int j=(i+1)%N;j!=i;j=(j+1)%N){
                if(B.charAt(j)=='1'){
                    left = (j+N -i)%N;
                    break;
                }
            }
            int right=N;
            for(int j=i;j!=i+1;j=(j-1+N)%N){
                if(B.charAt(j)=='1'){
                    right = (i+N-j)%N;
                    break;
                }
            }
            range[i] = new Pair(right, left);
        }

        //????
        for(int i=0;i<N;++i){
            int value = i;
            List<Pair> list = new ArrayList<>();
            for(int j=0;j<N;++j){
                if(A.charAt((j+i)%N)!=B.charAt(j)){
                    list.add(range[(j+i)%N]);
                }
            }
            value += list.size();
            list.sort((a,b) -> 10000*(a.second - b.second) + a.first - b.first);
            int maxValue = Integer.MAX_VALUE;
            int leftmax = 0;
            for(int j=list.size()-1;j>=0;--j){
                maxValue = Math.min(maxValue, list.get(j).second*2 + leftmax*2);
                leftmax = Math.max(leftmax, list.get(j).first);
            }
            maxValue = Math.min(maxValue, leftmax*2);

            value += maxValue;
            ans = Math.min(ans, value);
            //???????
            for(int j=0;j<N;++j){
                range[j].first =Math.max(0, range[j].first -1);
            }
//            System.out.println(value);
//            A = A.substring(1,N) + A.charAt(0);
        }


        System.out.println(ans);
    }
}