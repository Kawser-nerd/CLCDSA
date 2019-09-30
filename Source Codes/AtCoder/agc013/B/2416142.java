import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] num = new int[n];
        ArrayList<Integer>[] p = new ArrayList[n];
        for(int i=0; i<n; i++){
            p[i] = new ArrayList<Integer>();
        }
        for(int i=0; i<m; i++){
            int tmp1 = sc.nextInt()-1;
            int tmp2 = sc.nextInt()-1;
            num[tmp1]++;
            num[tmp2]++;
            p[tmp1].add(tmp2);
            p[tmp2].add(tmp1);            
        }
        sc.close();
        //System.out.println("input end");

        int e1 = 0;
        int e2 = p[e1].get(0);
        ArrayDeque<Integer> path = new ArrayDeque<>();
        path.addFirst(e1);
        path.addLast(e2);
        boolean[] use = new boolean[n];
        use[e1] = true;
        use[e2] = true;

        //int count = 0;
        out: while(true){
            int tmp = 0;
            for(int i=0; i<p[e1].size(); i++){
                int mtmp = p[e1].get(i);
                if(use[mtmp]){
                    tmp++;
                }else{
                    e1 = mtmp;
                    path.addFirst(e1);
                    use[e1] = true;
                    continue out;
                }
            }
            for(int i=0; i<p[e2].size(); i++){
                int mtmp = p[e2].get(i);
                if(use[mtmp]){
                    tmp++;
                }else{
                    e2 = mtmp;
                    path.addLast(e2);
                    use[e2] = true;
                    break;
                }
            }
            if(tmp == p[e1].size() + p[e2].size()) break;


            // count++;
            // if(count % 100 == 0){
            //     System.out.println(e1 + " " + e2 + " " + tmp + p[e1].size() + p[e2].size() + " " + tmp);
            // }
        }

        int tmp = path.size();
        System.out.println(tmp);
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<tmp; i++){
            sb.append(path.poll()+1);
            sb.append(" ");
            if(tmp / 1000 == 0){
                System.out.print(sb);
                sb = new StringBuilder();
            }
        }
        System.out.println(sb);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.