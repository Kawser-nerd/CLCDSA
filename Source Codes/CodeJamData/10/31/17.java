import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class apocalypse {


    public static void main(String args []) throws Exception
    {
    BufferedReader f=new BufferedReader(new FileReader("A.in"));
    BufferedWriter w=new BufferedWriter(new FileWriter("A.txt"));

    int c=Integer.parseInt(f.readLine());
StringTokenizer g;
int n;
int  t;
int [] A,B;
for(int p=1;p<=c;p++)
{
    //g=new StringTokenizer(f.readLine());
    n=Integer.parseInt(f.readLine());
    //k=Integer.parseInt(g.nextToken());
A=new int[n];
B=new int[n];
    for(int i=0;i<n;i++)
    {
g=new StringTokenizer(f.readLine());
    A[i]=Integer.parseInt(g.nextToken());
    B[i]=Integer.parseInt(g.nextToken());
    }
t=0;
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if((A[i]-A[j])*(B[i]-B[j])<0)
{t++;
}
}
}


w.write("Case #"+p+": "+""+t+"\n");

}

    w.close();

    }

}
