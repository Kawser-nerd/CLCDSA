// Google Code Jam 2017, Qualification - problem D
// "Fashion Show"
// Andras Eles, Veszprem, Hungary, 2017.04.08.
#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
	int N;
	vector<bool> v;
public:
	Matrix (int N): N(N), v(N*N){ for (int i=0;i<N*N;i++) v[i] = false;}
	bool get (int r, int c) { return v[N*r+c]; }
	void add (int r, int c) { v[N*r+c] = true; }
	void addV (int r, int c)
	{
		for (int i=0;i<N;i++)
		{
			add(r,i);
			add(i,c);
		}
	}
	void addD (int r, int c)
	{
		for (int j=0;j<N;j++)
		{
			int calt = r + c - j;
			if (0 <= calt && calt < N)
			{
				add(j,calt);
			}
		}
		for (int j=0;j<N;j++)
		{
			int ralt = r - c + j;
			if (0 <= ralt && ralt < N)
			{
				add(ralt,j);
			}
		}
	}
};

void solveProblem (void)
{
	int N, M;
	cin >> N >> M;
	Matrix v(N), d(N), vorig(N), dorig(N), vfinal(N), dfinal(N);
	int points = 0;
	for (int i=0;i<M;i++)
	{
		char type;
		int R, C;
		cin >> type >> R >> C;
		R--;
		C--;
		if (type == 'x' || type == 'o')
		{
			points++;
			v.addV(R,C);
			vorig.add(R,C);
		}
		if (type == '+' || type == 'o')
		{
			points++;
			d.addD(R,C);
			dorig.add(R,C);
		}
	}
	vfinal = vorig;
	dfinal = dorig;
	// adding X models
	for (int r=0;r<N;r++)
	{
		for (int c=0;c<N;c++)
		{
			if (!v.get(r,c))
			{
				v.addV(r,c);
				vfinal.add(r,c);
				points++;
			}
		}
	}
	// adding + models
	{
		int xA, xB;
		for (xA=0,xB=N-1;xA<=xB;xA++,xB--)
		{
			if (!d.get(xA,xA))
			{
				d.addD(xA,xA);
				dfinal.add(xA,xA);
				points++;
			}
			if (!d.get(xA,xB))
			{
				d.addD(xA,xB);
				dfinal.add(xA,xB);
				points++;
			}
			if (!d.get(xB,xA))
			{
				d.addD(xB,xA);
				dfinal.add(xB,xA);
				points++;
			}
			if (!d.get(xB,xB))
			{
				d.addD(xB,xB);
				dfinal.add(xB,xB);
				points++;
			}
			for (int y=xA+1;y<xB;y++)
			{
				int z = N - 1 - y;
				int r1 = y, c1 = xA;
				int r2 = xA, c2 = y;
				int r3 = z, c3 = xB;
				int r4 = xB, c4 = z;
				bool w1 = d.get(r1,c1);
				bool w2 = d.get(r2,c2);
				bool w3 = d.get(r3,c3);
				bool w4 = d.get(r4,c4);
				if (!w1 && !w3)
				{
					d.addD(r1,c1);
					dfinal.add(r1,c1);
					points++;
					d.addD(r3,c3);
					dfinal.add(r3,c3);
					points++;
				}
				else if (!w2 && !w4)
				{
					d.addD(r2,c2);
					dfinal.add(r2,c2);
					points++;
					d.addD(r4,c4);
					dfinal.add(r4,c4);
					points++;
				}
				else if (!w1)
				{
					d.addD(r1,c1);
					dfinal.add(r1,c1);
					points++;
				}
				else if (!w2)
				{
					d.addD(r2,c2);
					dfinal.add(r2,c2);
					points++;
				}
				else if (!w3)
				{
					d.addD(r3,c3);
					dfinal.add(r3,c3);
					points++;
				}
				else if (!w4)
				{
					d.addD(r4,c4);
					dfinal.add(r4,c4);
					points++;
				}
			}
		}
	}
	cout << points << " " << flush;
	{
		int chmod = 0;
		for (int r=0;r<N;r++)
		{
			for (int c=0;c<N;c++)
			{
				if (vorig.get(r,c) != vfinal.get(r,c) || dorig.get(r,c) != dfinal.get(r,c))
				{
					chmod++;
				}
			}
		}
		cout << chmod << endl;
	}
	for (int r=0;r<N;r++)
	{
		for (int c=0;c<N;c++)
		{
			if (vorig.get(r,c) != vfinal.get(r,c) || dorig.get(r,c) != dfinal.get(r,c))
			{
				if (vfinal.get(r,c) && !dfinal.get(r,c))
				{
					cout << 'x' << " " << (r+1) << " " << (c+1) << endl;
				}
				if (!vfinal.get(r,c) && dfinal.get(r,c))
				{
					cout << '+' << " " << (r+1) << " " << (c+1) << endl;
				}
				if (vfinal.get(r,c) && dfinal.get(r,c))
				{
					cout << 'o' << " " << (r+1) << " " << (c+1) << endl;
				}
			}
		}
	}
}

int main (int argc, char** argv)
{
	int T;
	cin >> T;
	for (int t=1;t<=T;t++)
	{
		cout << "Case #" << t << ": " << flush;
		solveProblem();
	}
	return 0;
}
