import java.util.*;

class Main {
    static int k,n;
    static String[] v,w;
    static boolean search(int[] array,String[] answer,int a){
        if(a<k){
            for(int i=1;i<=3;++i){
                array[a]=i;
                if(search(array,answer,a+1))
                    return true;
            }
            return false;
        }
        String[] kouho=new String[k];
        for (int i=0;i<n;++i){
            int totalLength=0;
            for(int j=0;j<v[i].length();++j){
                int t=array[v[i].charAt(j)-'1'];
                totalLength+=t;
            }
            if(totalLength!=w[i].length())return false;
        }
        for (int i=0;i<n;++i){
            int c=0;
            for(int j=0;j<v[i].length();++j){
                int u=v[i].charAt(j)-'1';
                int t=array[u];
                String cut=w[i].substring(c,c+t);
                if(kouho[u]==null)
                    kouho[u]=cut;
                else if(!kouho[u].equals(cut))
                    return false;
                c+=t;
            }
        }
        System.arraycopy(kouho,0,answer,0,k);
        return true;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        k=scan.nextInt();
        n=scan.nextInt();
        v=new String[n];
        w=new String[n];
        for (int i=0;i<n;++i){
            v[i]=scan.next();
            w[i]=scan.next();
        }
        int[] array=new int[k];
        String[] answer=new String[k];
        Arrays.fill(array,1);
        if(search(array,answer,0))
            for(String s:answer)
                System.out.println(s);
        else
            throw new RuntimeException();
    }
}