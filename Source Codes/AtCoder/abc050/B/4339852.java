import java.io.InputStream;
import java.io.IOException;

class MyScanner{
    InputStream stream;
    public MyScanner(){
        stream = System.in;
    }
    
    public int nextInt(){
        int ret = 0;
        try{
            while(true){
                char readed = (char)stream.read();
                if(readed < '0' || readed > '9'){
                    break;
                }
                ret = ret * 10 + (readed - '0');
            }
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            return ret;
        }
    }
}

class Main {
    public static void main(String args[]) {
        MyScanner sc = new MyScanner();
        int n = sc.nextInt();
        int[] t = new int[n];
        int sum = 0;
        for(int i = 0; i < n; ++i){
            t[i] = sc.nextInt();
            sum += t[i];
        }
        int m = sc.nextInt();
        for(int i = 0; i < m; ++i){
            int p, x;
            p = sc.nextInt() - 1;
            x = sc.nextInt();
            System.out.println(sum - t[p] + x);
        }
    }
}