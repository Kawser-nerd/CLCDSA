import java.util.Scanner;
import java.util.TreeMap;

class Main {
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
       int n = scan.nextInt();
       int[] ar = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = scan.nextInt();
        }

        TreeMap<Integer,Integer> ax = new TreeMap<>();

        for (int i = 0; i < ar.length; i++) {
            Integer x = ax.get(ar[i]);
            ax.put(ar[i],x==null?1:x+1);
        }

        int result = 0;
       while (!ax.isEmpty()){
            Integer cur = ax.lastKey();
            if(ax.get(cur) == 1){
                ax.remove(cur);
            }else{
                ax.put(cur,ax.get(cur)-1);
            }

            int pos = 1;
            while (pos <= cur) pos*=2;
            int need = pos-cur;
            Integer got = ax.get(need);
            if(got == null){
                continue;
            }
            result++;
            if(got == 1){
                ax.remove(need);
            }else{
                ax.put(need,got-1);
            }
       }

        System.out.println(result);
    }
}