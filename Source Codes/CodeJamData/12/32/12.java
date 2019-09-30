package gcjr1pb;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Gcjr1pb {
    public static void main(String[] args) {
        //variables
        Integer T=0;
        ArrayList<Double> D=new ArrayList<Double>();
        ArrayList<Integer> N=new ArrayList<Integer>();
        ArrayList<Integer> A=new ArrayList<Integer>();
        ArrayList<ArrayList<Double>> t=new ArrayList<ArrayList<Double>>();
        ArrayList<ArrayList<Double>> x=new ArrayList<ArrayList<Double>>();
        ArrayList<ArrayList<Double>> a=new ArrayList<ArrayList<Double>>();
        ArrayList<ArrayList<Double>> tmin=new ArrayList<ArrayList<Double>>();
        //Leo
        File archin=new File(args[0]);
        FileReader in=null;
        BufferedReader bin=null;
        try{
            in=new FileReader(archin);
            bin=new BufferedReader(in);
            T=Integer.parseInt(bin.readLine());
            for(int i=0;i<T;i++){
                StringTokenizer st=new StringTokenizer(bin.readLine());
                D.add(Double.parseDouble(st.nextToken()));
                N.add(Integer.parseInt(st.nextToken()));
                A.add(Integer.parseInt(st.nextToken()));
                t.add(new ArrayList<Double>());
                x.add(new ArrayList<Double>());
                a.add(new ArrayList<Double>());
                for(int j=0;j<N.get(i);j++){
                    st=new StringTokenizer(bin.readLine());
                    t.get(i).add(Double.parseDouble(st.nextToken()));
                    x.get(i).add(Double.parseDouble(st.nextToken()));
                }
                st=new StringTokenizer(bin.readLine());
                for(int j=0;j<A.get(i);j++){
                    a.get(i).add(Double.parseDouble(st.nextToken()));
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
            tmin.add(new ArrayList<Double>());
            for(int j=0;j<A.get(i);j++){
                tmin.get(i).add(Math.sqrt(2.0*D.get(i)/a.get(i).get(j)));
                int k;
                for(k=0;(k<N.get(i))&&(x.get(i).get(k)<=D.get(i));k++){
                    Double temp=new Double(t.get(i).get(k)-Math.sqrt(2.0*x.get(i).get(k)/a.get(i).get(j))+Math.sqrt(2.0*D.get(i)/a.get(i).get(j)));
                    if(temp>tmin.get(i).get(j)){
                        tmin.get(i).set(j,temp);
                    }
                }
                if(k<N.get(i)){
                    Double temp=null;
                    if(k>0){
                        temp=new Double((t.get(i).get(k)-t.get(i).get(k-1))/(x.get(i).get(k)-x.get(i).get(k-1))*(D.get(i)-x.get(i).get(k-1))+t.get(i).get(k-1));
                    }else{
                        temp=new Double(t.get(i).get(k)/x.get(i).get(k)*D.get(i));
                    }
                    if(temp>tmin.get(i).get(j)){
                        tmin.get(i).set(j,temp);
                    }
                }
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
                bout.write("Case #"+(i+1)+":");
                for(int j=0;j<A.get(i);j++){
                    bout.newLine();
                    bout.write(tmin.get(i).get(j).toString());
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
}