import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class ab {

  
     public static void main(String args []) throws Exception
    {
    BufferedReader f=new BufferedReader(new FileReader("A.in"));
    BufferedWriter w=new BufferedWriter(new FileWriter("A.txt"));

    int t=Integer.parseInt(f.readLine());
StringTokenizer g;
int l,p,c;

for(int d=1;d<=t;d++)
{g=new StringTokenizer(f.readLine());
l=Integer.parseInt(g.nextToken());
p=Integer.parseInt(g.nextToken());
c=Integer.parseInt(g.nextToken());
int ans=(int)((Math.ceil(Math.log(Math.ceil(Math.log(p/(double)l)/Math.log(c))))/Math.log(2)));
w.write("Case #"+d+": "+""+ans+"\n");

}

    w.close();

    }

}
