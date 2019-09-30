import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        int N = scan.nextInt();
        int[] a = IntStream.range(0,N).map(i -> scan.nextInt()).toArray();
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<N;++i){
            if(!map.containsKey(a[i])){
                map.put(a[i],0);
            }
            map.put(a[i],map.get(a[i])+1);
        }

        int ans = 0;
        for(Map.Entry<Integer,Integer> entry : map.entrySet()){
            if(entry.getKey() > entry.getValue()){
                ans+=entry.getValue();
            }else{
                ans+=entry.getValue()-entry.getKey();
            }
        }
        System.out.println(ans);

    }
}