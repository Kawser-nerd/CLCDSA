package qualifiers;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class WaterSheds 
{
	private int[] dx;
	private int[] dy;
	private int[][] map;
	private int[][][] labels;
	private int H;
	private int W;
	private int[] drain(int row,int col)
	{
		if(labels[row][col][0]!=-1 && labels[row][col][1]!=-1)
			return labels[row][col];
		int low=Integer.MAX_VALUE;
		int[] ret=new int[2];
		for(int i=0;i<dx.length;++i)
		{
			int nr=row+dx[i];
			int nc=col+dy[i];
			if(0<=nr && nr<H && 0<=nc && nc<W && map[row][col]>map[nr][nc] && map[nr][nc]<low)
			{
				low=map[nr][nc];
				ret[0]=nr;
				ret[1]=nc;
			}
		}
		if(low==Integer.MAX_VALUE)
		{
			ret[0]=row;
			ret[1]=col;
		}
		else
			ret=drain(ret[0],ret[1]);
		labels[row][col][0]=ret[0];
		labels[row][col][1]=ret[1];
		return ret;
	}
	
	public char[][] categorizeBasin(int[][] map)
	{
		this.dx=new int[]{-1,0,0,1};
		this.dy=new int[]{0,-1,1,0};
		this.H=map.length;
		this.W=map[0].length;
		this.map=map;
		this.labels=new int[H][W][2];
		for(int i=0;i<H;++i)
		{
			for(int j=0;j<W;++j)
			{
				labels[i][j][0]=-1;
				labels[i][j][1]=-1;
			}
		}
		for(int i=0;i<H;++i)
		{
			for(int j=0;j<W;++j)
			{
				if(labels[i][j][0]==-1 && labels[i][j][1]==-1)
					drain(i,j);
			}
		}
		char alpha='a';
		char[][] ret=new char[H][W];
		for(int i=0;i<H;++i)
			Arrays.fill(ret[i],(char)0);
		for(int i=0;i<H;++i)
		{
			for(int j=0;j<W;++j)
			{
				 if(ret[i][j]==0)
				 {
					 ret[i][j]=alpha;
					 for(int p=0;p<H;++p)
					 {
						 for(int q=0;q<W;++q)
						 {
							 if(labels[p][q][0]==labels[i][j][0] && labels[p][q][1]==labels[i][j][1])
								 ret[p][q]=alpha;
						 }
					 }
					 alpha=(char)(alpha+1);
				 }
			}
		}
		return ret;
	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception 
	{
		WaterSheds obj=new WaterSheds();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.valueOf(br.readLine());
		for(int i=1;i<=N;++i)
		{
			String[] t=br.readLine().split(" ");
			int H=Integer.valueOf(t[0]);
			int W=Integer.valueOf(t[1]);
			int[][] inp=new int[H][W];
			for(int j=0;j<H;++j)
			{
				String[] temp=br.readLine().split(" ");
				for(int k=0;k<W;++k)
					inp[j][k]=Integer.valueOf(temp[k]);
			}
			char[][] ret=obj.categorizeBasin(inp);
			System.out.println("Case #"+i+":");
			for(int j=0;j<ret.length;++j)
			{
				String out="";
				for(int k=0;k<ret[j].length;++k)
					out+=" "+ret[j][k];
				System.out.println(out.trim());
			}			
		}
	}
}