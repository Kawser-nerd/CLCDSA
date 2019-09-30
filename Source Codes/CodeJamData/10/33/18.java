import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class cd {

    public static boolean isprop(int [][] t,int i,int j,int s)
    {

    int z=t[i][j];
    for(int k=i;k<=i+s-1;k++)
    {
    for(int p=j;p<=j+s-1;p++)
    {
	if(t[k][p]==-1){return false;}
    if(t[k][p]!=((z+(k-i)+(p-j))%2)){return false;}
    }
    }


    return true;
    }

    public static void upd(char d,int [][]t,int i,int j)
    {
    if(d=='A')	   {t[i][j]=1;t[i][j+1]=0;t[i][j+2]=1;t[i][j+3]=0;}
    else if(d=='B'){t[i][j]=1;t[i][j+1]=0;t[i][j+2]=1;t[i][j+3]=1;}
    else if(d=='C'){t[i][j]=1;t[i][j+1]=1;t[i][j+2]=0;t[i][j+3]=0;}
    else if(d=='D'){t[i][j]=1;t[i][j+1]=1;t[i][j+2]=0;t[i][j+3]=1;}
    else if(d=='E'){t[i][j]=1;t[i][j+1]=1;t[i][j+2]=1;t[i][j+3]=0;}
    else if(d=='F'){t[i][j]=1;t[i][j+1]=1;t[i][j+2]=1;t[i][j+3]=1;}
    else if(d=='0'){t[i][j]=0;t[i][j+1]=0;t[i][j+2]=0;t[i][j+3]=0;}
    else if(d=='1'){t[i][j]=0;t[i][j+1]=0;t[i][j+2]=0;t[i][j+3]=1;}
    else if(d=='2'){t[i][j]=0;t[i][j+1]=0;t[i][j+2]=1;t[i][j+3]=0;}
    else if(d=='3'){t[i][j]=0;t[i][j+1]=0;t[i][j+2]=1;t[i][j+3]=1;}
    else if(d=='4'){t[i][j]=0;t[i][j+1]=1;t[i][j+2]=0;t[i][j+3]=0;}
    else if(d=='5'){t[i][j]=0;t[i][j+1]=1;t[i][j+2]=0;t[i][j+3]=1;}
    else if(d=='6'){t[i][j]=0;t[i][j+1]=1;t[i][j+2]=1;t[i][j+3]=0;}
    else if(d=='7'){t[i][j]=0;t[i][j+1]=1;t[i][j+2]=1;t[i][j+3]=1;}
    else if(d=='8'){t[i][j]=1;t[i][j+1]=0;t[i][j+2]=0;t[i][j+3]=0;}
    else	   {t[i][j]=1;t[i][j+1]=0;t[i][j+2]=0;t[i][j+3]=1;}




    }
   public static void mark(int [][] t,int i,int j,int s)
   {

    for(int k=i;k<=i+s-1;k++)
    {
    for(int p=j;p<=j+s-1;p++)
    {
    t[k][p]=-1;
    }
    }

   }

 public static void main(String args []) throws Exception
    {
    BufferedReader f=new BufferedReader(new FileReader("A.in"));
    BufferedWriter w=new BufferedWriter(new FileWriter("A.txt"));

    int c=Integer.parseInt(f.readLine());
StringTokenizer g;
int n,m;
int [][] t;

int [] jl;
for(int p=1;p<=c;p++)
{g=new StringTokenizer(f.readLine());
m=Integer.parseInt(g.nextToken());
n=Integer.parseInt(g.nextToken());
t=new int[m][n];


for(int i=0;i<m;i++)
{
String y=f.readLine();
int cv=0;
for(int j=0;j<y.length();j++)
{
 {upd(y.charAt(j),t,i,cv);
 cv=cv+4;
 }
}

}
jl=new int[Math.min(m,n)+1];
boolean gm;
for(int k=Math.min(n,m);k>=1;k--)//size
{gm=false;

for(int i=0;i<=m-k;i++)
{
for(int j=0;j<=n-k;j++)
{
if(isprop(t,i,j,k))
{gm=true;
mark(t,i,j,k);
jl[k]++;
}

}

}

 if(gm){k++;}

}
int total=0;
for(int i=1;i<=Math.min(n,m);i++)
{
if(jl[i]!=0){total++;}
}

w.write("Case #"+p+": "+""+total+"\n");
for(int i=Math.min(m, n);i>=1;i--)
{
if(jl[i]!=0){w.write(i+" "+jl[i]+"\n");
}
}

}

    w.close();

    }

}
