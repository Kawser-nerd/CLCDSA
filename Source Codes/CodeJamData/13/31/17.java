package round1C;
import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class A{
    public static Scanner sc = new Scanner(in);
    public static Random rand=new Random();

    public static PrintWriter out;
    static{
    	try {
			out=new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\shimomire\\Dropbox\\Project\\ProgramContest\\java\\GCJ\\res.out")));
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
    }

    public void run(){
       	int t=sc.nextInt();
    	StringBuilder sb=new StringBuilder();

    	for(int i=1;i<=t;i++){
    		char[] str=sc.next().toCharArray();
    		int len=sc.nextInt();
    		boolean[] isC=new boolean[str.length];
    		for(int j=0;j<str.length;j++){
    			char c=str[j];
    			isC[j]=c=='a'|| c== 'i' || c=='u'||c=='e'||c=='o';
    		}

    		int l=0,r=0;
    		int v=0;
    		int res=0;
    		while(r<str.length){
    			if(isC[r])v=0;
				else v++;
    			if(v<len){
    				r++;
    				continue;
    			}
    			res+=str.length-r;
    			l++;
    			v=0;
    			r=l;
    		}
    		sb.append("Case #"+i+": "+res+"\n");
    	}

    	ln(sb);
    	out.close();
    }

    public static void main(String[] _) {
        new A().run();
    }

    public int[] nextIntArray(int n){
        int[] res=new int[n];
        for(int i=0;i<n;i++){
            res[i]=sc.nextInt();
        }
        return res;
    }
    public static void pr(Object o) {
    	out.print(o);
    }
    public static void ln(Object o) {
        out.println(o);
    }
    public static void ln() {
    	out.println();
    }

}