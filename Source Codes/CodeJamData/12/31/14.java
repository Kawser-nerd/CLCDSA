package gcjr1pa;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Gcjr1pa {
    public static void main(String[] args) {
        //variables
        Integer T=0;
        ArrayList<Integer> N=new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> M=new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<ArrayList<Integer>>> H=new ArrayList<ArrayList<ArrayList<Integer>>>();
        ArrayList<Boolean> Y=new ArrayList<Boolean>();
        //Leo
        File archin=new File(args[0]);
        FileReader in=null;
        BufferedReader bin=null;
        try{
            in=new FileReader(archin);
            bin=new BufferedReader(in);
            T=Integer.parseInt(bin.readLine());
            for(int i=0;i<T;i++){
                M.add(new ArrayList<Integer>());
                H.add(new ArrayList<ArrayList<Integer>>());
                N.add(Integer.parseInt(bin.readLine()));
                for(int j=0;j<N.get(i);j++){
                    StringTokenizer st=new StringTokenizer(bin.readLine());
                    H.get(i).add(new ArrayList<Integer>());
                    M.get(i).add(Integer.parseInt(st.nextToken()));
                    for(int k=0;k<M.get(i).get(j);k++){
                        H.get(i).get(j).add(Integer.parseInt(st.nextToken())-1);
                    }
                }
            }
        }catch(Exception ex){
        }finally{
            try{
                bin.close();
            }catch(Exception ex){
            }
            try{
                in.close();
            }catch(Exception ex){
            }
        }
        //Proceso
        for(int i=0;i<T;i++){
            Y.add(Boolean.FALSE);
            for(int j=0;!Y.get(i)&&(j<N.get(i));j++){
                ArrayList<Boolean> pase=new ArrayList<Boolean>();
                for(int k=0;k<N.get(i);k++){
                    pase.add(Boolean.FALSE);
                }
                Y.set(i,searchDiamond(pase,H.get(i),j));
            }
        }
        //Escribo
        File archout=new File("out.txt");
        FileWriter out=null;
        BufferedWriter bout=null;
        try{
            out=new FileWriter(archout);
            bout=new BufferedWriter(out);
            for(int i=0;i<T;i++){
                if(i>0){
                    bout.newLine();
                }
                bout.write("Case #"+(i+1)+": ");
                if(Y.get(i)){
                    bout.write("Yes");
                }else{
                    bout.write("No");
                }                    
            }
        }catch(Exception ex){
        }finally{
            try{
                bout.close();
            }catch(Exception ex){
            }
            try{
                out.close();
            }catch(Exception ex){
            }
        }
    }
    
    private static Boolean searchDiamond(ArrayList<Boolean> pase,ArrayList<ArrayList<Integer>> H,Integer n){
        Boolean si=Boolean.FALSE;
        if(pase.get(n)){
            si=Boolean.TRUE;
        }else{
            pase.set(n,Boolean.TRUE);
            for(int i=0;!si&&(i<H.get(n).size());i++){
                si=searchDiamond(pase,H,H.get(n).get(i));
            }
        }
        return si;
    }
}