import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		char[][] f=new char[10][10];
		UF uf=new UF(100);
		for(int i=0;i<10;++i){
			s.next().getChars(0,10,f[i],0);
		}
		for(int i=0;i<10;++i){
			for(int j=0;j<10;++j){
				if(f[i][j]=='o'){
					if(inBound(i-1,j)&&f[i-1][j]=='o')uf.connect((i-1)*10+j,i*10+j);
					if(inBound(i,j-1)&&f[i][j-1]=='o')uf.connect(i*10+(j-1),i*10+j);
				}
			}
		}


		BitSet b=new BitSet(),c=new BitSet();
		for(int i=0;i<10;++i)
			for(int j=0;j<10;++j)
				if(f[i][j]=='o')
					b.set(uf.root(i*10+j));

		System.err.println(b);

		boolean r=b.cardinality()<=4
				&&IntStream.range(0,100).anyMatch(i->{
					c.clear();
					for(int d=0;d<4;++d) {
						int y=i/10+dy[d];
						int x=i%10+dx[d];
						if(inBound(y,x)&&f[y][x]=='o')
							c.set(uf.root(y*10+x));
					}
					return c.equals(b);
				});
		System.out.println(r?"YES":"NO");
	}

	static boolean inBound(int y,int x){
		return 0<=y&&y<10&&0<=x&&x<10;
	}

	static int[] dx={0,1,0,-1},dy={1,0,-1,0};
}

class UF{
	public int[] uni;
	public UF(int size){
		Arrays.fill(uni=new int[size],-1);
	}
	public int root(int t){
		return uni[t]<0?t:(uni[t]=root(uni[t]));
	}
	public boolean connect(int p,int c){
		p=root(p);
		c=root(c);
		if(p==c)
			return false;
		if(uni[p]>uni[c]){
			int buf=c;
			c=p;
			p=buf;
		}
		uni[p]+=uni[c];
		uni[c]=p;
		return true;
	}
	public boolean isConnected(int a,int b){
		return root(a)==root(b);
	}
	public int groupSize(int t){
		return -uni[root(t)];
	}
}