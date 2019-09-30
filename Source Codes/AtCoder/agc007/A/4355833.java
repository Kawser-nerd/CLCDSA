import java.io.InputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

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
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            MyScanner sc = new MyScanner();
            int h = sc.nextInt(), w = sc.nextInt();
            int sum = 0;
            for(int i = 0; i < h; ++i){
                char[] a = br.readLine().toCharArray();
                for(int j = 0; j < w; ++j){
                    if(a[j] == '#'){
                        ++sum;
                    }
                }
            }
            if(sum == h + w - 1){
                System.out.println("Possible");
            }else{
                System.out.println("Impossible");
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}