const int maxp = 100000;
#include <pe>
static inline int Rint()
{
    struct X{ int dig[256]; X(){
    for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
    }};
    static     X fuck;int s = 1, v = 0, c;
    for (;!fuck.dig[c = getchar()];);
    if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
    for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}
/*
"C:\mingw-w64\mingw64\bin\g++.exe" "C.c" -o a.exe --std=c++11 -O3 -march=native -fopenmp
*/
typedef int64 Ct;
struct Pt
{
	Pt(Ct _x = 0, Ct _y = 0) : x(_x), y(_y){}
	Ct x, y;
  int id;
  double angle;
};
inline Pt operator - (const Pt& a, const Pt& b) 
{
	return Pt(a.x-b.x, a.y-b.y);
}
inline Pt operator + (const Pt& a, const Pt& b)
{
	return Pt(a.x+b.x, a.y+b.y);
}
inline Ct cross(const Pt& a, const Pt& b)
{
	return a.x * b.y - a.y * b.x;
}
inline Ct cross(const Pt& a, const Pt& b, const Pt& c)
{
	return cross(b-a, c-a);
}
struct covex_hull
{
	int cal(Pt* input, int size, Pt* output)
	{
		sort(input, input+size, cmp_y_x);
		if (size <= 2)
		{
			copy(input, input+size, output);
			return size;
		}
		output[0] = input[0], output[1] = input[1];
		int top = 1;
		for (int i = 2; i < size; ++i)
		{
			while (top && cross(output[top-1], output[top], input[i]) < 0)
			--top;
			output[++top] = input[i];
		}
		int len = top;
		output[++top] = input[size-2];
		for (int i = size - 3; i >= 0; --i) 
		{
			while (top != len && cross(output[top-1], output[top], input[i]) < 0)
			--top;
			output[++top] = input[i];
		}
		return top;
	}
	static int cmp_y_x(const Pt& a, const Pt& b)
	{
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	}
};

int cmp(const Pt& a, const Pt& b)
{
  return a.angle < b.angle;
}

Pt data[3005];
Pt data1[3005+3005];
int ans[3005];
int main()
{
  set_process_priority(PRIORITY_IDLE);
  covex_hull cv;
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    dbg(id);
    const int n = Rint();
    for (int i = 0; i < n; ++i)
    {
      data[i].x = Rint();
      data[i].y = Rint();
      data[i].id = i;
      //if (id == 80)
      //cerr << data[i].x << " " << data[i].y << endl;
    }
    fill(ans, ans+n, 2000000000);
    if (n > 2)
    {
      for (int i = 0; i < n; ++i)
      {
        Pt a = data[i];
        int top = 0;
        for (int j = 0; j < n; ++j)
        if (j != i)
        {
          data1[top].x = data[j].x - a.x;
          data1[top].y = data[j].y - a.y;
          data1[top].id = j;
          data1[top].angle = atan2(data1[top].y, data1[top].x);
          ++top;
        }
        sort(data1, data1+top, cmp);
        copy(data1, data1+top, data1+top);
        int s = 0;
        int u = 0, v = 0;
        for (; s < top; ++s)
        {
          if (u < s) u = s;
          while (u + 1 != s + top && cross(data1[s], data1[u+1]) == 0) ++u;
          if (u > v) v = u;
          while (v + 1 != s + top && cross(data1[s], data1[v+1]) > 0) ++v;
          int t = v - u;
          if (t < ans[i]) ans[i] = t;
        }
      }
    }
    else
    {
      ans[0] = ans[1] = 0;
    }
    printf("Case #%d:\n", id);
    for (int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  }
  return 0;
}