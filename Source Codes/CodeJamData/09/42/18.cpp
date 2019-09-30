#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

char a[60][60];
int d[60][60][60][60];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int i,j,k,l,t,best,o,left,right,p,q,tmpx,tmpy,z,m,n,f;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d%d%d",&m,&n,&f);
        for (i=0;i<m;i++)
            scanf("%s",a[i]);
        memset(d,-1,sizeof(d));
        d[0][0][0][0]=0;
        for (i=0;i<m-1;i++)
        {
            for (j=0;j<n;j++)
            {
                if (d[i][j][0][0]!=-1)
                {
                    left=j;right=j;
                    while ((left-1>=0)&&(a[i+1][left-1]=='#')&&(a[i][left-1]=='.'))
                    {
                        left--;
                    }

                    while ((right+1<n)&&(a[i+1][right+1]=='#')&&(a[i][right+1]=='.'))
                    {
                        right++;
                    }
                    z=d[i][j][0][0];
                    if ((left-1>=0)&&(a[i][left-1]=='.'))
                    {
                        tmpx=i+1;
                        tmpy=left-1;
                        while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                        {
                            tmpx++;
                        }
                        if (tmpx-i<=f)
                        {
                            if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                d[tmpx][tmpy][0][0]=z;
                        }
                    }
                    if ((right+1<n)&&(a[i][right+1]=='.'))
                    {
                        tmpx=i+1;
                        tmpy=right+1;
                        while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                        {
                            tmpx++;
                        }
                        if (tmpx-i<=f)
                        {
                            if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                d[tmpx][tmpy][0][0]=z;
                        }
                    }
                    for (p=left;p<=right;p++)
                        for (q=1;p+q-1<=right;q++)
                        {
                            z=d[i][j][0][0]+q;
                            if ((p==left)&&(q==right-left+1)) continue;
                            if (p!=left)
                            {
                                tmpx=i+1;
                                tmpy=p;
                                while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                                {
                                    tmpx++;
                                }
                                if (tmpx-i<=f)
                                {
                                    if (tmpx==i+1)
                                    {
                                        if ((d[tmpx][tmpy][p][q]==-1)||(z<d[tmpx][tmpy][p][q]))
                                            d[tmpx][tmpy][p][q]=z;
                                    }
                                    else
                                    {
                                        if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                            d[tmpx][tmpy][0][0]=z;
                                    }
                                }
                            }
                            if (p+q-1!=right)
                            {
                                tmpx=i+1;
                                tmpy=p+q-1;
                                while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                                {
                                    tmpx++;
                                }
                                if (tmpx-i<=f)
                                {
                                    if (tmpx==i+1)
                                    {
                                        if ((d[tmpx][tmpy][p][q]==-1)||(z<d[tmpx][tmpy][p][q]))
                                            d[tmpx][tmpy][p][q]=z;
                                    }
                                    else
                                    {
                                        if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                            d[tmpx][tmpy][0][0]=z;
                                    }
                                }
                            }
                        }

                }
                for (k=0;k<n;k++)
                    for (o=1;k+o-1<n;o++)
                    {
                        if (a[i][k+o-1]!='#') break;
                        if (d[i][j][k][o]!=-1)
                        {
                            left=j;right=j;
                            while ((left-1>=0)&&(a[i+1][left-1]=='#')&&((a[i][left-1]=='.')||((left-1-k<o)&&(left-1>=k))))
                            {
                                left--;
                            }

                            while ((right+1<n)&&(a[i+1][right+1]=='#')&&((a[i][right+1]=='.')||((right+1-k<o)&&(right+1>=k))))
                            {
                                right++;
                            }
                            z=d[i][j][k][o];
                            if ((left-1>=0)&&((a[i][left-1]=='.')||((left-1-k<o)&&(left-1>=k))))
                            {
                                tmpx=i+1;
                                tmpy=left-1;
                                while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                                {
                                    tmpx++;
                                }
                                if (tmpx-i<=f)
                                {
                                    if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                        d[tmpx][tmpy][0][0]=z;
                                }
                            }
                            if ((right+1<n)&&((a[i][right+1]=='.')||((right+1-k<o)&&(right+1>=k))))
                            {
                                tmpx=i+1;
                                tmpy=right+1;
                                while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                                {
                                    tmpx++;
                                }
                                if (tmpx-i<=f)
                                {
                                    if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                        d[tmpx][tmpy][0][0]=z;
                                }
                            }
                            for (p=left;p<=right;p++)
                                for (q=1;p+q-1<=right;q++)
                                {
                                    z=d[i][j][k][o]+q;
                                    if ((p==left)&&(q==right-left+1)) continue;
                                    if (p!=left)
                                    {
                                        tmpx=i+1;
                                        tmpy=p;
                                        while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                                        {
                                            tmpx++;
                                        }
                                        if (tmpx-i<=f)
                                        {
                                            if (tmpx==i+1)
                                            {
                                                if ((d[tmpx][tmpy][p][q]==-1)||(z<d[tmpx][tmpy][p][q]))
                                                    d[tmpx][tmpy][p][q]=z;
                                            }
                                            else
                                            {
                                                if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                                    d[tmpx][tmpy][0][0]=z;
                                            }
                                        }
                                    }
                                    if (p+q-1!=right)
                                    {
                                        tmpx=i+1;
                                        tmpy=p+q-1;
                                        while ((tmpx+1<m)&&(a[tmpx+1][tmpy]=='.'))
                                        {
                                            tmpx++;
                                        }
                                        if (tmpx-i<=f)
                                        {
                                            if (tmpx==i+1)
                                            {
                                                if ((d[tmpx][tmpy][p][q]==-1)||(z<d[tmpx][tmpy][p][q]))
                                                    d[tmpx][tmpy][p][q]=z;
                                            }
                                            else
                                            {
                                                if ((d[tmpx][tmpy][0][0]==-1)||(z<d[tmpx][tmpy][0][0]))
                                                    d[tmpx][tmpy][0][0]=z;
                                            }
                                        }
                                    }
                                }
                        }
                    }
            }
        }



        best=2000000000;
        for (i=0;i<n;i++)
        {
            if (d[m-1][i][0][0]!=-1)
            {
                if (d[m-1][i][0][0]<best) best=d[m-1][i][0][0];
            }
            if (d[m-1][i][i][1]!=-1)
            {
                if (d[m-1][i][i][1]<best) best=d[m-1][i][i][1];
            }
        }
        if (best==2000000000)
        {
            printf("Case #%d: No\n",l+1);
        }
        else
        {
            printf("Case #%d: Yes %d\n",l+1,best);
        }
    }
	return 0;
}

