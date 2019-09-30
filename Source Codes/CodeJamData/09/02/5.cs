using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class B {
	int n, m;
	int[,] h;
	int[,] nx, ny;
	char[,] color;
	public B() {
		string[] s=Console.ReadLine().Split();
		n=int.Parse(s[0]); m=int.Parse(s[1]);
		h=new int[n, m];
		for (int i=0; i<n; ++i) {
			s=Console.ReadLine().Split();
			for (int j=0; j<m; ++j) h[i, j]=int.Parse(s[j]);
		}
	}
	int[] dx= { -1, 0, 0, 1 }, dy= { 0, -1, 1, 0 };
	void dfs(int x, int y, char c) {
		color[x,y]=c;
		if (color[nx[x,y],ny[x,y]]==0) dfs(nx[x, y], ny[x, y], c);
		for (int i=0; i<4; ++i) {
			int x2=x+dx[i], y2=y+dy[i];
			if (x2>=0&&x2<n&&y2>=0&&y2<m&&nx[x2, y2]==x&&ny[x2, y2]==y&&color[x2, y2]==0)
				dfs(x2, y2, c);
		}
	}
	public string main() {
		nx=new int[n, m]; ny=new int[n, m];
		for (int x=0; x<n; ++x)
			for (int y=0; y<m; ++y) {
				nx[x,y]=x; ny[x,y]=y;
				for (int i=0; i<4; ++i) {
					int x2=x+dx[i], y2=y+dy[i];
					if (x2>=0&&x2<n&&y2>=0&&y2<m&&h[x2, y2]<h[nx[x, y], ny[x, y]]) {
						nx[x, y]=x2;
						ny[x, y]=y2;
					}
				}
			}
		color=new char[n, m];
		char cur='a';
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (color[i, j]==0)
					dfs(i, j, cur++);
		string ans="";
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				ans+=(j==0?"\n":" ");
				ans+=color[i, j];
			}
		}
		return ans;
	}
}