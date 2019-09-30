import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static class Fast {
        BufferedReader br;
        StringTokenizer st;

        public Fast() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main(String args[]) throws Exception {
        Fast in = new Fast();
        String t="";
        String str=in.nextLine();
        String arr[]=str.split("eraser");
        StringBuilder sb=new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]);
        }
        if(sb.length()==0){
            System.out.println("YES");
            return;
        }
        String arr1[]=sb.toString().split("erase");
        StringBuilder sb2=new StringBuilder();
        for (int i = 0; i < arr1.length; i++) {
            sb2.append(arr1[i]);
        }
        if(sb2.length()==0){
            System.out.println("YES");
            return;
        }
        String arr2[]=sb2.toString().split("dreamer");
        StringBuilder sb3=new StringBuilder();
        for (int i = 0; i < arr2.length; i++) {
            sb3.append(arr2[i]);
        }
        if(sb3.length()==0){
            System.out.println("YES");
            return;
        }
        String arr3[]=sb3.toString().split("dream");
        StringBuilder sb4=new StringBuilder();
        for (int i = 0; i < arr3.length; i++) {
            sb4.append(arr3[i]);
        }
        if(sb4.length()==0){
            System.out.println("YES");
            return;
        }else{
            System.out.println("NO");
        }

    }
}