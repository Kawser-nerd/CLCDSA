import java.io.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int[] rb = {0,0};
        for (String s:str.split("")){
            if (s.equals("0")){
                rb[0]++;
            } else {
                rb[1]++;
            }
        }
        System.out.println(Math.min(rb[0],rb[1])*2);
    }
}