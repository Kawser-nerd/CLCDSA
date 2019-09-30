import java.util.*;
 
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        char[] qc = sc.next().toCharArray();
        int data[] = new int[n+1];
        for(int i = 1;i<n;i++){
            data[i] = data[i-1];
            if(qc[i] == 'C'){
                if(qc[i-1] == 'A'){
                    data[i] = data[i-1] + 1;
                }
            }
        }
        int l[] = new int[q];
        int r[] = new int[q];
        for(int i = 0;i<q;i++){
            l[i] = Integer.parseInt(sc.next());
            r[i] = Integer.parseInt(sc.next());
        }
        for(int i = 0;i<q;i++){
            System.out.println(data[r[i]-1] - data[l[i]-1]);
        }
    }
}